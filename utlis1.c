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
