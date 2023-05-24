#include"shell.h"
/**
 * process_token - Processes a token and returns the corresponding string.
 * @token: The input token to process.
 * @status: An integer representing the status of the command.
 * Return: A dynamically allocated string representing the processed token.
 */
char *process_token(char *token, int status)
{
	char *cmde, *variable;

	cmde = NULL;
	variable = NULL;

	if (_strcmp("$$", token) == 0)
		cmde = get_process_id();
	else if (_strcmp("$?", token) == 0)
		cmde = get_status(status);
	else if (token[0] == '$' && token[1] != '\0')
	{
		variable = _getenv(&token[1]);
		cmde = (variable != NULL) ? _strdup(variable) : _strdup("");
	}
	else
		cmde = _strdup(token);
	return (cmde);
}
