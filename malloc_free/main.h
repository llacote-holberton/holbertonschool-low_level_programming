#ifndef MAIN_H
#define MAIN_H

/* Externally provided function defined in _putchar.c */
int _putchar(char c);
/* Ma+Fr - R1 - Exo 00 - 0-isupper.c */
char *create_array(unsigned int size, char c);
/* Ma+Fr - R1 - Exo 01 - 1-strdup.c */
char *_strdup(char *str);
/* Ma+Fr - R1 - Exo 02 -  */
char *str_concat(char *s1, char *s2);
/* Ma+Fr - R1 - Exo 03 -  */
int **alloc_grid(int width, int height);
/* Ma+Fr - R1 - Exo 04 -  */
void free_grid(int **grid, int height);


#endif
