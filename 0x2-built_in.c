#include "main.h"












my_build array[] =
        {
                {"exit", my_exit},
		{"env", my_env},
        };


void my_exit(char **args)
{
	exit(0);
}


void my_env(char **args)
{
	int i;
	char **env;

	for (i = 0; env[i] != NULL; i++)
	{
		printf("%s\n", env[i]);
	}
}

int num_builtin()
{
	return (sizeof(array) / sizeof(my_build));
}
