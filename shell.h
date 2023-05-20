#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <signal.h>
#include <sys/wait.h>
#include <errno.h>
#include <limits.h>
#include <sys/stat.h>

extern char **environ;
#define ENVIRON environ
#define PATH _getenv()
#define BUFFER_SIZE 256
void prompt(const char *str);
void interpreter(int argc, char *argv[]);
char **split(char *str, const char *delim);
char *_getenv(void);
int count_dir(void);
int execvpe(char *file, char *argv[], char *envp[]);
char *is_exist(char *file);
void exit_shell(void);
int external_func(char const *cmd);
void _printf(char *str);
void print_env(void);
char* my_getline(void);

#endif
