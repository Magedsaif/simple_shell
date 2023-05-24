#include "shell.h"
int main(int argc, char *argv[], char *env[])
{
	int *status, count = 0, s = 0, non_interactive = 1, op_mode;
	char *command, **command_lines, **command_array = NULL, *new_path = NULL;
	list_paths *current;

	op_mode = check_mode(argc);/*checking op. mode by getting the arg count*/
	current = paths_to_linkedlist();/*turning the path current to a linked */
	if (op_mode != INTERACTIVE_MODE)/*checking the file after the command*/
		command_lines = scan_command_files(op_mode, argv[1], argv[0]);
	status = &s;
	while (non_interactive && ++count)
	{
		if (op_mode == NON_INTERACTIVE_PIPE || op_mode == NON_INTERACTIVE_MODE)
		{
			if (command_lines[count - 1])
				command = command_lines[count - 1];
			else
				break;
		}
		else if (op_mode == INTERACTIVE_MODE)
			command = scan_cmd_user(current);/*prompt user&get command*/
		if (!command)
			continue;
		command_array = line_to_vector(command);
		if (!command_array)
			free(command);
			continue;
		if (directory_check(command_array[0]) == 0)
		{
			print_error(argv[0], count, command_array[0], PERMISSION_DENIED);
			*status = PERMISSION_DENIED;
			free_l_v(command, command_array);
			continue;
		}
		/*handle the built in and deal with it's commands*/
		if (builtin_handler(command, command_array, current, argv[0], count, status) != 0)/*----lsa----*/
			nonbuiltin_hndler(command_array, env, status,
			count, current, argv);
		free_l_v(command, command_array);
	}
	exit(*status);
}
