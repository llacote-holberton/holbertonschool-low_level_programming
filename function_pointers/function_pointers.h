#ifndef FUNCTION_POINTERS_H
#define FUNCTION_POINTERS_H

/* Externally provided function defined in _putchar.c */
int _putchar(char c);
/* FnPtrs - Exo 00 */
void print_name(char *name, void (*f)(char *));
/* FnPtrs - Exo 01 */
void array_iterator(int *array, size_t size, void (*action)(int));
/* FnPtrs - Exo 02 */

/* FnPtrs - Exo 03 */



#endif
