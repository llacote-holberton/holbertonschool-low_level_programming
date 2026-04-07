#include <fcntl.h>  /* Required for open syscall function. */
#include <stdlib.h> /* Required for malloc. */
#include <unistd.h> /* Required for read syscall function. */
#include "main.h"   /* Required for custom putchar function. */

#include <stdio.h> /* @temporary */

/**
 * read_textfile - Lit un fichier en entrée
 *
 * @filename: path of the file to read.
 * @letters: numbers of characters from file which should be printed.
 * Return: 0 if failure for any cause, number of characters printed otherwise.
 *
 * Additional infos
 * - If the file can not be opened or read, return 0
 * - If filename is NULL return 0
 * - If write fails or does not write the expected amount of bytes, return 0
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	const int read_failure = 0;
	ssize_t readonly_filedescriptor;
	/*  No other choice than dynamic alloc as cannot know size in advance. */
	/* ssize_t read_buffer[]; -> CANNOT WORK */
	ssize_t *read_buffer = NULL;
	ssize_t to_print;
	ssize_t printed;

	/* Let's start with the classics. */
	if (!filename || !letters)
		return (read_failure);
	printf("Attempting to open the file %s.\n", filename);

	readonly_filedescriptor = open(filename, O_RDONLY);
	if (readonly_filedescriptor == -1)
		return (read_failure);

	/*@note: malloc tried AFTER opening because I feel it is useful to caller */
	/*  to "first" know that the file is not even available for reading. */
	read_buffer = malloc(letters);
	if (!read_buffer)
	{
		close(readonly_filedescriptor);
		return (read_failure);
	}

	to_print = read(readonly_filedescriptor, read_buffer, letters);
	if (to_print != -1)
	{
		printed = write(1, read_buffer, to_print);
	}
	else
		printed = read_failure;

	close(readonly_filedescriptor);
	free(read_buffer);
	read_buffer = NULL;

	return (printed);

}


