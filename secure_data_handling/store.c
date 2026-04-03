#include <stdlib.h>
#include <string.h>
#include "store.h"

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

static node_t *node_create(session_t *s)
{
	node_t *n = (node_t *)malloc(sizeof(*n));

	if (!n)
		return (NULL);
	n->sess = s;
	n->next = NULL;
	return (n);
}

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
