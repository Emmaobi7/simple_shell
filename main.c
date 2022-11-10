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
			builtin_check(cmd[0]);
			my_execute(cmd);
		}
	}
	return (0);
}
