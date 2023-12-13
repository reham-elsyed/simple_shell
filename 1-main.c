#include "main.h"
/**
 * ar_line - get line
 * @line: input line pointer
 * @fd: input file discriptor
 * Return: arg vector
 */
int ar_line(char line[], int fd)
{
	int chars_read, i;

	chars_read = ar_getline(line, fd);
	if (chars_read < 0)
	{
		return (-1);
	}
	for (i = 0; i < chars_read; i++)
		if (line[i] == '\n')
		{
			chars_read = i;
			line[i] = '\0';
		}
	if (chars_read == 0)
		return (0);
	return (1);
}
/**
 * main - main
 * @av: args vector
 * @ac: input ac
 * Return: 0
 */
int main(int ac, char *av[])
{
	char *prompt = "ar$ ";
	int i, status, fd = 0, counter = 0;
	char line[LINE_SIZE], *sep = " ", **argv = NULL;
	int chars_read;

	if (ac == 2)
		fd = open(av[1], O_RDONLY);
	while (1)
	{
		counter++;
		if (!fd && isatty(0))
			ar_puts(prompt);
		chars_read = ar_line(line, fd);
		if (chars_read == -1)
			return (-1);
		if (chars_read == 0)
			continue;
		argv = ar_split(line, sep);
		if (argv == NULL)
			return (-1);
		status = ar_execute(argv);
		if (status == -1)
		{
			ar_putserr(av[0]);
			ar_putserr(": ");
			ar_putn(counter);
			ar_putserr(": ");
			ar_putserr(argv[0]);
			ar_putserr(": not found\n");
		}
		for (i = 0; argv[i] != NULL; i++)
			free(argv[i]);
		free(argv);
	}
	return (0);
}
