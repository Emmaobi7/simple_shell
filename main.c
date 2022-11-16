<<<<<<< HEAD
#include "shell.h"

/**
 * main - entry point
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **av)
{
	info_t info[] = { INFO_INIT };
	int fd = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fd)
		: "r" (fd));

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(av[0]);
				_eputs(": 0: Can't open ");
				_eputs(av[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = fd;
	}
	populate_env_list(info);
	read_history(info);
	hsh(info, av);
	return (EXIT_SUCCESS);
=======
#include "main.h"



int main(void)
{
	char *argv[5], *token, *buffer;
	pid_t child;
	int status, x = 0;

	signal(SIGINT, _sigign);
	while (1)
	{
		argv[0] = NULL, buffer = NULL, token = NULL, x = 0;
		buffer = getinput();
		token = strtok(buffer, DELIM);
		do {
			argv[x] = _strdup(token);
			x++;
			token = strtok(NULL, DELIM);
		} while (token != NULL);
		argv[x] = NULL;
		if (argv != NULL && argv[0] != NULL)
		{
			builtin(argv[0]);
			argv[0] = findpath(argv[0]);
			child = fork();
			if (child < 0)
				perror("Error");
			if (child == 0)
			{
				if (execve(argv[0], argv, NULL) == -1)
				{
					perror("Error");
					exit(1);
				}
			}
			wait(&status);
		}
		free(buffer);
		free(token);
	}
	free(buffer);
	return (0);
>>>>>>> d9799d7f47ddca088ce3f575c54978517dac05ec
}
