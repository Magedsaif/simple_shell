#include "shell.h"
/*BETTY OKAY*/
/**
 * builtin_handler - Handles built-in commands in the shell.
 * @command: The original command entered by the user.
 * @command_array: An array of strings containing the parsed command.
 * @current: A pointer to a list_paths struct representing the current path.
 * @shell_name: The name of the shell.
 * @count: The count of the commands entered in the shell.
 * @status: A pointer to an integer variable to set the status.
 *
 * Return: The function returns 0 on successful execution of a built-in command
 * -1 if the command is not a built-in command,
 * or an error occurs.
 */
int builtin_handler(char *command, char **command_array, list_paths *current,
char *shell_name, int count, int *status)
{
	int i, n = -1;
	char *built_in[] = {"env", "exit"};

	/* Check if the entered command is a built-in command */
	for (i = 0; i < 2; i++)
	{
		if (_strcmp(built_in[i], command_array[0]) == 0)
		{
			n = i;
			break;
		}
	}

	/* If the command is not a built-in command, return -1 */
	if (n == -1)
		return (n);

	/* Execute the corresponding built-in command */
	switch (n)
	{
		case 0:
			print_env(status);
			break;
		case 1:
			is_exit(command, command_array,
			 current, shell_name, count, status);
			break;
		default:/*removed a break for betty*/
			return (-1);

	}

	return (0);
}


