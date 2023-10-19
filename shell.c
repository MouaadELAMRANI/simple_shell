#include "shell.h"

/**
 * shell - basic shell
 * Return: void
 */

int shell(void)
{
	char *cmd = NULL;
	size_t n = 0;

	if (isatty(STDIN_FILENO))
	{
		printf("$ ");
	}

	/*printf("SHELL START\n");*/
	if (getline(&cmd, &n, stdin) < 1)
	{
		free(cmd);
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		handlecommand(cmd);
	}
		
	
	return (0);
}

/**
 * handlecommand - to handle cmd
 * @cmd: char
 * Return: return to 0
 */
void handlecommand(char *cmd)
{
	char *cmd_dup = NULL, *token = NULL, *delim = " \n", **argv = NULL;
	int argc = 0, i = 0;

	/*printf("handlecommand START\n");*/
	cmd_dup = _strdup(cmd);
	token = strtok(cmd, delim);
	while (token)
	{
		token = strtok(NULL, delim);
		argc++;
	}
	if (argc > 0)
	{
		argv = malloc(sizeof(char *) * argc);
		token = strtok(cmd_dup, delim);
		while (token)
		{
			argv[i] = token;
			token = strtok(NULL, delim);
			i++;
		}
		argv[i] = NULL;
		if (executecommand(argv, __environ) != 0)
		{
			printf("No such file or directory\n");
		}
		free(cmd), free(argv);
	}
}

/**
 * executecommand - cmd excution
 * @argv: argument value
 * @environ: env
 * Return: return to 0
 */
int executecommand(char **argv, char **environ)
{
	int status;
	char *command;

	if (_strcmp("exit", argv[0]) == 0)
	{
		exit(EXIT_SUCCESS);
		return (0);
	}
	else if (_strcmp("env", argv[0]) == 0)
	{
		printenv(environ);
		return (0);
	}
	else
	{
		command = getcommand(argv);
		if (command != NULL)
		{
			if (fork() == 0)
			{
				execve(command, argv, __environ);
			}
			else
				wait(&status);
			
			return (0);
		}
		else
		{
			return (-1);
		}
	}
}

/**
 * getcommand - ?
 * @argv: argument value
 * @environ: env
 * Return: return to NULL
 */
char *getcommand(char **argv)
{
	/*char *token, *delim = ":"; path = _getpath(environ),*/

	/*printf("getcommand START\n");*/
	/*printf("PATH is: %s\n", path);*/
	/*printf("got path\n");*/
	if (access(argv[0], X_OK) == 0)
	{
		/*printf("found outside path\n");*/
		return (argv[0]);
	}
	else
	{
		/*printf("searching for command in path\n");*/
		if (access(_strcat("/bin/", argv[0]), X_OK) == 0)
		{
			/*printf("OK %s\n", _strcat("/bin/", argv[0]));*/
			return (_strcat("/bin/", argv[0]));
		}

		/*token = strtok("/bin/", delim);*/
		/*while (token)*/
		/*{*/
		/*	token = strtok(NULL, delim);*/
			/*printf("currently searching in: %s\n", token);*/
			/*printf("TOKEN = %s\n", _strcat(_strcat(token, "/"), argv[0]));*/
			/*if (access(_strcat(_strcat(token, "/"), argv[0]), X_OK) == 0)*/
			/*{*/
				/*printf("OK %s\n", _strcat(_strcat(token, "/"), argv[0]));*/
				/*return (_strcat(_strcat(token, "/"), argv[0]));*/
			/*}*/
		/*}*/
	}

	return (NULL);
}
