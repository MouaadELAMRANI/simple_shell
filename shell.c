#include "shell.h"

int shell(void)
{
	char *cmd = NULL;
	size_t n = 0;

	/* taking input */
	printf("$ ");


	if (getline(&cmd, &n, stdin) < 1)
	{
		if (feof(stdin))
		{
			free(cmd);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(cmd);
			exit(EXIT_FAILURE);
		}
	}
	else if (_strlen(cmd) > 1)
	{
		return (handlecommand(cmd));
	}
	else
	{
		return (0);
	}
}

int handlecommand(char *cmd)
{
	char *cmd_dup = NULL, *token = NULL, *delim = " \n", **argv = NULL;
	int argc = 0, i = 0;
	extern char **environ;

	cmd_dup = strdup(cmd);
	token = strtok(cmd, delim);
	while (token)
	{
		token = strtok(NULL, delim);
		argc++;
	}
	argv = malloc(sizeof(char *) * argc);
	token = strtok(cmd_dup, delim);
	while (token)
	{
		argv[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	argv[i] = NULL;
	if (_strcmp("exit", argv[0]) == 0)
	{
		exit(EXIT_SUCCESS);
	}
	else if (_strcmp("env", argv[0]) == 0)
	{
		printf("%s\n", *environ);
	}
	else if (access(argv[0], X_OK) == 0)
	{
		executecommand(argv, environ);
	}
	else
	{
		printf("No such file or directory\n");
	}
	free(cmd), free(argv);

	return (0);
}

int executecommand(char **argv, char **environ)
{
	int status;

	if (fork() == 0)
	{
		execve(argv[0], argv, environ);
		printf("$ ");
	}
	else
	{
		wait(&status);
	}

	return (0);
}