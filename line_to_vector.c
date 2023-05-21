#include "shell.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include<sys/types.h>
#include<unistd.h>

/*function to convert int to str*/
void int_to_str(int n, char *str)
{
	int tmp;
	int i = 0;
	if (n == 0)
	{
		str[i++] = '0';
	}
	tmp = n;
	while (tmp > 0)
	{
		tmp /= 10;
		i++; /* calc str length needed*/
	}
	tmp = n;
	while (i > 0)
	{
		str[--i] = tmp % 10 + '0'; /*store rightmost and move backward*/
		tmp /= 10; /*remove rightmost*/

	}
	str[i] = '\0'; /*null term*/

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

/*function converts line input into array of strings*/
/*reurn ptr to this arr of strings*/

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


