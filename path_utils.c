#include "shell.h"

/**
 * _getenv - Get environment variable
 * @name: Name of environment variable
 *
 * Return: Pointer to environment variable
 */
char *_getenv(const char *name)
{
	int i, j, len;
	char **env, *tmp;

	if (!name)
		return (NULL);
	env = environ;
	for (i = 0; env[i]; i++)
	{
		for (len = 0; env[i][len] != '='; len++)
			;
		len++;
		tmp = malloc((len) * sizeof(char));
		_memcpy(tmp, env[i], len - 1);
		tmp[len - 1] = '\0';
		if (_strncmp((char *)name, tmp, _strlen(tmp)) == 0)
		{
			free(tmp);
			tmp = NULL;
			for (j = 0; env[i][j]; j++)
			{
				if (env[i][j] == '=')
				{
					tmp = &env[i][j + 1];
					break;
				}
			}
			return (tmp);
		}
		free(tmp);
		tmp = NULL;
	}
	return (NULL);
}

/**
 * get_stat - Get stat of file
 * @filename: Filename
 *
 * Return: Pointer to filename
 */
char *get_stat(char *filename)
{
	struct stat st;

	if (!filename)
	{
		perror("Filename");
		exit(1);
	}

	if (stat(filename, &st) == 0)
		if (access(filename, X_OK) == 0)
			return (filename);

	return (NULL);
}

/**
 * append_slash - Append slash to filename
 * @filename: Filename
 *
 * Return: Pointer to new filename
 */
char *append_slash(char *filename)
{
	char *new_filename = NULL;
	size_t length;

	if (!filename)
	{
		perror("Filename");
		exit(1);
	}

	length = _strlen(filename);
	new_filename = malloc(length + 2);
	if (!new_filename)
	{
		perror("Failed to allocate memory");
		exit(1);
	}

	new_filename[0] = '/';
	new_filename[1] = '\0';
	_strcat(new_filename, filename);

	return (new_filename);
}

/**
 * get_file_path - Get file path
 * @directory: Directory
 * @filename: Filename
 *
 * Return: Pointer to file path
 */
char *get_file_path(char *directory, char *filename)
{
	char *file_path;

	if (!directory || !filename)
	{
		perror("Error");
		exit(1);
	}

	file_path = malloc(_strlen(directory) + _strlen(filename) + 1);
	if (!file_path)
	{
		perror("Failed to allocate memory");
		exit(1);
	}

	file_path[0] = '\0';
	_strcat(file_path, directory);
	_strcat(file_path, filename);

	return (file_path);
}
