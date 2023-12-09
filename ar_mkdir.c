#include "main.h"
/**
 * ar_mkdir - mkdir function
 * @av: input av
 * Return: status
 */
int ar_mkdir(char **av)
{
	if (av[1] == NULL)
	{
		errno = 2;
		perror(av[0]);
	}
	return (1);
}
