#include "shell.h"
/**
 * process_command - Process the command and generate the command array.
 * @command: The command to be processed.
 * @status: Pointer to the status variable.
 * @command_array: Pointer to the command array.
 * Return : command array.
 */
void process_command(char *command, int *status, char ***command_array)
{
	*command_array = line_to_vector(command, *status);
	if (!(*command_array))
	{
	free(command);
	return;
	}

}
