#include <fcntl.h>  /* Required for open syscall function. */
#include <stdlib.h> /* Required for malloc. */
#include <unistd.h> /* Required for read syscall function. */
#include "main.h"   /* Required for custom putchar function. */

/**
 * append_text_to_file - Appends text at the end of (existing) file.
 *
 * @filename: path of the file to create.
 * @text_content: NULL terminated ('\0') string to put inside.
 * Return: 1 on success, -1 if failure for any cause (NULL filename,
 *   file not creatable/writable, write "fails", etc…).
 *
 * Additional infos
 * - Text_content is a NULL terminated string to write to the file
 * - Do not create the file if it does not exist
 * - If NULL filename return -1.
 * - If NULL text_content don't add anything to the file. Instead return...
 *   1 (file exists) or -1 (cannot modify it: does not exist or no write perm).
 */
int append_text_to_file(const char *filename, char *text_content)
{
	const int APPEND_FAILURE = -1;
	const int APPEND_SUCCESS =  1;

	int writing_fd;
	int text_size;
	int written = 0;

	if (!filename)
		return (APPEND_FAILURE);

	/* @note no need to go too far, trying access in write is enough to know. */
	writing_fd = open(filename, O_WRONLY | O_APPEND);
	if (writing_fd == -1)
		return (APPEND_FAILURE);
	/* @note imo it's logical to include case "pointer exists but empty str". */
	if (!text_content || text_content[0] == '\0')
	{
		/* @warning DO NOT FORGET to CLOSE! */
		close(writing_fd);
		return (APPEND_SUCCESS);
	}
	for (text_size = 0; text_content[text_size]; text_size++)
	;
	if (text_size > 0)
		written = write(writing_fd, text_content, text_size);
	/* Naive: write can interrupt if writing on unreliable outs like sockets. */
	/*   should be enough for current exercise. */
	close(writing_fd);
	return ((written >= 0) ? APPEND_SUCCESS : APPEND_FAILURE);
}



