#include "shell.h"
/**
 * printenv - function to print env
 * @environ: arg
 * Return: void
 */

void printenv(char **environ)
{
	for (; *environ; environ++)
	{
		printf("%s\n", *environ);
	}
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
