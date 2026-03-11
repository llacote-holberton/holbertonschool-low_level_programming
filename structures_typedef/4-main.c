#include <stdio.h>
#include "dog.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	dog_t *my_dog;
	dog_t *custom_dog;

	my_dog = new_dog("Poppy", 3.5, "Bob");
	printf("My name is %s, and I am %.1f :) - Woof!\n",
				 my_dog->name, my_dog->age);

	custom_dog = new_dog("4th Dawg", 777, "Universe is my master.");
	printf("My name is %s, and I am %.1f :) - %s\n",
				 custom_dog->name, custom_dog->age, custom_dog->owner);
	return (0);
}
