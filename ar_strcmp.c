#include "main.h"
/**
 * ar_strcmp - string compare
 * @s1: first string
 * @s2: second string
 * Return: status
 */
int ar_strcmp(const char *s1, const char *s2)
{
	int i, s1_len = ar_strlen(s1), s2_len = ar_strlen(s2);

	for (i = 0; i < s1_len && i < s2_len; i++)
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	if (i < s1_len || i < s2_len)
		return (s1_len - s2_len);
	return (0);
}
