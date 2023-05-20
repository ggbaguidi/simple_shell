#include "shell.h"


/**
 * execvpe - execute the entered command
 *
 * @file: location of command(absolute, relative)
 * @argv: a command arguments
 * @envp: a environ
 * Return: int (SUCCESS 0)
 */

int execvpe(char *file, char *argv[], char *envp[])
{
	const char *p, *z, *path = PATH;
	size_t l, k;

	if (!*file)
		return (-1);
	if (strchr(file, '/'))
		return (execve(file, argv, envp));
	if (!path)
		path = "/usr/local/bin:/bin:/usr/bin";
	k = strnlen(file, NAME_MAX + 1);
	if (k > NAME_MAX)
	{
		return (-1);
	}
	l = strnlen(path, PATH_MAX - 1) + 1;
	for (p = path;; p = z)
	{
		char *b = malloc(sizeof(char) * (l + k + 1));

		z = strchr(p, ':');
		if ((z - p) >= (long int)l)
		{
			if (!*z++)
				break;
			continue;
		}
		memcpy(b, p, z - p);
		b[z - p] = '/';
		memcpy(b + (z - p) + (z > p), file, k + 1);
		execve(b, argv, envp);
		if (!*z++)
		{
			printf("break\n");
			break;
		}
	}
	printf("Sorti !!\n");
	return (-1);
}
