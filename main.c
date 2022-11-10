#include "main.h"



















int main(int argc, char *argv[], char *envp[])
{

	char *str;
	char **cmd;
	int i, status;

	(void) argc;


	while (1)
	{
		printf("($)" );
		str = my_readline();
		cmd = my_token(str);
		if (cmd != NULL && cmd[0] != NULL)
		{
			builtin_check(cmd[0]);

			pid_t pid = fork();
			pid_t val;

			if (pid == -1)
			{
				perror("Error forking");
				exit(1);
			}

			if (pid == 0)
			{
				val = execve(cmd[0], cmd, environ);
				if (val == -1)
				{
					perror(argv[0]);
					exit(1);
				}
			}
			else
			{
				wait(&status);
			}
		}
	}
	return (0);
}
