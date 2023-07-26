#include "shell.h"

/**
 * _strstr -Locates a substring.
 * @haystack: The string to check.
 * @needle: The substring to find.
 *
 * Return: Pointer to the beginning of the located substring.
 * Or NULL if the substring is not found.
 */
char *_strstr(char *haystack, char *needle)
{
	int i, j;
	int start = 0;
	int has_str = 0;
	int sub_len = strlen(needle);

	if (*needle == '\0')
		return (haystack);

	for (i = 0; haystack[i]; i++)
		if (haystack[i] == needle[0])
		{
			start = i;
			has_str = 1;

			for (j = 1; j < sub_len; j++)
			{
				if (haystack[++i] != needle[j])
				{
					has_str = 0;
					break;
				}
			}

			if (has_str)
				return (haystack + start);
		}

	return (NULL);
}

/**
 * _isspace - checks if a character is a whitespace
 * @c: The character to check
 *
 * Return: 1 if c is a whitespace, otherwise 0
 */
int _isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' ||
		c == '\v' || c == '\f' || c == '\r');
}

/**
 * _atoi - Converts a string to an integer.
 * @s: The string to convert.
 *
 * Return: The converted integer. Otherwise 0;
 */
int _atoi(char *s)
{
	int sign = 1;
	int got_number = 0;
	unsigned int number = 0;

	while (*s != '\0')
	{
		char c = *s;

		if (!got_number && c == '-')
			sign *= -1;

		if (c >= 48 && c <= 57)
		{
			int digit = c - '0';

			number = number * 10 + digit;
			got_number = 1;
		}
		else if (got_number)
			break;

		s++;
	}

	return (number * sign);
}

/**
 * _memcpy - Copies a specified number of bytes from source
 *		to destination memory.
 * @dest: Pointer to the destination memory.
 * @src: Pointer to the source memory.
 * @bytes: Number of bytes to copy.
 */
void _memcpy(char *dest, char *src, unsigned int bytes)
{
	unsigned int i;

	for (i = 0; i < bytes; i++)
		dest[i] = src[i];
}

/**
 * _realloc - Reallocates a memory block using malloc and free.
 * @ptr: A pointer to the memory previously allocated.
 * @size: The size of the new memory to be allocated.
 *
 * Return: A pointer to the reallocated memory.
 */
void *_realloc(void *ptr, size_t size)
{
	void *new_ptr;
	char *old_ptr, *new_ptr_char;
	size_t i;

	if (size == 0)
	{
		free(ptr);
		ptr = NULL;
		return (NULL);
	}

	new_ptr = malloc(size);
	if (new_ptr == NULL)
		return (NULL);

	if (ptr)
	{
		old_ptr = (char *)ptr;
		new_ptr_char = (char *)new_ptr;

		for (i = 0; i < size; i++)
			new_ptr_char[i] = old_ptr[i];
		free(ptr);
		ptr = NULL;
	}

	return (new_ptr);
}
