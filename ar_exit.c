#include "main.h"
/**
 * ar_exit - exit function
 * @av: input of av
 * Return: status on success
 */
int ar_exit(char **av)
{
	int i, result;

	if (av[1] == NULL)
		result = errno;
	else
		result = ar_atoi(av[1]);
	for (i = 0; av[i] != NULL; i++)
		free(av[i]);
	free(av);
	exit(result);
	return (-1);
}
