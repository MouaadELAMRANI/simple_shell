#include "shell.h"

int shell(void)
{
	char *cmd = NULL;
	size_t n = 0;

	printf("SHELL START\n");
	printf("$ ");
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
		return (handlecommand(cmd));
}

int handlecommand(char *cmd)
{
	char *cmd_dup = NULL, *token = NULL, *delim = " \n", **argv = NULL;
	int argc = 0, i = 0;
	extern char **environ;

	printf("handlecommand START\n");
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
		if (executecommand(argv, environ) != 0)
		{
			printf("No such file or directory\n");
			return (-1);
		}
		free(cmd), free(argv);
	}

	return (0);
}

int executecommand(char **argv, char **environ)
{
	int status;
	char *command;

	printf("executecommand START\n");
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
	/*else if (access(argv[0], X_OK) == 0)
		command = argv[0];
	else if (access(_strcat(_getpath(environ), argv[0]), X_OK) == 0) 
		command = _strcat("/bin/", argv[0]);
	else
		return (1);*/
	else
	{
		command = getcommand(argv, environ);
		if (command != NULL)
		{
			if (fork() == 0)
			{
				execve(command, argv, environ);
			}
			else
				wait(&status);
		}
	}

	printf("done");
	return (0);
}

char *getcommand(char **argv, char **environ)
{
	char *path = _getpath(environ), *token, *delim = ":";

	printf("getcommand START\n");
	printf("PATH is: %s\n", path);
	printf("got path\n");
	if (access(argv[0], X_OK) == 0)
	{
		printf("found outside path\n");
		return (argv[0]);
	}
	else
	{
		printf("searching for command in path\n");
		token = strtok(path, delim);
		while (token)
		{
			token = strtok(NULL, delim);
			printf("currently searching in: %s\n", token);
			printf("TOKEN = %s\n", _strcat(_strcat(token, "/"), argv[0]));
			if (access(_strcat(_strcat(token, "/"), argv[0]), X_OK) == 0)
			{
				printf("OK %s\n", _strcat(_strcat(token, "/"), argv[0]));
				return _strcat(_strcat(token, "/"), argv[0]);
			}
		}
	}

	return (NULL);
}
