#include "shell.h"

/**
 * _getline - Reads a line from a file descriptor.
 * @lineptr: Pointer to the buffer where the line is stored.
 * @n: Pointer to the size of the buffer.
 * @fd: File descriptor from which to read the line.
 *
 * Return: The number of bytes read, -1 on failure,
 *		or -2 if the end of the file is reached.
 */
ssize_t _getline(char **lineptr, size_t *n, int fd)
{
	ssize_t nread = 0;

	if (!lineptr || !n || fd < 0)
		return (-1);

	*lineptr = malloc(BUFFER_SIZE * sizeof(char));
	if (!*lineptr)
		return (-1);

	*n = BUFFER_SIZE;

	nread = read(fd, *lineptr, BUFFER_SIZE - 1);
	if (nread == -1)
	{
		free(*lineptr);
		return (-1);
	}

	if (nread > 0)
	{
		(*lineptr)[nread] = '\0';

		while (_isspace(**lineptr))
			(*lineptr)++;
	}

	return (nread);
}

/**
 * get_input - Reads input from a file descriptor and handles comments.
 * @line: Pointer to the buffer where the input is stored.
 * @fd: File descriptor from which to read the input.
 *
 * Return: The number of bytes read, -1 on failure,
 *		or -2 if the end of the file is reached.
 */
ssize_t get_input(char **line, int fd)
{
	size_t n = 0;
	ssize_t read_bytes = 0;

	read_bytes = _getline(line, &n, fd);
	if (read_bytes == 0)
		return (-2);
	if (remove_comment(*line))
	{
		read_bytes = _strlen(*line);
		if (read_bytes == 0)
			return (-2);
	}
	if (read_bytes == -1)
		return (-1);

	if ((*line)[read_bytes - 1] == '\n')
		(*line)[read_bytes - 1] = '\0';

	return (read_bytes);
}
