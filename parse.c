#include "shell.h"

/**
 * parse - Tokenizes a line and stores the tokens in a 2D array.
 * @args: Pointer to the pointer that will hold the array of tokens.
 * @line: The input line to be tokenized.
 * @size: The size of the input line buffer.
 * @delims: The delimiters used to tokenize the line.
 *
 * Return: 1 on success, 0 on memory allocation failure.
 */
size_t parse(char ***args, char *line, size_t size, const char *delims)
{
	char *token;
	size_t len = size / 2 + size % 2 + 1;
	size_t i;

	*args = malloc(len * sizeof(char *));
	if (!*args)
		return (1);

	token = _strtok(line, delims);
	for (i = 0; token; i++)
	{
		(*args)[i] = malloc((_strlen(token) + 1) * sizeof(char));
		if (!(*args)[i])
		{
			free_vec(*args);
			return (0);
		}

		_strcpy((*args)[i], token);
		token = _strtok(NULL, delims);
	}

	line = NULL;
	(*args)[i] = NULL;
	return (1);
}
