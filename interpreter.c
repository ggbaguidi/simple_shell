#include "shell.h"

/**
 * handle_signal - just catch the signal
 * Cette fonction est utilisée pour le Crtl + C afin d'arreter
 * l'interpreteur
 * @signal: int type
 * Return: None (SUCCESS)
 */

void handle_signal(int signal)
{
}

/**
 * interpreter - UNIX command line interpreter
 * @argc: the number of arguments of command line(argc donne
 * le nombre d'éléments de la ligne de commande)
 * @argv: the array of string(argv contient ces éléments sous
 * la forme d'un tableau de chaînes de caractères)
 * Return: None (SUCCESS)
 */
void interpreter(int argc, char *argv[])
{
	char *filename = malloc(sizeof(char));
	char *environ[] = { NULL };

	signal(SIGINT, handle_signal);

	while (1)
	{
		printf("#cisfun$ ");
		scanf("%s", filename);
		if (execve(filename, argv, environ) == -1)
		{
			perror(argv[0]);
			exit(EXIT_FAILURE);
		}

	}
	free(filename);
}
