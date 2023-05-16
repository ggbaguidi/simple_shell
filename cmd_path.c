#include "shell.h"

/**
 * _getenv - get a environment variable
 *
 * Return: a array of all (SUCCESS)
 */

char **_getenv(void)
{
	char **env = ENVIRON;
	char **dirs = NULL;

	while (*env != NULL)
	{
		if (strncmp(*env, "PATH=", 5) == 0)
		{
			dirs = split(*env + 5, ":");
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
	char **dirs = PATH;
	char *full_path = NULL;
	size_t len_path = 0;
	char *tmp_path = NULL;
	struct stat st;

	if (strstr(cmd, "/") != NULL)
	{
		if ((access(cmd, X_OK) == 0) && (stat(cmd, &st) == 0) && S_ISREG(st.st_mode))
		{
			full_path = cmd;
		}
	}
	else
	{
		while (*dirs != NULL)
		{
			len_path = strlen(*dirs) + strlen(cmd) + 2;
			tmp_path = malloc(sizeof(char) * len_path);
			snprintf(tmp_path, len_path, "%s/%s", *dirs, cmd);
			if ((access(tmp_path, X_OK) != -1) && (stat(tmp_path, &st) == 0) && S_ISREG(st.st_mode))
			{
				printf("OK\n");
				full_path = tmp_path;
				break;
			}
			dirs++;
			if (full_path == NULL)
				free(tmp_path);
		}
	}
	return (full_path);
}
