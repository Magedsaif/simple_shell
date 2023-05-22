#include "shell.h"
/*BETTY OKAY*/
/**
 * print_env - Prints the environment variables.
 * @status: A pointer to an integer variable to set the status.
 *
 * Each variable is printed on a separate line.
 * The 'status' parameter is used to set the status of the function.
 * Return:nothing
 */
void print_env(int *status)
{
	int i;

	/* Iterate over the environment variables until a NULL is encountered */
	for (i = 0; environ[i] != NULL; i++)
	{
		/* Print the current environment variable */
		printf("%s\n", environ[i]);

		/* Flush the output buffer to ensure immediate visibility */
		fflush(stdout);
	}

	/* Set the status to indicate successful completion */
	*status = 0;
}

/**
 * get_process_id - Retrieves the string representation of the current
 * process ID.
 *
 * Return: A pointer to a string representing the process ID.
 */

char *get_process_id()
{
	char *ppid_s;
	pid_t pid = getpid();

	/* Convert the process ID to a string */
	ppid_s = num_to_char(pid);

	/* Return the string representation of the process ID */
	return (ppid_s);
}

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

/**
 * get_status - Retrieves the string representation of a status value.
 *
 * @n: The status value to convert to a string.
 *
 * Return: A pointer to a string representing the status value.
 */
char *get_status(int n)
{
	char *status;

	/* Convert the status value to a string */
	status = num_to_char(n);

	/* Return the string representation of the status value */
	return (status);
}
