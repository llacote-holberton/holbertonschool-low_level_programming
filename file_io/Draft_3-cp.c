#include <fcntl.h>  /* Required for open syscall function. */
#include <stdlib.h> /* Required for malloc. */
#include <unistd.h> /* Required for read syscall function. */
#include <stdio.h>  /* Required for dprintf. */
#include "main.h"   /* Required for custom putchar function. */

/**
 * main - check the code
 * @ac: number of command line arguments.
 * @av: list of the provided arguments themselves.
 * Return: 0 if success, error codes from 97 to 100 if problem.
 *
 * MORE Additional information
 * - All error message should be printed onto POSIX standard error fd.
 * - If the number of argument is not the correct one, exit with code 97
 *     and print "Usage: cp file_from file_to" ending with newline.
 *   , followed by a new line, on the POSIX standard error
 * - If file_to already exists, DO NOT change permissions BUT truncate it.
 * - If file_to is created permissions must be rw-rw-r--.
 * - If file_from does not exist or unreadable, exit with code 98 and
 *     print "Error: Can't read from file NAME_OF_THE_FILE" ending with newline
 *     where NAME_OF_THE_FILE is the first argument passed to your program.
 * - If you can not create or if write to file_to fails, exit with code 99
 *     and print "Error: Can't write to NAME_OF_THE_FILE" ending with newline
 *     where NAME_OF_THE_FILE is the second argument passed to your program
 * - If you can not close a file descriptor , exit with code 100 and
 *     print "Error: Can't close fd FD_VALUE" ending with newline
 *     where FD_VALUE is the value of the file descriptor
 * - You must read 1,024 bytes at a time from the file_from
 *     to make less system calls.
 * - Use a buffer.
 * - You are allowed to use dprintf.
 *
 */
int main(int ac, char **av)
{
	const int INVALID_ARGS__CODE = 97;
	const char *INVALID_ARGS__TMPL = "Usage: cp file_from file_to\n";
	const int INVALID_SOURCE__CODE = 98;
	const char *INVALID_SOURCE__TMPL = "Error: Can't read from file %s\n";
	const char INVALID_DEST__CODE = 99;
	const char *INVALID_DEST__TMPL = "Error: Can't write to %s\n";
	int read_source__fd;
	int write_dest__fd;
	int total_count;
	int cp_loop_count = 0;
	char cp_buffer[1024]; /* Buffer size is imposed and small so on stack. */

	if (ac != 3) /* First is command. We only support single file copy. */
	{
		dprintf(STDERR_FILENO, INVALID_ARGS__TMPL);
		exit(INVALID_ARGS__CODE);
	}
	read_source__fd = open(av[1], O_RDONLY);/* Check that source is readable */
	if (read_source__fd == -1)
	{
		dprintf(STDERR_FILENO, INVALID_SOURCE__TMPL, av[1]);
		exit(INVALID_SOURCE__CODE);
	}

	write_dest__fd = open(av[2], O_WRONLY | O_TRUNC | O_CREAT, 0664);
	if (write_dest__fd == -1)
	{
		dprintf(STDERR_FILENO, INVALID_DEST__TMPL, av[2]);
		exit(INVALID_DEST__CODE);
	}
	while (cp_loop_count > 0)/* @warning try both error (-1) and EOL (0) */
	{
		cp_loop_count = read(read_source__fd, cp_buffer, 1024);
		write(write_dest__fd, cp_buffer, cp_loop_count);
	}

	if (cp_loop_count < 0)
		return (99);
	return (0);
}

/* === BRAINSTORM AND SELF-TEACHING ===*/
/*
 * Probable workflow...
 * 1/ Check whave everything to work
 *    - Good number of arguments or error 97.
 *    - Exploitable source file (exists, readable) or error 98.
 *    - Exploitable destination file (inexistant or writable) or error 99.
 *    WARNING do not forget to close file descriptors (or error 100).
 * 2/ Prepare the copy.
 *   - Initialize the buffer (or error 96 custom one if failed).
 *   - Calculate total size of text (bytes? length? both?)?
 *   - I think I'll need some kind of loop which stops when read from file_from
 *     finds a EOL char.
 */
/* https://pubs.opengroup.org/onlinepubs/7908799/xsh/unistd.h.html */
