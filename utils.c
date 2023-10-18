#include "shell.h"

/**
 * _strlen - todo
 * @msg: too
 * Return: todo
 **/
int _strlen(char *msg)
{
	int i;

	for (i = 0; msg[i] != '\0'; i++)
		;

	return (i);
}


/**
 * _strdup - todo
 * @str: todo
 * Return: todo
 **/
char *_strdup(char *str)
{
	int size, i;
	char *dest;

	if (str == NULL)
		return (NULL);

	size = _strlen(str) + 1;
	dest = malloc(size * sizeof(char));
	if (dest == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		*(dest + i) = *(str + i);

	/* (dest + i) = 0; */

	return (dest);
}

/**
 * _strcmp - todo
 * @s1: todo
 * @s2: todo
 * Return: todo
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (1);
	}

	return (0);
}

/**
 * _strcat - todo
 * @dest: todo
 * @src: todo
 * Return: todo
 */
char *_strcat(char *dest, char *src)
{
	char *concat = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (concat);
}
