#include "shell.h"
#include <errno.h>

int shell(void)
{
	char *cmd = NULL, *cmd_dup = NULL, *token = NULL;
	char *delim = " \n";
	size_t n = 0;
	int argc = 0, i = 0, status;
	char **argv = NULL;
    extern char **environ;

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
        printf("cmd: %s\n", cmd);
    
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
        if (_strcmp(argv[0], "exit") == 0)
        {
            exit(0);
        }
        else if (access(argv[0], X_OK) == 0)
        {
            if (fork() == 0)
            {
                execve(argv[0], argv, environ);
                printf("$ ");
            }
            else
            {
                wait(&status);
            }
        }
        else
        {
            printf("No such file or directory\n");
        }

        


        /* freeing used resources */ 
        free(cmd), free(argv);

        /* finish */ 
        return (0);
    }
    else
    {
        return (0);
    }
}