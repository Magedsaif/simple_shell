#include "shell.h"
/**
 * line_to_vector - converts a string into an array of strings
 * @command: the string to convert
 * @status: an integer representing the status of the command
 * Return: a pointer to a char array.
 */
char **line_to_vector(char *command, int status)
{
	char *copied_line, *token, **argument_vector, *variable, *cmde;
	int i = 0, character_count;

	/*handle_comments(command);*//*lsaaaaaa*/
	if (command[0] == '\0')
		return (NULL);
	copied_line = _strdup(command);
	if (copied_line == NULL)
		return (NULL); /*can't cpy*/
	character_count = char_count(copied_line, ' ');
	argument_vector = malloc((character_count + 1) * sizeof(char *));
	token = _strtok(copied_line, TOK_D);

	cmde = flags_handler(token, command, argument_vector, status);
	argument_vector[i++] = cmde;
	while (token != NULL)
	{
		token = _strtok(NULL, TOK_D);
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
	free(copied_line);
	return (argument_vector);
}
/**
 * flags_handler - .
 * @token:.
 * @command:.
 * @argument_vector:.
 * @status:.
 * Return:.
*/
char *flags_handler(char *token, char *command,
char **argument_vector, int status)
{
		char *variable, *cmde, *copied_line;

	copied_line = command;
		if (token == NULL)
	{
		free(argument_vector);
		free(copied_line);
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

	return (cmde);
}
