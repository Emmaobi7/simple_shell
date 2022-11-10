#include "main.h"












<<<<<<< HEAD
my_build array[] =
        {
                {"exit", my_exit},
		{"env", my_env},
        };
*

void my_exit(char **args)
=======

int my_exit()
>>>>>>> 6ede9c54230eadf7d7a2f267f7c7dd7fdd88c0c3
{
	exit(0);
}


int my_env()
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
	return (0);
}
/*
int num_builtin()
{
	my_build array[] =                                        {                                                         {"exit", my_exit},                                {"env", my_env},                                  {NULL, NULL}                              };
	return (sizeof(array) / sizeof(my_build));
}
*/


int builtin_check(char *a)
{
	my_build array[] =
                {                                                         {"exit", my_exit},
                        {"env", my_env},
                        {NULL, NULL}                              };
	int i;
	
	i = 0;
	while (array[i].name != NULL)
	{
		if (_strcmp(array[i].name, a) == 0 && (strlen(array[i].name) == strlen(a)))
		{
			return (array[i].func());
		}
		i++;
	}
	
	return (1);
}

