#include "shell.h"

/**
 * my_getline - .....
 *
 * Return: char pointer
 */

char *my_getline(void)
{
	static char buffer[BUFFER_SIZE];
	static size_t buffer_index;
	static ssize_t bytes_read, bytes_left;
	char *line = NULL;
	size_t line_length = 0;
	int reached_end_of_line = 0;
	char current_char;

	while (!reached_end_of_line)
	{
		if (buffer_index >= (unsigned int long)bytes_read)
		{
			bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
			if (bytes_read <= 0)
			{
				if (line_length > 0)
					break;
			}
			bytes_left = bytes_read;
			buffer_index = 0;
		}
		current_char = buffer[buffer_index++];

		bytes_left--;
		if (current_char != '\n')
		{
			line = realloc(line, line_length + 1);
			line[line_length++] = current_char;
		}
		else
			reached_end_of_line = 1;

	}
	if (line != NULL)
	{
		line = realloc(line, line_length + 1);
		line[line_length] = '\0';
	}
	return (line);
}
