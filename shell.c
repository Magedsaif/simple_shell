#include"shell.h"

int main(int argc, char *argv[], char *env[])
{
	int mode, *status, count = 0, s = 0, non_interactive = 1;
	char *command, **command_array = NULL;
	char *new_path = NULL;
	list_paths *current;

	mode = check_mode(argc);/*checking op. mode by getting the arg count*/
	current = paths_to_linkedlist();/*turning the path current to a linked */
	if (mode == NON_INTERACTIVE_MODE)/*checking the file after the command*/
		check_input_file(argv[1]);/*----lsa----*/
	status = &s;
	while (non_interactive && ++count)
	{
		if (mode == NON_INTERACTIVE_MODE)/*deal with commands from a file*/
		{
		scan_cmd_file(argv[1]);/*----lsa---- remove assign to command bcoz void fn*/
		non_interactive = 0;
		}
		else if (mode == INTERACTIVE_MODE)
			command = scan_cmd_user(current);/*prompt user&get command*/
		if(!command)
			continue;
		command_array = line_to_vector(command);
		if (is_dir(command_array[0]) == 0)
		{
			print_error(argv[0], count, command_array[0], PERMISSION_DENIED);
			*status = PERMISSION_DENIED;
			free_array(command_array);
			free(command);
			continue;
		}/*handle the built in and deal with it's commands*/
		if (builtin_handler(command, command_array, current, argv[0], count, status) != 0)/*----lsa----*/
			{
			if (access(command_array[0],X_OK) == 0)
				command_executer(command_array[0], command_array, env, status);
				else
				{	/*if the user just entered the command without the whole path*/
					if (new_path == check_access(command_array[0], current))
					{
						command_executer(new_path, command_array, env, status);
						free(new_path);
					}
					else
					{
						print_error(argv[0] , count, command_array[0], NOT_FOUND);/*----lsa----*/
						*status = NOT_FOUND;
					}
				}
			}
		free_array(command_array);
		free(command);
	}
	return (0);
}
