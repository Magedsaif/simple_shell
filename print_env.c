#include"shell.h"
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
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}

	/* Set the status to indicate successful completion */
	*status = 0;
}
