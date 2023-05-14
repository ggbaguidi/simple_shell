#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <signal.h>
#include <sys/wait.h>

void prompt(const char *str);
void interpreter(int argc, char *argv[]);
char **split(char *str, const char *delim);

#endif
