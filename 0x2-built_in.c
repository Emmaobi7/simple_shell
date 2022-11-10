#include "main.h"













int my_exit()
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

