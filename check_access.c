#include "shell.h"
/*BETTY OKAY*/
/**
  * check_access - a function that checks the access
  * for a given command in the command line.
  *
  * @current: current path turned into linked lists
  * @command:  line from user entered by getline and path list
  *
  * Return: full path of the command
  * if it is found be able to access and execute it
  * if fails returns NULL
  */

char *check_access(char *command, list_paths *current)
{
	char *full_path;
	int found_path, length, command_length, current_path_legnth;

	if (current == NULL)
		return (NULL);
	while (current)
	{
		current_path_legnth = _strlen(current->path);
		command_length = _strlen(command);
		length = (current_path_legnth + command_length + 2);
		/*Allocatig memory for full path depends on the length of it*/
		full_path = (char *)malloc(length * sizeof(char));
		/*copy the current path to the full path*/
		_strcpy(full_path, current->path);
		/*make it as a directory*/
		_strcat(full_path, "/");
		/*getting the supposed exact place in memory*/
		_strcat(full_path, command);
		/*checking the access for the command in it's full path*/
		found_path = 0;
		if (access(full_path, X_OK) == 0)
		{
			found_path = 1;
			break;
		}
		else
			free(full_path);
		/*traversing the full path*/
		current = current->next;
	}
	if (found_path)
		return (full_path);

	else
		return (NULL);
}
