#include "shell.h"

/**
 * get_command - Get command
 * @arg: Argument
 *
 * Return: Command
 */
char *get_command(char *arg)
{
	char *path, *filename = NULL, *directory = NULL, *file_path = NULL;

	if (get_stat(arg))
		return (arg);

	path = _strdup(_getenv("PATH"));
	if (!path)
	{
		/* perror("Failed to get PATH"); */
		return (NULL);
	}
	filename = append_slash(arg);
	directory = _strtok(path, ":");
	while (directory)
	{
		file_path = get_file_path(directory, filename);

		if (get_stat(file_path))
		{
			free_mem(NULL, filename, path);
			return (file_path);
		}

		free(file_path);
		file_path = NULL;
		directory = _strtok(NULL, ":");
	}
	free_mem(NULL, filename, path);
	free_mem(NULL, directory, file_path);

	return (NULL);
}

/**
 * execute_command - Execute command
 * @command: Command
 * @args: Arguments
 *
 * Return: Status
 */
int execute_command(char *command, char **args)
{
	pid_t child;
	int status;

	child = fork();
	if (child == -1)
	{
		perror("fork");
		return (1);
	}

	if (child == 0)
	{
		if (execve(command, args, environ) == -1)
		{
			perror("execve");
			exit(1);
		}
	}
	else
		wait(&status);

	return (status);
}

/**
 * execute - Executes a command with arguments parsed from an expression.
 * @p_name: Name of the program.
 * @args: Array of arguments for the command.
 * @expression: Expression containing the command and arguments.
 *
 * Return: The exit code of the executed command.
 */
int execute(char *p_name, char **args, char *expression)
{
	char *command = NULL;
	int code;

	parse(&args, expression, _strlen(expression), DELIMITERS);

	command = get_command(args[0]);
	if (!command)
	{
		write(STDERR_FILENO, p_name, _strlen(p_name));
		write(STDERR_FILENO, ": 1: ", 5);
		write(STDERR_FILENO, args[0], _strlen(args[0]));
		write(STDERR_FILENO, ": not found\n", 12);
		code = 127;
	}
	else 
		code = execute_command(command, args);
	free_mem(args, expression, command);

	return (code);
}
