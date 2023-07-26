#include "shell.h"

/**
 * non_interactive_mode - Executes commands in non-interactive mode.
 * @argv: Array of strings representing the program name and arguments.
 *
 * Return: 0;
 */
int non_interactive_mode(char *argv[])
{
	char *bytes = NULL;
	char **expressions = NULL, **args = NULL;
	int read_bytes, code = 0, i = 0;

	read_bytes = get_input(&bytes, STDIN_FILENO);
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

	if (expressions[i])
	{
		while (expressions[i])
		{
			code = execute(argv[0], args, expressions[i]);
			free_vec(args);
			i++;
		}
	}
	free(expressions);

	exit(code);
}
