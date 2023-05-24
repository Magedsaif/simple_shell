#include "shell.h"

/**
 * get_commands - .
 * @mode: .
 * @file_name: .
 * @program_name: .
 * Return: .
 */
char **scan_command_files(int op_mode, char *file_name, char *shell_name)
{
	char **command_lines;

	if (op_mode == NON_INTERACTIVE_PIPE)
		command_lines = noninteractive_pipes_handler(shell_name);
	else if (op_mode == NON_INTERACTIVE_MODE)
	{
		command_lines = noninteractive_files_handler(file_name, shell_name);
	}
	return (command_lines);
}



