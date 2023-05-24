#include"shell.h"
/**
 * noninteractive_pipes_handler - processes shell commands with pipes
 * Return: pointer to char array with output
 */
char **noninteractive_pipes_handler()
{
	char c[2048], *text_read, **command_lines;
	size_t total_characters_read = 0;
	ssize_t bytes_read;
	int i, flags;

	flags = 0;
	command_lines = NULL;
	text_read = NULL;
	while ((bytes_read = read(STDIN_FILENO, c, 2048)) > 0)
	{
		total_characters_read = total_characters_read + bytes_read;
	}
	if (bytes_read == -1)
	{
		perror("reading error");
		exit(ERROR);
	}
	if (total_characters_read > 2048)
		c[2048 - 1] = '\0';
	else
		c[total_characters_read - 1] = '\0';

	for (i = 0; c[i]; i++)
	{
		if (c[i] != ' ')
			flags = 1;
	}
	if (flags == 0)
		return (NULL);
	total_characters_read = _strlen(c);
	text_read = (char *)malloc(sizeof(char) * (total_characters_read));
	if (text_read != NULL)
	{
		_strcpy(text_read, c);
		text_read[total_characters_read] = '\0';
		command_lines = text_to_array(text_read);
	}
	return (command_lines);
}
