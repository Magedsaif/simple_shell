#include "shell.h"
/**
 * permission_handler - Handle permission denied error
 * @command_array: Array of command arguments
 * @count: Current count
 * @executable: Name of the executable
 * @status: Pointer to the status variable
 * @command: Command string
 */
void permission_handler(char **command_array, int count,
char *executable, int *status, char *command)
{
	if (directory_check(command_array[0]) == 0)
	{
	print_error(executable, count, command_array[0], PERMISSION_DENIED);
	*status = PERMISSION_DENIED;
	free_all(command, command_array);
	return;
	}

}


