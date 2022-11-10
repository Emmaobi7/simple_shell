#include "main.h"










char *my_readline()
{
	char *buffer = NULL;
	size_t size = 0;

	if (getline(&buffer, &size, stdin) == -1)
	{
		if (feof(stdin))
		{
			exit(1);
		}
	}
	return (buffer);
}

char **my_token(char *buf)
{
	char **space;
	int buf_size;
	char *store;
	int index;

	char delim[] = " \t\r\n\a";

	buf_size = 64;
	space = malloc(buf_size * sizeof(char *));

	if (space == NULL)
	{
		fprintf(stderr, "allocatio f\n");
		exit(1);
	}

	store = strtok(buf, delim);

	index = 0;
	while (store != NULL)
	{
		space[index] = store;
		index++;
		if (index > buf_size)
		{
			space = realloc(space, buf_size * sizeof(char *));
			if (space == NULL)
			{
				fprintf(stderr, "allocation failed \n");
				exit(1);
			}
		}

		store = strtok(NULL, delim);
	}
	space[index] = NULL;

	return (space);
}







/*
void my_execute(char **args)
{
	pid_t pid = fork();
	int val;
	

	if (pid == -1)
	{
		perror("Error forking");
		exit(1);
	}

	if (pid == 0)
	{

		val = execve(args[0], args, NULL);
		if (val == -1)
		{
			perror(" ");
			exit(1);
		}
	}
	else
	{
		wait(NULL);
	}
}
*/
