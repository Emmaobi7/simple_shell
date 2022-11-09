#include "main.h"













int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	return (*s1- *s2);
}




char *my_strcat(char *dest, char *src)
{
        int i = 0;
        int j = 0;
        int k;

        while(dest[i] != '\0')
        {
                i++;
        }

        while (src[j] != '\0')
        {
                j++;
        }

        for (k = 0; k <= j; k++)
        {
                dest[i + k] = src[k];
        }

        return (dest);
}
