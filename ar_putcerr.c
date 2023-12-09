#include "main.h"
/**
 * ar_putcerr - put character error
 * @c: input character
 * Return: one
 */
int ar_putcerr(char c)
{
	return (write(2, &c, 1));
}
