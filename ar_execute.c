#include "main.h"
/**
 * ar_ispath - check is path
 * @str: input string
 * Return: is path or not
 */
int ar_ispath(const char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		if (str[i] == '/')
			return (1);
	return (0);
}
/**
 * ar_execute - execute function
 * @av: input argument vector
 * Return: status
 */
int ar_execute(char **av)
{
	op_t ops[] = {
		{"exit", ar_exit},
		{"env", ar_env},
		{NULL, NULL}
	};
	int i;

	if (av == NULL)
		return (-1);
	if (ar_ispath(av[0]))
	{
		return (ar_execve(av[0], av, environ));
	}
	else
	{
		for (i = 0; ops[i].name != NULL; i++)
			if (ar_strcmp(ops[i].name, av[0]) == 0)
				return (ops[i].op(av));
		return (ar_execvp(av));
	}
	return (1);
}
/**
 * ar_execvp - execute using path
 * @av: input argment vecter
 * Return: status
 */
int ar_execvp(char **av)
{
	char *filename;
	int state;

	filename = ar_getpath(av[0]);
	if (filename == NULL)
		return (-1);
	state = ar_execve(filename, av, environ);
	free(filename);
	return (state);
}
