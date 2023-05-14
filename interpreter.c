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
	char *cmd = malloc(sizeof(char));
	char *env[] = { NULL };
	size_t len = 0;

	while (argc || 1)
	{
		prompt("#cisfun$");
		if (getline(&cmd, &len, stdin) != -1)
		{
			cmd[strcspn(cmd, "\n")] = '\0';
			args = split(cmd, " ");
			if (fork() == 0)
			{
				if (execve(args[0], args, env) == -1)
				{
					perror(argv[0]);
					exit(EXIT_FAILURE);
				}
			}
			else
				wait(NULL);
		}
		else
			break;

		free(args);

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
