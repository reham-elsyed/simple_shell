#include "main.h"
/**
 * ar_env - env function
 * @av: input av
 * Return: status
 */
int ar_env(char **av)
{
	int i;

	if (av[1] == NULL)
		i = 0;
	for (i = 0; environ[i] != NULL; i++)
	{
		ar_puts(environ[i]);
		ar_putchar('\n');
	}
	return (0);
}
