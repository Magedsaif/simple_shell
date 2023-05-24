#include "shell.h"
/**
* main - Function that run SHELL program
* @argc: Argument Count.
* @argv: Argument vector
* @env: The shell environment
* Return: Exit status of the program
*/
int main(int argc, char *argv[], char *env[])
{
	int *status, count = 0, s = 0, non_interactive = 1, op_mode;
	char *command, **command_lines, **command_array = NULL;
	list_paths *current;

	op_mode = check_mode(argc);
	current = paths_to_linkedlist();/*turning the path current to a linked */
	if (op_mode != INTERACTIVE_MODE)/*checking the file after the command*/
		command_lines = scan_command_files(op_mode, argv[1], argv[0]);
	status = &s;

		if (op_mode == NON_INTERACTIVE_PIPE || op_mode == NON_INTERACTIVE_MODE)
		{
		command = get_non_interactive_command(command_lines, count);
		}
		else if (op_mode == INTERACTIVE_MODE)
			command = scan_cmd_user(current);/*prompt user&get command*/
		if (!command)
			return;
		process_command(command, status, &command_array);
		permission_handler(command_array, count, argv[0],
		status, command);
		/*handle the built in and deal with it's commands*/
		if (builtin_handler(command,
		command_array, current, argv[0], count, status) != 0)/*----lsa----*/
			nonbuiltin_hndler(command_array, env, status,
			count, current, argv);
		free_all(command, command_array);
	exit(*status);
}
