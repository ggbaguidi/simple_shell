#include "shell.h"

/**
 * is_exist - .....
 *
 * @file: location of command(absolute, relative)
 * Return: a char pointer (FAIL NULL)
 */

char *is_exist(char *file)
{
	const char *p, *path = PATH;
	char *b;
	size_t l, k;

	if (!*file)
		return (NULL);
	if (strchr(file, '/'))
		return (file);
	if (!path)
		path = "/usr/local/bin:/bin:/usr/bin";
	k = strnlen(file, NAME_MAX + 1);
	if (k > NAME_MAX)
	{
		return (NULL);
	}
	l = strnlen(path, PATH_MAX - 1) + 1;
	for (p = path; *p != '\0'; p++)
	{
		if (*p == ':')
			continue;
		l = strcspn(p, ":");

		if (l >= PATH_MAX)
			continue;
		b = malloc(l + k + 2);
		if (!b)
			break;
		memcpy(b, p, l);
		b[l] = '/';
		memcpy(b + l + 1, file, k + 1);

		if (access(b, X_OK) != -1)
			return (b);
		free(b);
		p += l;
	}
	return ("none");
}
