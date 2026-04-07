#include <fcntl.h>  /* Required for open syscall function. */
#include <stdlib.h> /* Required for malloc. */
#include <unistd.h> /* Required for read syscall function. */
#include "main.h"   /* Required for custom putchar function. */

/**
 * create_file - Redefines a file content or creates it.
 *
 * @filename: path of the file to create.
 * @text_content: NULL terminated ('\0') string to put inside.
 * Return: 1 on success, -1 if failure for any cause (NULL filename,
 *   file not creatable/writable, write "fails", etc…).
 *
 * Additional infos
 * - Tex NULL terminated string to write to the file
 * - The created file must have those permissions: rw-------.
 * - If the file already exists, keep permissions but truncate.
 * - If text_content is NULL create an empty file.
 */
int create_file(const char *filename, char *text_content)
{
	const int CREATE_FAILURE = -1;
	const int CREATE_SUCCESS =  1;
	/* File descriptor handle for file manipulation.*/
	int writing_fd;
	int text_size;
	int written;
	/* Seems more logical to me to do in that order. */
	int open_flags = O_WRONLY | O_TRUNC | O_CREAT;
	mode_t octal_permissions = 0600;

	/* Steps: classic guard clauses -> check file existss -> */
	/* if exist just truncate and return 1 otherwise create and write. */
	if (!filename)
		return (CREATE_FAILURE);

	writing_fd = open(filename, open_flags, octal_permissions);
	if (writing_fd == -1)
		return (CREATE_FAILURE);

	if (!text_content) /* Expected behaviour is empty file, done. */
		return (CREATE_SUCCESS);

	for (text_size = 0; text_content[text_size]; text_size++)
	;
	if (text_size > 0)
		written = write(writing_fd, text_content, text_size);

	close(writing_fd);
	return ((written >= 0) ? CREATE_SUCCESS : CREATE_FAILURE);
}



