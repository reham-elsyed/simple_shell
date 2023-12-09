#include "main.h"
#include <fcntl.h>
/**
 * ar_getpath - get path from operation
 * @op: input operation
 * Return: pathname
 */
char *ar_getpath(const char *op)
{
	char *path = getenv("PATH");
	char *sep = ":", *result;
	char **paths = ar_split(path, sep);
/**	struct stat stats;**/
	int i, j, result_len, fd;

	if (paths == NULL)
		return (NULL);
	for (i = 0; paths[i] != NULL; i++)
	{
		result_len = ar_strlen(op) + 2 + ar_strlen(paths[i]);
		result = malloc(sizeof(char) * result_len);
		if (result == NULL)
		{
			perror("get path error");
			return (NULL);
		}
		for (j = 0; j < result_len; j++)
			result[j] = '\0';
		ar_strcat(result, paths[i]);
		ar_strcat(result, "/");
		ar_strcat(result, op);
		fd = open(result, O_RDONLY);
		if (fd != -1)
		{
			close(fd);
			for (; paths[i] != NULL; i++)
				free(paths[i]);
			free(paths);
			return (result);
		}
		free(paths[i]);
		free(result);
	}
	free(paths);
	return (NULL);
}
