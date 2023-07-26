#include "shell.h"

/**
 * file_mode - Executes commands from a file in non-interactive mode.
 * @argv: Array of strings representing the program name and arguments.
 *
 * Return: 0 or 1
 */
int file_mode(char *argv[])
{
	char *bytes = NULL;
	char **expressions = NULL, **args = NULL;
	int fd, read_bytes, code, i = 0;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror(argv[0]);
		exit(1);
	}

	read_bytes = get_input(&bytes, fd);
	if (read_bytes == -1)
	{
		perror(argv[0]);
		exit(1);
	}
	if (read_bytes == -2)
	{
		free(bytes);
		exit(0);
	}

	parse(&expressions, bytes, read_bytes, NEWLINE);
	free(bytes);

	while (expressions[i])
	{
		code = execute(argv[0], args, expressions[i++]);
		free_mem(args, NULL, NULL);
	}

	free(expressions);
	close(fd);
	exit(code);
}
