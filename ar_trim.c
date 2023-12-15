#include "main.h"
/**
 * ar_trim - trim a string
 * @str: input string array
 * @n: input string length
 */
void ar_trim(char str[], int *n)
{
	int i, pos = -1;

	for (i = 0; i < *n && (str[i] == ' ' || str[i] == '\t'); i++)
		pos = i;
	if (i == *n)
	{
		str[0] = '\0';
		*n = 0;
		return;
	}
	if (pos > -1)
	{
		for (i = 0; i < *n - pos - 1; i++)
		{
			str[i] = str[pos + i + 1];
		}
		*n = *n - pos - 1;
	}
	str[*n] = '\0';
	pos = *n;
	for (i = *n - 1; i > 0 && (str[i] == ' ' || str[i] == '\t'); i--)
		pos = i;
	str[pos] = '\0';
	*n = pos;
}
