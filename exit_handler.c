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

/**
 * free_array - Frees memory allocated for an array of strings.
 * @argv: The array of strings to be freed.
 * Return : nothing
 */

void free_array(char **argv)
{
	char **current_character;

	/* Check if the input pointer is NULL */
	if (argv == NULL)
	{
		return;
	}

	/* Set the current_char pointer to the start of the array */
	current_character = argv;

	/* Iterate over each string in the array */
	while (*current_character != NULL)
	{
		/* Free the memory for the current string */
		free(*current_character);
		/* Move to the next string in the array */
		current_character++;
	}

	/* Free the memory allocated for the array itself */
	free(argv);
}

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
	counter_string = num_to_char(count);

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

/**
 * num_to_char - Converts an integer to a string.
 * @num: The integer to be converted.
 *
 * Return: The string representation of the integer,
 * or NULL on failure.
 */

char *num_to_char(int num)
{
	int c = 0, tmp = num;
	char *cp_num;

	/* Count the digits in the input number */
	if (num == 0)
	{
		c = 1;
	}
	else
	{
		while (tmp != 0)
		{
			tmp /= 10;
			c++;
		}
	}

	/* Allocate memory for the character array */
	cp_num = malloc(sizeof(char) * (c + 1));
	if (!cp_num)
	{
		perror("malloc");
		return (NULL);
	}

	/* Set the null terminator at the end of the array */
	cp_num[c] = '\0';

	/* Convert each digit of the integer to a character and store in the array */
	while (c != 0)
	{
		c--;
		cp_num[c] = '0' + num % 10;
		num /= 10;
	}

	/* Return the converted string */
	return (cp_num);
}

/**
 * _atoi - Converts a string to an integer.
 * @s: The string to be converted.
 *
 * Return: The converted integer,
 * or -1 on conversion error.
 */

int _atoi(char *s)
{
	unsigned int n, i;
	char positive;

	i = 0;
	n = 0;

	/* Iterate through each character of the string */
	while (s[i] != '\0')
	{
		/* Check if the character is a non-digit */
		if (!((s[i] >= '0') && (s[i] <= '9')))
		{
			return (-1);
		}

		/* Check if the character is a digit */
		if (((s[i] >= '0') && (s[i] <= '9')))
		{
			n = (n * 10) + (s[i] - '0');
		}
		else if (s[i] == '+')
		{
			positive++;
		}

		i++;
	}

	/* Return the converted integer */
	return (n);
}
