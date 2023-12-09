#include "main.h"
/**
 * ar_putchar - putchar
 * @c: input character
 * Return: numer of written character
 */
int ar_putchar(char c)
{
	return (write(1, &c, 1));
}
