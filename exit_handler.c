#include"shell.h"
/*BETTY OKAY*/

/**
 * is_exit - Checks if the command is an "exit" command and handles it.
 * @command: The original command entered by the user.
 * @command_array: An array of strings containing the command and its arguments
 * @current: A pointer to a list_paths struct representing the current path.
 * @shell_name: The name of the shell program.
 * @count: The command count.
 * @status: A pointer to an integer variable representing the status.
 * Return:Nothing
 */

void is_exit(char *command, char **command_array, list_paths *current,
char *shell_name, int count, int *status)
{
	int exit_num;

	/* Check if the first element of the command_array is "exit" */
	if (_strcmp(command_array[0], "exit") == 0)
	{
		/* If the second element is NULL, exit the shell program */
		if (command_array[1] == NULL)
		{
			/* Free memory, release resources, and exit with the status */
			free(command);
			free_list(current);
			free_array(command_array);
			exit(*status);
		}
		/* If the second element is not NULL */
		else if (command_array[1] != NULL)
		{
			if (_strlen(command_array[1]) <= 9)
			{
				exit_num = _atoi(command_array[1]);
				if (exit_num != -1)
				{
					free(command);
					free_list(current);
					free_array(command_array);
					exit(exit_num);
				}
				else
				{
					*status = EXIT_ERROR;
					print_error(shell_name, count, command_array[1], EXIT_ERROR);
				}
			}
			else
			{
				*status = EXIT_ERROR;
				print_error(shell_name, count, command_array[1], EXIT_ERROR);
			}
		}
	}
}
