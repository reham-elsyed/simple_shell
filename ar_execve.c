#include "main.h"
/**
 * ar_execve - function to execute command
 * @pathname: input pathname
 * @argv: argument vector
 * @envp: input environ
 * Return: fail or success
 */
int ar_execve(const char *pathname, char *const argv[], char *const envp[])
{
	int status, exit_status;
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		execve(pathname, argv, envp);
		exit(errno);
	}
	else if (pid > 0)
	{
		if (wait(&status) == -1)
		{
			perror("wait error");
			return (-1);
		}
		if (WIFEXITED(status))
		{
			exit_status = WEXITSTATUS(status);
			return (exit_status);

		}
	}
	else
	{
		perror("fork error");
		return (-1);
	}
	return (0);
}
