#include "main.h"
/**
 * ar_puts - puts function
 * @str: input string
 * Return: number of character printed
 */
int ar_puts(char *str)
{
	int len, sum = 0;

	for (len = 0; str[len] != '\0'; len++)
		sum += ar_putchar(str[len]);
	return (sum);
}
