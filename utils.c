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

	for (i = 0; s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (1);
	}

	return (0);
}

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
 * _strcat - todo
 * @dest: todo
 * @src: todo
 * Return: todo
 */
char *_strcat(char *left, char *right)
{
	int l, r;
	char *concat;

	for (l = 0; left[l] != '\0'; l++);
	for (r = 0; right[r] != '\0'; r++);

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


void printenv(char **environ)
{
	for (; *environ; environ++) 
	{
		printf("%s\n", *environ);
	}
}

/**
 
_getpath - todo
@environ: todo
Return: todo
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

	return NULL;
}
