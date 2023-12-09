#include "main.h"
/**
 * ar_putserr - print error string
 * @str: input string
 * Return: number of printed characters
 */
int ar_putserr(const char *str)
{
	int i, count = 0;

	for (i = 0; str[i] != '\0'; i++)
		count += ar_putcerr(str[i]);
	return (count);
}
