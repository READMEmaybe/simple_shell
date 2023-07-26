#include "shell.h"

/**
 * interactive_mode - Run shell in interactive mode
 * @p_name: Program name
 *
 * Return: 0 or 1
 */
int interactive_mode(char *p_name)
{
	char *line = NULL;
	char **args = NULL;
	ssize_t line_size;
	int code;

	while (1)
	{
		write(STDOUT_FILENO, PROMPT, 2);
		line_size = get_input(&line, STDIN_FILENO);
		if (line_size != -2 && _strcmp(line, "exit") == 0)
		{
			free_mem(NULL, NULL, line);
			exit(0);
		}
		if (handle_eof_empty(line, line_size))
		{
			line = NULL;
			return (1);
		}
		if (line)
		{
			code = execute(p_name, args, line);
			free_vec(args);
		}
	}
	return (code);
}
