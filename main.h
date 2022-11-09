#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>






typedef struct builtin
{
	char *name;
	void (*func) (char **args);
}my_build;

char *my_readline();
void my_execute(char **args);
char **my_token(char *buf);
char *my_strcat(char *dest, char *src);
extern char **environ;
void my_exit(char **args);
int num_builtin();
int _strcmp(char *s1, char *s2);
void my_env(char **args);
#endif 
