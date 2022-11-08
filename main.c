#include "main.h"



















int main(int argc, char *argv[])
{

	char *str;
	char **cmd;

	(void) argc;

	while (1)
	{
		printf("($)" );
		str = my_readline();
		cmd = my_token(str);
		if (cmd != NULL)
		{
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
		}
	}

	return (0);
}
