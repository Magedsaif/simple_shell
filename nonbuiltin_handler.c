#include"shell.h"
/*BETTY OKAY*/

/**
* nonbuiltin_hndler - Handle non-builtin commands
* @command_array: Array of command arguments
* @env: Environment variables
* @status: Pointer to the status variable
* @count: Number of commands executed
* @current: Pointer to the list_paths structure
* @argv: Array of command-line arguments
* This function handles non-builtin commands in the shell.
* by checking the access permission.
*/
void nonbuiltin_hndler(char **command_array, char *env[], int *status,
						int count, list_paths *current, char *argv[])
{
	char *new_path;

	if (access(command_array[0], X_OK) == 0)
		command_executer(command_array[0], command_array, env, status);
		else
		{	/*if the user just entered the command without the whole path*/
			new_path = check_access(command_array[0], current);
			if (new_path)
			{
				command_executer(new_path, command_array, env, status);
				free(new_path);
			}
			else
			{
				print_error(argv[0], count, command_array[0], NOT_FOUND);/*----lsa----*/
				*status = NOT_FOUND;
			}
		}
}
