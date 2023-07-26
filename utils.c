#include "shell.h"

/**
 * _strlen - Returns the length of a string.
 * @str: The string to be checked.
 * Return: The length of str.
 */
size_t _strlen(const char *str)
{
	size_t i = 0;

	while (str[i])
		i++;

	return (i);
}

/**
 * _strcmp - Compares two strings.
 * @s1: First string.
 * @s2: Second string.
 *
 * Return: A negative value if s1 is less than s2.
 * A positive value if s1 is greater than s2.
 * 0, if the s1 and s2 are equal.
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * _strncmp - Compares two strings up to a specified number of bytes.
 * @s1: First string.
 * @s2: Second string.
 * @bytes: Number of bytes to compare.
 *
 * Return: A negative value if s1 is less than s2, zero if they are equal,
 * or a positive value if s1 is greater than s2.
 */
int _strncmp(char *s1, char *s2, size_t bytes)
{
	unsigned int i;

	if (s1 == NULL || s2 == NULL)
		return (-1);

	for (i = 0; s1[i] && s2[i] && s2[i] == s1[i] && i < bytes - 1; i++)
		;
	return (s2[i] - s1[i]);
}

/**
 * *_strcpy - Copies string.
 * @dest: Destination string.
 * @src: Source string.
 *
 * Return: The pointer to dest.
 */
char *_strcpy(char *dest, const char *src)
{
	char *d = dest;

	while (*src)
		*d++ = *src++;

	*d = '\0';

	return (dest);
}

/**
 * _strncpy - Copies a string.
 * @dest: The destination string.
 * @src: The source string.
 * @n: The number of bytes to copy.
 *
 * Return: Pointer to the string dest.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];

	for (; i < n; i++)
		dest[i] = '\0';

	return (dest);
}
