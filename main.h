#ifndef MAIN_H
#define MAIN_H
#define FLAG 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>






typedef struct builtin
{
	char *name;
	int (*func) (void);
}my_build;

char *my_readline();
void my_execute(char **args);
char **my_token(char *buf);
char *my_strcat(char *dest, char *src);
extern char **environ;
int my_exit();
int num_builtin();
int _strcmp(char *s1, char *s2);
int my_env();
int builtin_check(char *a);
int _strlen(char *s);
#endif 
