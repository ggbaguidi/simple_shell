#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;
#define ENVIRON environ
#define PATH _getenv()
void prompt(const char *str);
void interpreter(int argc, char *argv[]);
char **split(char *str, const char *delim);
char **_getenv(void);
char *cmd_path(char *cmd);
#endif
