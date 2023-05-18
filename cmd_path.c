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
			break;
		}
		env++;
	}
	return (dirs);
}

/**
 * cmd_path - return the path of command
 *
 * @cmd: a command executed as a char pointer
 *
 * Return: a char pointer (SUCCESS)
 */

char *cmd_path(char *cmd)
{
	return (cmd);
}
