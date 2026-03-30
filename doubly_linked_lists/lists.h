#ifndef LISTS_H
#define LISTS_H

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

/* DoLiLi - Exo 01 (1-dlistint_len.c)     */

/* DoLiLi - Exo 02 (2-add_dnodeint.c)     */

/* DoLiLi - Exo 03 (3-add_dnodeint_end.c) */

/* DoLiLi - Exo 04 (4-free_dlistint.c)    */

/* DoLiLi - Exo 05 (5-get_dnodeint.c)    */

/* DoLiLi - Exo 06 (6-sum_dlistint.c)    */

/* DoLiLi - Exo 07 (7-insert_dnodeint.c)    */

/* DoLiLi - Exo 08 (8-delete_dnodeint.c)    */


#endif
