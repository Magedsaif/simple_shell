#include "shell.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


#define MAX_STR_LEN 100 /*arg len*/
#define MAX_STR_NUM 10	/*args count*/

/*function converts line input into array of strings*/
/*reurn ptr to this arr of strings*/

char **line_to_vector(char *line)
{
	char *token;
	char *command;
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
	/*fill vector with tokens  one after another*/
	while (token != NULL)
	{
		if (_strcmp(token, "echo") == 0)
		{


		}
		else
		{
			vector[i] = _strdup(token); /*not on token directly*/
		}
		i++;
		token = strtok(NULL, " ");
	}
		vector[i] = NULL;

	free(line_copy);
	return (vector);

}
int main()
{
    char line[] = "echo $$";
    char **vector = line_to_vector(line);

    if (vector == NULL)
    {
        fprintf(stderr, "Failed to tokenize line.\n");
        return 1;
    }

    int i = 0;
    while (vector[i] != NULL && i < MAX_STR_NUM)
    {
        printf("%s\n", vector[i]);
        i++;
    }

    // Free the allocated memory
    for (int j = 0; j < i; j++)
    {
        free(vector[j]);
    }
    free(vector);

    return 0;
}

