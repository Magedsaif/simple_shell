#include "shell.h"
/**
 * line_to_vector - converts a string into an array of strings
 * @command: the string to convert
 * @status: an integer representing the status of the command
 * Return: a pointer to a char array.
 */
char **line_to_vector(char *command, int status)
{
	char *command_copied;
	int characters_count;
	char **argument_vector;

	command_copied = _strdup(command);
	if (command_copied == NULL)
		return (NULL);

	characters_count = char_count(command_copied, ' ');
	argument_vector = allocate_vector(characters_count);

	if (argument_vector == NULL)
	{
		free(command_copied);
		return (NULL);
	}

	if (!tokenize_command(command, status, argument_vector))
	{
		free(argument_vector);
		return (NULL);
	}
	return (argument_vector);

}
