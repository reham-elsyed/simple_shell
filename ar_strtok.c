#include "main.h"
/**
 * ar_strtok - make tokens from string
 * @str: input string
 * @delim: input delim
 * Return: current token
 */
char *ar_strtok(char *str, const char *delim)
{
	static char *s = NULL;
	char *start = NULL;

	if (str == NULL)
	{
		str = s;
		if (s == NULL)
		{
			return (NULL);
		}
	}
	start = str;
	while (*str != '\0' && *str == *delim)
	{
		str++;
	}
		if (*str == '\0')
		{
			s = NULL;
			return (NULL);
		}
		while (*str != '\0' && *str != *delim)
		{
			str++;
		}
		if (*str != '\0')
		{
			*str = '\0';
			s = str + 1;
		}
		else
		{
			s = NULL;
		}
		return (start);
}
