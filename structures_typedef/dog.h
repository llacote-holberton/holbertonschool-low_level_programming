#ifndef DOG_H
#define DOG_H

/* Let's make dogs! */
/**
 * struct dog - Basic representation of dogs.
 * @name:  string representing Dog's name.
 * @age:   float because we must be precise.
 * @owner: string for his best Human pal.
 */
struct dog
{
	char  *name;
	float age;
	char  *owner;
};

/* C - Struct&Types - Exo 01*/
void init_dog(struct dog *d, char *name, float age, char *owner);

#endif
