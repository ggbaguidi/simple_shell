#include "shell.h"

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

	while (argc || 1)
	{
		printf("#cisfun$ ");
		scanf("%s", filename);
		if (execve(filename, argv, environ) == -1)
			perror(argv[0]);
		if (feof(stdin))
		{
			putchar('\n');
			break;
		}

	}
	free(filename);
}
