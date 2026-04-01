#ifndef LISTS_H
#define LISTS_H

#include <stddef.h> /* Required for 'size_t' var type */

/* Externally provided structure */
/**
 * struct dlistint_s - doubly linked list
 * @n: integer
 * @prev: points to the previous node
 * @next: points to the next node
 *
 * Description: doubly linked list node structure
 *
 */
typedef struct dlistint_s
{
	int n;
	struct dlistint_s *prev;
	struct dlistint_s *next;
} dlistint_t;

/* DoLiLi - Exo 00 (0-print_dlistint.c)   */
size_t print_dlistint(const dlistint_t *h);
/* DoLiLi - Exo 01 (1-dlistint_len.c)     */
size_t dlistint_len(const dlistint_t *h);
/* DoLiLi - Exo 02 (2-add_dnodeint.c)     */
dlistint_t *add_dnodeint(dlistint_t **head, const int n);
/* DoLiLi - Exo 03 (3-add_dnodeint_end.c) */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n);
/* DoLiLi - Exo 04 (4-free_dlistint.c)    */
void free_dlistint(dlistint_t *head);
/* DoLiLi - Exo 05 (5-get_dnodeint.c)    */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index);
/* DoLiLi - Exo 06 (6-sum_dlistint.c)    */
int sum_dlistint(dlistint_t *head);
/* DoLiLi - Exo 07 (7-insert_dnodeint.c)    */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n);
/* DoLiLi - Exo 08 (8-delete_dnodeint.c)    */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index);

#endif
