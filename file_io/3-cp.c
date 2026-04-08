#include <fcntl.h>  /* Required for open syscall function. */
#include <stdlib.h> /* Required for malloc. */
#include <unistd.h> /* Required for read syscall function. */
#include <stdio.h>  /* Required for dprintf. */
#include "main.h"   /* Required for custom putchar function. */

/**
 * exit_in_error - Bubbles up error on standard error fd.
 * @error_code: valid code (caller must know them, current limitation).
 * @tmpl_var: string to interpolate in template (caller ).
 * @src_fd: file descriptor to close
 * @dest_fd: file descriptor to close
 * Return: -1 if unknown error code, otherwise the error code.
 *
 * NOTE: this is a quick and dirty fun just to separate code.
 *  Needing the caller to know the code and templates is awfully bad DX.
 *  And this would be a perfect use case for a combo
 *    "structure + correspondance table" to be honest.
 */
int exit_in_error(int error_code, char *tmpl_var, int src_fd, int dest_fd)
{
	/* IVD == INVALID */
	const int IVD_ARGS__CODE = 97;
	const char *IVD_ARGS__TMPL = "Usage: cp file_from file_to\n";
	const int IVD_SRC__CODE = 98;
	const char *IVD_SRC__TMPL = "Error: Can't read from file %s\n";
	const char IVD_DEST__CODE = 99;
	const char *IVD_DEST__TMPL = "Error: Can't write to %s\n";
	const char FDC_FAIL__CODE = 100;
	const char *FDC_FAIL__TMPL = "Error: Can't close fd %d\n";
	int fd_closed; /* @warning do NOT forget to check it closed correctly! */

	switch (error_code)
	{
		/* case IVD_ARGS__CODE doesn't work :/ */
		case 97:
			dprintf(IVD_ARGS__CODE, IVD_ARGS__TMPL, (tmpl_var) ? tmpl_var : "(nil)");
			break;
		case 98:
			dprintf(IVD_SRC__CODE, IVD_SRC__TMPL, (tmpl_var) ? tmpl_var : "(nil)");
			break;
		case 99:
			dprintf(IVD_DEST__CODE, IVD_DEST__TMPL, (tmpl_var) ? tmpl_var : "(nil)");
			break;
		case 100:
			dprintf(FDC_FAIL__CODE, FDC_FAIL__TMPL, (tmpl_var) ? tmpl_var : "(nil)");
			break;
		default:
			break;
	}
	fd_closed = (src_fd != -1) ? close(src_fd) : 0;
	if (fd_closed == -1)
		dprintf(FDC_FAIL__CODE, FDC_FAIL__TMPL, src_fd);
	fd_closed = (dest_fd != -1) ? close(dest_fd) : 0;
	if (fd_closed == -1)
		dprintf(FDC_FAIL__CODE, FDC_FAIL__TMPL, dest_fd);
	if (error_code >= 97 && error_code <= 100)
		exit(error_code);
	else
		return (-1);
}

/**
 * get_source_reader - Returns a RO file descriptor handle.
 * @pathname: filename (possibly with path) of file to read.
 * @src_fd: file descriptor to propagate to closer if error.
 * @dest_fd: file descriptor to propagate to closer if error.
 * Return: file descriptor if success. Exit in error otherwise.
 */
int get_source_reader(char *pathname, int src_fd, int dest_fd)
{
	int read_source__fd;

	if (!pathname || pathname[0] == '\0')
		exit_in_error(98, pathname, src_fd, dest_fd);
	read_source__fd = open(pathname, O_RDONLY);
	if (read_source__fd == -1)
		exit_in_error(98, pathname, src_fd, dest_fd);
	return (read_source__fd);
}

/**
 * get_dest_writer - Returns a RO file descriptor handle.
 * @pathname: filename (possibly with path) of file to read.
 * @src_fd: file descriptor to propagate to closer if error.
 * @dest_fd: file descriptor to propagate to closer if error.
 * Return: file descriptor if success. Exit in error otherwise.
 */
int get_dest_writer(char *pathname, int src_fd, int dest_fd)
{
	int write_dest__fd;
	int opening_flags = O_WRONLY | O_TRUNC | O_CREAT;
	mode_t new_file_perms = 0644;

	if (!pathname || pathname[0] == '\0')
		exit_in_error(99, pathname, src_fd, dest_fd);
	write_dest__fd = open(pathname, opening_flags, new_file_perms);
	if (write_dest__fd == -1)
		exit_in_error(99, pathname, src_fd, dest_fd);
	return (write_dest__fd);
}

/**
 * main - check the code
 * @ac: number of command line arguments.
 * @av: list of the provided arguments themselves.
 * Return: 0 if success, error codes from 97 to 100 if problem.
 *
 * Additional information
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
	int reader_handle = -1;
	int writer_handle = -1;
	int total_count = 0;
	int chars_to_write = 1; /* Need to initialize above 0 to enter loop. */
	int chars_written = 0;
	char cp_buffer[1024]; /* Buffer size is imposed and small so on stack. */

	/* Check we have the right number of arguments (separated by space) */
	if (ac != 3) /* First is command. We only support single file copy. */
		exit_in_error(97, NULL, reader_handle, writer_handle);
	/* Check that source file is readable (callee exits if failure). */
	reader_handle = get_source_reader(av[1], reader_handle, writer_handle);
	/* Check that dest file is writable (callee exits if failure). */
	writer_handle = get_dest_writer(av[2], reader_handle, writer_handle);
	/* @warning problem of this architecture is we cannot close opened fd!! */
	while (chars_to_write > 0)
	{
		chars_to_write = read(reader_handle, cp_buffer, 1024);
			if (chars_to_write < 0)
				exit_in_error(98, av[1], reader_handle, writer_handle);
			else if (chars_to_write == 0)
				break;

			chars_written = write(writer_handle, cp_buffer, chars_to_write);
			if (chars_written == -1)
				exit_in_error(99, av[1], reader_handle, writer_handle);
			total_count += chars_written;
	}

	if (chars_to_write < 0)
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
