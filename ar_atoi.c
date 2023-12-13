#include "main.h"
/**
 * ar_atoi - string to integer
 * @str: input string
 * Return: integer
 */
int ar_atoi(const char *str)
{
	int sign = 1, result = 0;

	while (*str != '\0')
	{
		if (*str == '-')
			sign = -1;
		else if (*str >= '0' && *str <= '9')
			result = result * 10 + *str - '0';
		else if (result > 0)
			break;
		str++;
	}
	return (sign * result);
}
