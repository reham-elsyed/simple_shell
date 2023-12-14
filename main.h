#ifndef MAIN_H
#define MAIN_H
#define LINE_SIZE 1024
#define EXIT_CODE 3040
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
extern char **environ;
/**
 * struct op - operation structure
 * @name: operation name
 * @op: operation method
 * LONGER DISCRIPTION
 */
struct op
{
	char *name;
	int (*op)(char **);
};
/**
 * op_t - operation type
 */
typedef struct op op_t;
int ar_atoi(const char *);
int ar_putcerr(char);
int ar_putserr(const char *);
int ar_putn(int);
int ar_getline(char *, int);
int ar_putchar(char);
int ar_puts(char *);
int ar_strcmp(const char *, const char *);
int ar_env(char **);
int ar_execvp(char **);
int ar_exit(char **);
int ar_execute(char **);
char *ar_getpath(const char *);
char *ar_strcat(char *, const char *);
char *ar_strtok(char *, const char *);
char **ar_split(const char *, const char *);
char *ar_strdub(const char *);
int ar_strlen(const char *);
int ar_execve(const char *, char *const [], char *const []);
#endif
