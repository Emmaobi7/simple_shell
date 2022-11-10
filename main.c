#include "main.h"



















int main(int argc, char *argv[], char *envp[])
{

	char *str;
	char **cmd;
	int i;

	(void) argc;


	while (1)
	{
		printf("($)" );
		str = my_readline();
		cmd = my_token(str);
		if (cmd != NULL && cmd[0] != NULL)
		{
<<<<<<< HEAD
			for (i = 0; i < num_builtin(); i++)
			{
				if (strcmp(cmd[0], array[i].name) == 0)
				{
					array[i].func(cmd);
				}
			}
			pid_t pid = fork();
        int val;

        if (pid == -1)
        {
                perror("Error forking");                          exit(1);
        }

        if (pid == 0)
        {

                val = execve(cmd[0], cmd, NULL);
                if (val == -1)
                {
                        perror(argv[0]);
                        exit(1);
                }
        }
        else
        {
                wait(NULL);
        }
=======
			builtin_check(cmd[0]);
			my_execute(cmd);
>>>>>>> 6ede9c54230eadf7d7a2f267f7c7dd7fdd88c0c3
		}
	}
	return (0);
}
