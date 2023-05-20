#include "shell.h"

/**
 * interpreter - UNIX command line interpreter
 *
 * SIMPLE SHELL 0.1
 *
 * @argc: the number of arguments of command line(argc donne
 * le nombre d'éléments de la ligne de commande)
 * @argv: the array of string(argv contient ces éléments sous
 * la forme d'un tableau de chaînes de caractères)
 * Return: None (SUCCESS)
 */
void interpreter(int argc, char *argv[])
{
	char **args = NULL;
	char *cmd = malloc(sizeof(char)), *envp[] = { NULL }, *tmp = NULL;
/*	size_t len = 0;*/
	pid_t pid = 1;
	int status;

	while (argc || 1)
	{
		prompt("#cisfun$");
		cmd = my_getline();
		if (cmd != NULL)
		{
			if (external_func(cmd) == 0)
				continue;
			cmd[strcspn(cmd, "\n")] = '\0';
			args = split(cmd, " ");
			tmp = is_exist(args[0]);
			if (strcmp(tmp, "none") != 0)
			{
				pid = fork();
				args[0] = tmp;
				if (pid == 0)
				{
					if (execve(args[0], args, envp) == -1)
					{
						perror(argv[0]);
						exit(EXIT_FAILURE);
					}
				}
				else
					waitpid(pid, &status, 0);
			}
			else
				exit(EXIT_FAILURE);
		}
		else
			exit(EXIT_FAILURE);
	}
	free(cmd);
}

/**
 * split - divide a string in tokens(divise une chaine de caracteres
 * mots(tokens)
 * @str: a string a char pointer
 * @delim: a delimiter a char pointer
 * Return: a pointer of pointer of char
 */

char **split(char *str, const char *delim)
{
	char **tokens = malloc(sizeof(char *));
	char *token = strtok(str, delim);
	int count = 0;

	while (token != NULL)
	{
		count++;
		tokens = realloc(tokens, sizeof(char *) * count);
		tokens[count - 1] = token;
		token = strtok(NULL, delim);
	}
	tokens = realloc(tokens, sizeof(char *) * (count + 1));
	tokens[count] = NULL;

	return (tokens);
}

/**
 * external_func - ....
 * @cmd: ....
 * Return: ...
 */

int external_func(char const *cmd)
{
	char *c = malloc(sizeof(char));

	strcpy(c, cmd);
	if (strcmp(c, "\n") == 0)
		exit(EXIT_FAILURE);
	c[strcspn(c, "\n")] = '\0';
	if (strcmp(c, "exit") == 0)
		exit_shell();
	if (strcmp(c, "env") == 0)
	{
		print_env();
		free(c);
		return (0);
	}
	return (-1);
}

