#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/* Personal addition for "NULL" testing */
#include <sys/resource.h>
/**
 * simple_print_buffer - prints buffer in hexa
 * @buffer: the address of memory to print
 * @size: the size of the memory to print
 *
 * Return: Nothing.
 */
void simple_print_buffer(char *buffer, unsigned int size)
{
	unsigned int i;

	i = 0;
	while (i < size)
	{
		if (i % 10)
		{
			printf(" ");
		}
		if (!(i % 10) && i)
		{
			printf("\n");
		}
		printf("0x%02x", buffer[i]);
		i++;
	}
	printf("\n");
}

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	char *buffer;
	/* ChatGPT provided example to restrict total memory */
	struct rlimit lim;
	/* Personal example to try and make malloc fail */
	char *oversized_buffer;

	buffer = create_array(98, 'H');
	if  (buffer == NULL)
	{
		printf("failed to allocate memory\n");
		return (1);
	}
	simple_print_buffer(buffer, 98);
	free(buffer);

	/* ChatGPT provided example to restrict memory in order to */
	/*   force malloc to fail at some point. */
	if (getrlimit(RLIMIT_AS, &lim) == -1)
	{
		perror("getrlimit");
		return (1);
	}

	lim.rlim_cur = 1 * 1024 * 1024;
	/* Hard limit requires root privileges to be augmented */
	/* Meaning it seems like something sensible, I won't play with it */
	/*   until I really understand implications. */
	/* lim.rlim_max = 50 * 1024 * 1024; */
	if (setrlimit(RLIMIT_AS, &lim) == -1)
		perror("setrlimit");

	oversized_buffer = create_array(200000, 'Z');
	if (oversized_buffer == NULL)
		printf("Tried to buffer overflow but failed");
	else
		printf("Oversized Buffer passed, address %p", oversized_buffer);

	return (0);
}
