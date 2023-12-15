#include "main.h"
/**
 * ar_putn - print num
 * @num: input string
 * Return: number of printed characters
 */
int ar_putn(int num)
{
	int rem, state;

	if (num == 0)
		return (0);
	rem = num % 10;
	state = ar_putn(num / 10);
	return (state + ar_putcerr('0' + rem));
}
