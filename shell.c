#include "shell.h"

int shell(void)
{
	char *cmd = NULL, *cmd_dup = NULL, *token = NULL;
	char *delim = " \n";
	size_t n = 0;
	int argc = 0, i = 0;
	char **argv = NULL;


    /* taking input */
	printf("$ ");


	if (getline(&cmd, &n, stdin) == -1)
    {
        free(cmd);
		return (-1);
    }
   
    cmd_dup = strdup(cmd);

    /* tokenizing input to count argc */ 
    token = strtok(cmd, delim);

    /* counting argc */
    while (token)
    {
        token = strtok(NULL, delim);
        argc++;
    }

    /* assigning memory of size argc to argv */
    argv = malloc(sizeof(char *) * argc);

    /* tokenizing input to assign values to argv */ 
    token = strtok(cmd_dup, delim);

    /* assigning values to argv */
    while (token)
    {
        argv[i] = token;
        token = strtok(NULL, delim);
        i++;
    }

    /* ending argv array */ 
    argv[i] = NULL;

    /* executing command with arguments in environment */ 
    

    if (access(argv[0], X_OK) == 0)
    {
        execve(argv[0], argv, __environ);
    }
    else
    {
        printf("Makaynch: No such file or directory");
    }

    


    /* freeing used resources */ 
	free(cmd), free(argv);

    /* finish */ 
	return (0);
}
