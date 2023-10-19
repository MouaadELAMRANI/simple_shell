#include "shell.h"

/**
 * _strdup - Function returns a pointer to a newly location in memory
 * @str: string
 * Return: return to dest
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
 * _strcmp - compares two string
 * @s1: str1
 * @s2: str2
 * Return: return to 0
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (1);
	}

	for (i = 0; s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (1);
	}

	return (0);
}
/**
 * _strcnt - Entry point
 * @target: destination pointer
 * @search: source pointer
 * Return: return to 0
 */

int _strcnt(char *target, char *search)
{
	int i;

	for (i = 0; search[i] != '\0'; i++)
	{
		if (target[i] != search[i])
			return (1);
	}

	return (0);
}

/**
 * _getpath - todo
 * @environ: todo
 * Return: todo
 */
char *_getpath(char **environ)
{
	char *pathname = "PATH=";

	for (; *environ; environ++)
	{
		if (_strcnt(*environ, pathname) == 0)
		{
			/*printf("PATH = %s\n", *environ);*/
			return (*environ);
		}
	}
	return (NULL);
}

/**
 * _strcat - Entry point
 * @left: destination pointer
 * @right: source pointer
 * Return: return to string
 */
char *_strcat(char *left, char *right)
{
	int l, r;
	char *concat;

	for (l = 0; left[l] != '\0'; l++)
	for (r = 0; right[r] != '\0'; r++)

	concat = malloc((l + r) * sizeof(char));

	for (l = 0; left[l] != '\0'; l++)
	{
		concat[l] = left[l];
	}
	for (r = 0; right[r] != '\0'; r++)
	{
		concat[l + r] = right[r];
	}

	return (concat);
}
