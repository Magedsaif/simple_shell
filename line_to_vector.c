#include "shell.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#define MAX_STR_LEN 100 /*arg len*/
#define MAX_STR_NUM 10	/*args count*/

/*function converts line input into array of strings*/
/*reurn ptr to this arr of strings*/

char **line_to_vector(char *line)
{
	char *token, *command;
	int i = 0;
	char *line_copy;

	/*duplicate line*/
	line_copy = _strdup(line);
	char **vector = malloc(sizeof(char *) * MAX_STR_NUM + 1);
	if (vector == NULL)
	{
		return (NULL);
	}
	/*tokenize at space delimeter*/
	token = strtok(line_copy, " ");
	/*exclude $ and $$ */
		if (_strcmp(token, "$") != 0 || _strcmp(token, "$$") != 0)
		{
			command = _strdup(token); /*not on token directly*/
			vector[i++] = command;
		}

	/*fill vector with tokens  one after another*/
	while (token != NULL)
	{

		if (_strcmp("$$", token) == 0)
		{
			pid_t pid = getpid();
			char pid_str[16];
			sprintf(pid_str, "%d\n", pid);
			write(STDOUT_FILENO, pid_str, strlen(pid_str));
		}

		else if (_strcmp("$?", token) == 0)
			{
			char *str = malloc(strlen(command) + strlen(": command not found") + 1);
			_strncpy(str, command, _strlen(str));
			_strncat(str, ": command not found", strlen(": command not found"));
			write(STDOUT_FILENO, str, _strlen(str));
			free(str);
			}
		else
			{
				command = _strdup(token);
			}
			vector[i++] = command;

		token = strtok(NULL, " ");
	}
	vector[i] = NULL;
	free(line_copy);
	return (vector);

}
int main(void)
{
    char line[MAX_STR_LEN];
    char **vector;
    int i;

    printf("Enter a command: ");
    fgets(line, MAX_STR_LEN, stdin);
    /* Remove newline character from input */
    line[strcspn(line, "\n")] = '\0';

    vector = line_to_vector(line);

    if (vector == NULL)
    {
        printf("Error: unable to allocate memory\n");
        return 1;
    }

    printf("Vector:\n");
    for (i = 0; vector[i] != NULL; i++)
    {
        printf("[%d] %s\n", i, vector[i]);
    }

    free(vector);

    return 0;
}



