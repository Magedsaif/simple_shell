#include "shell.h"
/**
* custom_cd - Change the current working directory.
* @command_array: array of strings of commands.
* @argument_vector:argv
* Return: None.
*/
int custom_cd(char **command_array, char **argument_vector)
{

	char *directory = command_array[1];
	char cwd[1024];

	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("error in getcwd()");
		return (1);
	}
	if (directory == NULL || _strcmp(directory, "~") == 0)
		directory = _getenv("HOME");
	else if (_strcmp(directory, "-") == 0)
		directory = _getenv("OLDPWD");
	if (chdir(directory) == -1)
	{
		write(STDERR_FILENO, argument_vector[0], _strlen(argument_vector[0]));
		write(STDERR_FILENO, ": 1", 3);
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, command_array[0], _strlen(command_array[0]));
		write(STDERR_FILENO, ": can't cd to ", 14);
		write(STDERR_FILENO, command_array[1], _strlen(command_array[1]));
		write(STDERR_FILENO, "\n", 1);
		return (1);
	}
	else
	{
		setenv("OLDPWD", cwd, 1);
		if (getcwd(cwd, sizeof(cwd)) == NULL)
		{
			perror("error in getcwd()");
			return (1);
		}
	}
	return (0);
}


