#include "main.h"


int env(void)
{
/*	extern char **environ;*/
	int line;

	for (line = 0; environ[line] != NULL; line++)
		printf("%s\n", environ[line]);
	return (0);
}
/**
 * exitshell - Leave shell
 * Return: void
 */
int exitshell(void)
{
	exit(EXIT_SUCCESS);
}



int builtin(char *s)
{
	int i = 0;

	cmnd_t comms[] = {
		{"env", printenv},		/*{arg, func},*/
		{"exit", exitshell},
		{NULL, NULL}
	};

	while (comms[i].arg != NULL) /*Loops through struct until NULL*/
	{
		if (_strcmp(comms[i].arg, s) == 0
				&& (_strlen(comms[i].arg) == _strlen(s)))
			return (comms[i].func());
		i++;
	}
	return (1); /*If no match return 1*/
}
