#include <stdlib.h>
#include <string.h>
#include "store.h"


/**
 * store_init - (re)Initializes a store.
 * @st: store to (re)initialize.
 * Return: pointer to created node.
 */
void store_init(store_t *st)
{
	if (st)
	{
		/* INIT means we want to start from fresh so IF there are still sessions */
		/*   we need to destroy them. Security required because technically */
		/* this function could be used by a caller without a store_destroy before. */
		if (st->head)
			store_destroy(st);
		st->head = NULL;
	}
}

/**
 * node_create - Creates a node to store a session inside a bucket.
 * @s: new session data.
 * Return: pointer to created node.
 */
static node_t *node_create(session_t *s)
{
	node_t *n = (node_t *)malloc(sizeof(*n));

	if (!n)
		return (NULL);
	n->sess = s;
	n->next = NULL;
	return (n);
}

/**
 * store_add - Gets the first session matching given id.
 * @st: store to insert new session into.
 * @s: new session data
 * Return: pointer to found session.
 */
int store_add(store_t *st, session_t *s)
{
	node_t *n, *cur;

	/* Cannot pursue, don't have all required infos. */
	if (!st || !s || !s->id)
		return (0);

	/* Grab first session from store metadata. */
	cur = st->head;
	/* First check that no existing session matches the creation request. */
	while (cur)
	{
		if (cur->sess && cur->sess->id && strcmp(cur->sess->id, s->id) == 0)
		{
			session_destroy(s); /* free(s) insufficient -> this avoids dups. */
			return (0);
		}
		cur = cur->next;
	}

	/*Reached here means no existing, allocate, affect and re-link. */
	n = node_create(s);
	if (!n)
	{
		session_destroy(s); /* free(s) insufficient -> this avoids dups. */
		return (0);
	}

	n->next = st->head;
	st->head = n;
	return (1);
}

/**
 * store_get - Gets the first session matching given id.
 * @st: store to get a session from.
 * @id: key to search by
 * Return: pointer to found session.
 */
session_t *store_get(store_t *st, const char *id)
{
	node_t *cur;

	if (!st || !id)
		return (NULL);

	cur = st->head;
	while (cur)
	{
		if (cur->sess && cur->sess->id && strcmp(cur->sess->id, id) == 0)
			return (cur->sess);
		cur = cur->next;
	}
	return (NULL);
}

/**
 * store_delete - Delete one session searched by id,
 *   optionally giving it back to caller instead.
 * @st: store to search session to delete into.
 * @id: key to search by
 * @out: if given by caller will hold found session.
 * Return: 1 if success, 0 if failure.
 */
int store_delete(store_t *st, const char *id, session_t **out)
{
	node_t *cur, *prev;

	if (!st || !id)
		return (0);

	prev = NULL;
	cur = st->head;

	/* Trys to find session which id matches the one requested for deletion */
	while (cur)
	{
		if (cur->sess && cur->sess->id && strcmp(cur->sess->id, id) == 0)
		{
			if (prev)
				prev->next = cur->next;
			else
				st->head = cur->next;
			if (out)
				*out = cur->sess;
			else
				session_destroy(cur->sess);
			free(cur);
			return (1);
		}
		prev = cur;
		cur = cur->next;
	}

	return (0);
}

/**
 * store_destroy - Fully delete and frees store content.
 * @st: store to empty entirely.
 */
void store_destroy(store_t *st)
{
	node_t *cur, *next;

	if (!st)
		return;

	cur = st->head;
	/* Prevents a risk of double free in the case where store_destroy */
	/*  is called a second time while the first is still running */
	/*  (couldn't have understood that risk without IA). */
	st->head = NULL;
	while (cur)
	{
		next = cur->next;
		/* Once further node for next cycle is "secured" we clean as usual. */
		cur->next = NULL;
		if (cur->sess) /* Actually needed to avoid risk of null dereferencing */
			session_destroy(cur->sess);
		free(cur);

		cur = next;
	}
	st->head = NULL;
}
