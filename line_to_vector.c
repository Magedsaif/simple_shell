#include "shell.h"

char **line_to_vector(char *line)
{
	char **vector;
	char *token, *command;
	int i = 0;
	char *line_copy;

	/*duplicate line*/
	line_copy = _strdup(line);
	vector = malloc(sizeof(char *) * (line_count(line) + 1));
	if (vector == NULL)
	{
		free(line_copy);
		return (NULL);
	}
	/*tokenize at space delimeter*/
	token = strtok(line_copy, " ");
	/*exclude $ and $$ */
		if (_strcmp(token, "$") != 0 && _strcmp(token, "$$") != 0)
		{
			command = _strdup(token); /*not on token directly*/
			vector[i++] = command;

		}

	/*fill vector with tokens  one after another*/
	while (token != NULL)
	{
		token = strtok(NULL, " ");
		if (token != NULL)
		{
			if (_strcmp(token, "$$") == 0)
			{
				int pid = getpid();
				char pid_str[16]; /*max sizeof pid*/
				int_to_str(pid, pid_str);
				command = _strdup(pid_str);
				vector[i++] = command;


			}
			else if (_strcmp(token, "$") == 0)
			{
			}
			else
			{
				command = _strdup(token);
				vector[i++] = command;
			}

		}

	}
	vector[i] = NULL;
	free(line_copy);
	return (vector);

}

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



