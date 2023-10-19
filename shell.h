#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int shell(void);
void handlecommand(char *cmd);
int executecommand(char **argv, char **environ);
void printenv(char **environ);
char *getcommand(char **argv);

int _strlen(char *msg);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_getpath(char **environ);

#endif
