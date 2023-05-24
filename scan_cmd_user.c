#include"shell.h"
/**
 * scan_cmd_user - Scans and retrieves user input command.
 *
 * @current: A pointer to a list_paths struct representing the current path.
 *
 * Return: command after scanning.
 */
char *scan_cmd_user(list_paths *current)
{
	ssize_t read;
	size_t s = 0;
	char *command = NULL;
	/*prompt ($) and getting the input from the user*/
	write(STDOUT_FILENO, "($) ", 4);
	read = getline(&command, &s, stdin);
	/*dealing with end of file or ctrl + D*/
	if (read == EOF)
	{
		/*write new line and free*/
		write(STDOUT_FILENO, "\n", 1);
		free_list(current);
		free(command);
		exit(0);
	}
	/* If the user enters a blank line, return NULL */
	if (read == 1 && command[0] == '\n')
	{
		free(command);
		return (NULL);
	}

	command[read - 1] = '\0';

	return (command);
}
