#ifndef LISTS_H
#define LISTS_H

#include <stddef.h> /* Required for 'size_t' var type */

/* Externally provided structure */
/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;

/* Externally provided custom putchar */
int _putchar(char c);

/* SiLiLi - Exo 00 (0-print_list.c)   */
size_t print_list(const list_t *h);
/* SiLiLi - Exo 01 (1-list_len.c)     */
size_t list_len(const list_t *h);
/* SiLiLi - Exo 02 (2-add_node.c)     */
list_t *add_node(list_t **head, const char *str);
/* SiLiLi - Exo 03 (3-add_node_end.c) */

/* SiLiLi - Exo 04 (4-free_list.c)    */


#endif
