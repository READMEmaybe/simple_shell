#include "shell.h"

/**
 * no_such_file_error - Displays an error message for a non-existent file.
 * @p_name: Name of the program.
 * @f_name: Name of the non-existent file.
 */
void no_such_file_error(char *p_name, char *f_name)
{
	write(STDERR_FILENO, p_name, _strlen(p_name));
	write(STDERR_FILENO, ": 0: cannot open ", 17);
	write(STDERR_FILENO, f_name, _strlen(f_name));
	write(STDERR_FILENO, ": No such file", 14);
	write(STDERR_FILENO, "\n", 1);
}

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
		no_such_file_error(argv[0], argv[1]);
		exit(2);
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
