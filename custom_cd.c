/*BETTY OKAY*/

#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
* custom_cd - Change the current working directory.
* @command_array: array of strings of commands.
* Return: None.
*/
void custom_cd(char **command_array)
{

	if (_strcmp(command_array[0], "-") == 0)
	{
		chdir(_getenv("OLDPWD"));
	}
	else if (command_array[0] ==  NULL)
	{
		chdir(_getenv("HOME"));
	}
	else
	{
		if (chdir(command_array[0]) == -1)
		{
		char *err_msg = "Directory not found\n";

		write(STDOUT_FILENO, err_msg, _strlen(err_msg));
		return;
		}

	}

}


