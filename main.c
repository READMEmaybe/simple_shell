#include "shell.h"

/**
 * main - Entry point
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 * Return: 0;
 */
int main(int argc, char *argv[])
{

	if (argc > 1 || isatty(STDIN_FILENO))
	{
		if (argc > 1)
		{
			file_mode(argv);
		}
		if (isatty(STDIN_FILENO))
		{
			interactive_mode(argv[0]);
		}
	}
	else
	{
		non_interactive_mode(argv);
	}

	return (0);
}
