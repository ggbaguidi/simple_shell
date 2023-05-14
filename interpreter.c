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
	char *args[] = { NULL, NULL };
	char cmd[1024];
	char *env[] = { NULL };

	while (argc || 1)
	{
		printf("#cisfun$ ");
		fflush(stdout);
		if (fgets(cmd, sizeof(cmd), stdin) != NULL)
		{
			cmd[strcspn(cmd, "\n")] = '\0';
			args[0] = cmd;
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

	}
}
