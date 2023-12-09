#include "main.h"
/**
 * ar_get_tok_num - get token number
 * @str: input string
 * @sep: input seperator
 * Return: number of tokens
 */
int ar_get_tok_num(const char *str, const char *sep)
{
	int token_num = 0;
	char *token, *str_cpy;

	str_cpy = ar_strdub(str);
	if (str_cpy == NULL)
		return (-1);
	token = ar_strtok(str_cpy, sep);
	while (token != NULL)
	{
		token_num++;
		token = ar_strtok(NULL, sep);
	}
	free(str_cpy);
	return (token_num);
}
/**
 * ar_split - string splitter
 * @str: input string
 * @sep: input seperator
 * Return: array of splitted strings
 */
char **ar_split(const char *str, const char *sep)
{
	int i, token_num = 0;
	char **result, *token, *str_cpy;

	token_num = ar_get_tok_num(str, sep);
	if (token_num == -1)
		return (NULL);
	result = malloc(sizeof(char *) * (token_num + 1));
	if (result == NULL)
	{
		perror("split error");
		return (NULL);
	}
	str_cpy = ar_strdub(str);
	if (str_cpy == NULL)
	{
		free(result);
		return (NULL);
	}
	token = ar_strtok(str_cpy, sep);
	for (i = 0; token != NULL; i++)
	{
		result[i] = ar_strdub(token);
		if (result[i] == NULL)
		{
			for (i = i - 1; i >= 0; i--)
				free(result[i]);
			free(result);
			return (NULL);
		}
		token = ar_strtok(NULL, sep);
	}
	result[i] = NULL;
	free(str_cpy);
	return (result);
}
