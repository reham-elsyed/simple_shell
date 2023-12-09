#include "main.h"
/**
 * ar_strlen - get length of a string
 * @str: input string
 * Return: length of string
 */
int ar_strlen(const char *str)
{
	int len;

	for (len = 0; str[len] != '\0'; len++)
		;
	return (len);
}
