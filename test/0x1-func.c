#include "main.h"



/*
size_t _getline(char **string, size_t *n, FILE *stream)
{
	char *ptr;
	unsigned int len;
	char array[256];

	if (stream == NULL)
	{
		return (-1);
	}
	
	if (string == NULL || n == NULL)
	{
		return (-1);
	}

	if (ferror(stream))
	{
		return (-1);
	}
	
	if (feof(stream))
	{
		return (-1);
	}


	fgets(array,256,stream);

	ptr = _strchr(array, '\n');
	if (ptr)
	{
		*ptr = '\0';
	}


	len = _strlen(array);

	if ((len + 1) < 256)
	{
		ptr = realloc(*string, 256);
		if (ptr == NULL)
		{
			return (-1);
		}
		*string = ptr;
		*n = 256;
	}
	strcpy(*string, array);
	return (len);
}

*/


/*
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


	buf_size = 64;
	space = malloc(buf_size * sizeof(char *));

	if (space == NULL)
	{
		fprintf(stderr, "allocatio f\n");
		exit(1);
	}

	store = my_strtok(buf, DELIM);

	index = 0;
	while (store != NULL)
	{
		space[index] = store;
		index++;
		if (index > buf_size)
		{
			space += buf_size;
			space = realloc(space, buf_size * sizeof(char *));
			if (space == NULL)
			{
				fprintf(stderr, "allocation failed \n");
				exit(1);
			}
		}

		store = strtok(NULL, DELIM);
	}
	space[index] = NULL;

	return (space);
}
*/






char *getinput(void)
{
	char *buffer;
	int check;
	size_t length = 1;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	buffer = malloc(sizeof(char) * length);
	if (buffer == NULL)
	{
		perror("Error");
	}
	while (1)
	{
		check = getline(&buffer, &length, stdin);
		if (check == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(EXIT_SUCCESS);
		}
		return (buffer);
	}
	perror("Error");
}

char *findpath(char *name)
{
	const char *path = "PATH";
	char *value, *token;
	char *dir[8];
	struct stat statbuff;
	int num = 0;

	value = _getenv(path);
	token = strtok(value, DELIM);
	do {
		dir[num] = NULL;
		dir[num] = _strdup(token);
		dir[num] = strcat(dir[num], name);
		if (name[0] == '/')
			break;
		if (_strcmp(name, "./") == 0)
			break;
		if (stat(dir[num], &statbuff) == 0)
		{
			free(value);
			return (dir[num]);
		}
		else
			num++;
		token = strtok(NULL, DELIM);
	} while (token != NULL);
	free(dir[num]);
	free(value);
	return (name);
}
