#include "shell.h"

int shell(void)
{
	char *cmd = NULL, *token = NULL;
	char *delim = " \n";
	size_t n = 0;
	int argc = 0, i = 0;
	char **argv = NULL;
    char *cmdpath = NULL;

    /* taking input */
	printf("$ ");
	if (getline(&cmd, &n, stdin) == -1)
		return (-1);

    /* tokenizing input to count argc */ 
	token = strtok(cmd, delim);

    /* counting argc */
	while (token)
	{
		token = strtok(NULL, delim);
		argc++;
	}

    printf("NUMBER OF ARGUMENTS: %d\n", argc);

    /* assigning memory of size argc to argv */
	argv = malloc(sizeof(char *) * argc - 1);

    /* tokenizing input to assign values to argv */ 
	token = strtok(cmd, delim);

    /* assigning values to argv */
	while (token)
	{
		argv[i] = token;
		token = strtok(NULL, delim);
        printf("ARGUMENT INDEX IS: %d\n", i);
        printf("ARGUMENT VALUE IS: %s\n", argv[i]);
		i++;
        printf("AFTER WHILE I = %d\n", i);
	}

    /* ending argv array */ 
	argv[i] = NULL;

    /* executing command with arguments in environment */ 
    execve(argv[0], argv, __environ);

    /* freeing used resources */ 
	free(cmd), free(argv); free(cmdpath);

    /* finish */ 
	return (0);
}
