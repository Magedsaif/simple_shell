#include "shell.h"
/**
 * line_to_vector - converts a string into an array of strings
 * @command: the string to convert
 * @status: an integer representing the status of the command
 * Return: a pointer to a char array.
 */
char **line_to_vector(char *command, int status)
{

	char *command_copied, *token, *cmde, **argument_vector, *variable;
	int i = 0, characters_count;

	/*handle_comments(command);*/
	command_copied = _strdup(command);
	if (command_copied == NULL)
		return (NULL); /*can't cpy*/
	characters_count = char_count(command_copied, ' ');
	argument_vector = malloc((characters_count + 1) * sizeof(char *));
	token = strtok(command_copied, TOK_D);
	if (token == NULL)
	{
		free(argument_vector);
		free(command_copied);
		return (NULL);
	}

	if (_strcmp("$$", token) == 0)
		cmde = get_process_id();
	else if (_strcmp("$?", token) == 0)
		cmde = get_status(status);
	else if ((token[0] == '$') && (token[1]))
			{
				variable = _getenv(&token[1]);
				if (variable)
					cmde = _strdup(variable);
				else
					cmde = _strdup("");
			}
	else
		cmde = _strdup(token);
	argument_vector[i++] = cmde;
	while (token != NULL)
	{
		token = strtok(NULL, TOK_D);
		if (token != NULL)
		{
			if (_strcmp("$$", token) == 0)
				cmde = get_process_id();
			else if (_strcmp("$?", token) == 0)
				cmde = get_status(status);
			else if ((token[0] == '$') && (token[1]))
			{
				variable = _getenv(&token[1]);
				if (variable)
					cmde = _strdup(variable);
				else
					cmde = _strdup("");
			}
			else
				cmde = _strdup(token);
			argument_vector[i++] = cmde;
		}
	}
	argument_vector[i] = NULL;
	free(command_copied);
	return (argument_vector);
}
/**
 * line_count - Counts the number of lines in a given string.
 * @line: The input string.
 * Return: The number of lines in the string.
 */
int line_count(char *line)
{
	int i = 0;

	while (*line != '\0')
	{
		i++;
		line++;
	}
	return (i);
}
/**
 * char_count - Counts the occurrences of a specific character in a string.
 * @string: The input string.
 * @character: The character to count.
 * Return: The number of occurrences of the character in the string.
 */
unsigned int char_count(char *string, char character)
{
	unsigned int counter = 0;

	while (*string != '\0')
	{
		if (*string != character && *(string + 1) == character)
			counter++;
		string++;
	}
	return (counter + 1);
}


