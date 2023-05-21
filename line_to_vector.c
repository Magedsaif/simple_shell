#include "shell.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#define MAX_STR_LEN 100 /*arg len*/
#define MAX_STR_NUM 10	/*args count*/

/*function converts line input into array of strings*/
/*reurn ptr to this arr of strings*/

char **line_to_vector(char *command, int status)
{
	char *token, *command_tokenized;
	int i = 0;
	char *command_copy;

	/*duplicate line*/
	command_copy = _strdup(command);
	if (command_copy == NULL)
        return (NULL);
	char **vector = malloc(sizeof(char *) * MAX_STR_NUM + 1);
	if (vector == NULL)
		return (NULL);
	/*tokenize at space delimeter*/
	token = strtok(command_copy, " ");
	/*exclude $ and $$ */
		if (_strcmp(token, "$?") != 0 || _strcmp(token, "$$") != 0)
		{
			command_tokenized = _strdup(token); /*not on token directly*/
			vector[i++] = command_tokenized;
		}
	/*fill vector with tokens  one after another*/
	while (token != NULL)
	{
		token = strtok(NULL, " ");
		if (token != NULL)
		{
            if (_strcmp("$$", token) == 0)
                command_tokenized = get_process_id();
			else if (_strcmp("$?", token) == 0)
				command_tokenized = get_status(status);
			else
			command_tokenized = _strdup(token);
			vector[i++] = command_tokenized;
		}
	}
	vector[i] = NULL;
	free(command_copy);
	return (vector);

}
