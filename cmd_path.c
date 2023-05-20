#include "shell.h"

/**
 * _getenv - get a environment variable
 *
 * Return: a array of all (SUCCESS)
 */

char *_getenv(void)
{
	char **env = ENVIRON;
	char *dirs = NULL;

	while (*env != NULL)
	{
		if (strncmp(*env, "PATH=", 5) == 0)
		{
			dirs = *env + 5;
		/*	strcat(dirs, ":");*/
			break;
		}
		env++;
	}
	return (dirs);
}

/**
 * count_dir - return the number of dir contained in path
 *
 *
 * Return: a int (SUCCESS)
 */

int count_dir(void)
{
	char *path = PATH;
	char *dir = strtok(path, ":");
	int cpt = 0;

	while (dir != NULL)
	{
		cpt++;
		dir = strtok(NULL, ":");
	}
	return (cpt);
}
