#include "shell.h"

/* get the full path of a command entered by the user - check if the command is executable */
/* Args: line from user entered by getline and path list */
/* Return: full path of the command if it is found and executable, NULL otherwise */

char *check_access(char *line, list_paths *path_list)
{
	char *token;
	char *full_path = NULL;
	size_t token_len;
    size_t path_len;
	struct stat file_stat;
	list_paths *current = path_list; /*pointer to linkedlist*/
	 int found_executable = 0;

	token = strtok(line, " \t\n");
	if (token == NULL || path_list == NULL)
	{
		return (NULL);
	}

	/*search path for corresponding excutable*/
	while (current != NULL)
	{
		path_len = _strlen(current->path);
		token_len = _strlen(token);
				/* create the full path*/
		full_path = malloc(sizeof(char) * (path_len + token_len + 2));
		if (full_path == NULL)
		{
			return NULL;
		}

		/*fill full path with path + '/' + token by coppying into full_path*/
		_strcpy(full_path, current->path); /*path went*/
		_strcat(full_path, "/");
		_strcat(full_path, token);
		full_path[path_len] = '\0';
		/*end of full path concat*/

		/*use stat to check stat() to check if a file exists and is executable*/
		if (stat(full_path, &file_stat) == 0 && file_stat.st_mode & S_IXUSR)
		{
			 found_executable = 1;
		}
		else{
			free(full_path);
		}
		free(full_path); /*malloced previously*/
		current = current->next; /*move to next dir*/
	}
	if (found_executable)
    {
        return (full_path);
    }
    else
    {
        free(full_path); /* free memory if no executable path is found */
        return (NULL);
    }

}


