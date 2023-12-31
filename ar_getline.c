#include "main.h"
/**
 * ar_getline - get line function to get prompt from user
 * @line: line pointer
 * @fd: input file discriptor
 * Return: number of character that has been read
 */
int ar_getline(char *line, int fd)
{
	int sum = 0, current, i, err_num = errno;

	if (fd > 1 || !isatty(0))
	{
		errno = err_num;
		for (i = 0; i < LINE_SIZE; i++)
		{
			current = read(fd, line + i, 1);
			if (current == 0)
				exit(errno);
			if (line[i] == '\n' || line[i] == EOF)
				break;
			sum += current;
		}
		line[i] = '\0';
		return (sum);
	}
	sum = read(fd, line, LINE_SIZE);
	if (sum == 0)
		return (-1);
	return (sum);
}
