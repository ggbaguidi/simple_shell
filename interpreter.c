#include "shell.h"

/**
 * handle_signal - Just catch the signal SIGNINT when a user click on
 * Crtl+C
 * @s: the signal type int
 * Return: None (SUCCESS)
 */
void handle_signal(int s)
{
	putchar('\n');
	exit(EXIT_SUCCESS || ~s);
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
	int status = 0;

	signal(SIGINT, handle_signal);
	while (argc || 1)
	{
		pid_t p = fork();

		if (p == 0)
		{
			printf("#cisfun$ ");
			scanf("%s", filename);
			if (execve(filename, argv, environ) == -1)
				perror(argv[0]);
		}
		else if (p > 0)
			waitpid(p, &status, 0);
		else
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}

		if (feof(stdin))
		{
			putchar('\n');
			break;
		}

	}
	free(filename);
}
