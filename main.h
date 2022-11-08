#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>







char *my_readline();
void my_execute(char **args);
char **my_token(char *buf);
char *my_strcat(char *dest, char *src);
extern char **environ;
#endif 
