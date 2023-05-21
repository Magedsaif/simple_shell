#include "shell.h"

/* get the full path of a command entered by the user - check if the command is executable */
/* Args: line from user entered by getline and path list */
/* Return: full path of the command if it is found and executable, NULL otherwise */

char *check_access(char *command, list_paths *current)
{
	char *full_path;
	int found = 0, len;

	if (current == NULL)
		return (NULL);
	while (current)
	{
		len = strlen(current->path) + strlen(command) + 2; /* to calculate the length of the full path*/
		if (len > 1024)
		{
			write(STDERR_FILENO, "ERROR: Path too long\n", 21);
			continue;
		}
		full_path = (char *)malloc(len * sizeof(char));
		strcpy(full_path,current->path);
		strcat(full_path, "/");
		strcat(full_path, command);
		if (access(full_path, X_OK) == 0)
		{
			found = 1;
			break;
		}
		else
			free(full_path);

		current = current->next;
	}
	if (found)
		return (full_path);

	else
			return (NULL);
}



