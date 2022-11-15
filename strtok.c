#include "main.h"














unsigned int is_delim(char c, char *delim)
{
	while (*delim != '\0')
	{
		if (c == *delim)
		{
			return (1);
		}
		delim++;
	}

	return (0);
}


char *my_strtok(char *s, char *delim)
{
	static char *backup;

	if (!s)
	{
		s = backup;
	}

	if (!s)
		return (NULL);
	
	while (1)
	{
		if (is_delim(*s, delim))
		{
			s++;
			continue;
		}
		if (*s == '\0')
		{
			return (NULL);
		}
		break;
	}

	char *ptr = s;
	
	while (1)
	{
		if (*s == '\0')
		{
			backup = s;
			return (ptr);
		}
		if (is_delim(*s, delim))
		{
			*s = '\0';
			backup = s + 1;

			return (ptr);
		}
		s++;
	}
}
