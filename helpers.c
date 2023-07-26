#include "shell.h"

/**
 * free_mem - Frees memory occupied by various pointers and strings.
 * @vec: Pointer to the array of strings to be freed.
 * @str1: Pointer to the first string to be freed.
 * @str2: Pointer to the second string to be freed.
 */
void free_mem(char **vec, char *str1, char *str2)
{
	size_t i;

	if (vec)
	{
		for (i = 0; vec[i]; i++)
		{
			if (vec[i] != str2)
			{
				free(vec[i]);
				vec[i] = NULL;
			}
		}
		free(vec);
		vec = NULL;
	}
	if (str1)
	{
		free(str1);
		str1 = NULL;
	}
	if (str2)
	{
		free(str2);
		str2 = NULL;
	}
}

/**
 * remove_comment - Removes the comment from a string.
 * @str: The string from which to remove the comment.
 *
 * Return: 1 if a comment is found and removed,
 *		or 0 if no comment is present.
 */
int remove_comment(char *str)
{
	int i;

	if (!str)
		return (0);

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '#')
		{
			str[i] = '\0';
			return (1);
		}
	}

	return (0);
}

/**
 * free_vec - Frees memory occupied by a NULL-terminated array of strings.
 * @vec: Pointer to the array of strings to be freed.
 */
void free_vec(char **vec)
{
	int i;

	if (vec)
	{
		for (i = 0; vec[i]; i++)
			free(vec[i]);
		free(vec);
		vec = NULL;
	}
}

/**
 * handle_eof_empty - Handle EOF and empty line
 * @line: Line
 * @size: Size
 *
 * Return: 0 or 1
 */
int handle_eof_empty(char *line, ssize_t size)
{
	if (size == -2)
	{
		free(line);
		write(STDOUT_FILENO, "\n", 1);
	}

	if (size == -1 || size == -2)
		exit(0);

	if (!*line)
		return (1);

	return (0);
}
