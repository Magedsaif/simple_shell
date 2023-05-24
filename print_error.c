#include"shell.h"
/**
 * print_error - Prints an error message to the standard error stream.
 * @shell_name: The name of the shell program.
 * @count: The command count.
 * @command_array: The command or argument causing the error.
 * @type_of_error: The type of error.
 * Return: nothing
 */

void print_error(char *shell_name, int count,
char *command_array, int type_of_error)
{
	char *counter_string;

	/* Convert the command count to a string */
	counter_string = number_to_character(count);

	/* Print the shell name, command count, and colon separator */
	write(STDERR_FILENO, shell_name, _strlen(shell_name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, counter_string, _strlen(counter_string));
	write(STDERR_FILENO, ": ", 2);

	/* Check the type of error and print the corresponding error message */
	if (type_of_error == EXIT_ERROR)
	{
		write(STDERR_FILENO, "Illegal number: ", 16);
		write(STDERR_FILENO, command_array, _strlen(command_array));
		write(STDERR_FILENO, "\n", 1);
	}
	else if (type_of_error == NOT_FOUND)
	{
		write(STDERR_FILENO, "not found\n", 10);
	}
	else if (type_of_error == PERMISSION_DENIED)
	{
		write(STDERR_FILENO, "Permission denied\n", 18);
	}

	/* Free the memory allocated for the converted command count */
	free(counter_string);
}
