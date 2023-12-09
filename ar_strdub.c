#include "main.h"
/**
 * ar_strdub - string dublicate
 * @str: input string
 * Return: duplicate pointer
 */
char *ar_strdub(const char *str)
{
	int str_len = ar_strlen(str);
	int i;
	char *str_dub = malloc(sizeof(char) * (str_len + 1));

	if (str_dub == NULL)
	{
		free(str_dub);
		perror("string dublicate error");
		return (NULL);
	}
	for (i = 0; i < str_len; i++)
		str_dub[i] = str[i];
	str_dub[i] = '\0';
	return (str_dub);
}
