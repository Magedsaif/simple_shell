#include"shell.h"

int main(int argc, char* argv[], char *env[])
{
	int mode,*status,count;
	char *command, **command_array,*new_path;
	list_paths *current;
	/*tuning the */
	current = paths_to_linkedlist();
	/*checking the operating mode by getting the argument count*/
	mode = mode_checking(argc);
	if (mode != INTERACTIVE_MODE )
		return (0);
	/*checking the file after the command*/
	if(mode == NON_INTERACTIVE_MODE)
		check_input_file(argv[1]);/*----lsa----*/
	count = 0;
	while (1)
	{	/*dealing with commands from a passed file*/
		if (mode == NON_INTERACTIVE_MODE)
			command = scan_cmd_file(argv[1]);/*----lsa----*/
		/*dealing with commands from a user turning it into victor*/
		else if (mode = INTERACTIVE_MODE)
			/*prompting the user and scan the input to a command*/
			command = scan_cmd_user(current);
		if(!command)
			continue;
		/*check if there is an exit command in the vector*/
		exit_handler(command, command_array, current);
		/*----line vector 6----*/
		/*handle the built in and deal with it's commands*/
		if (/*-----lsa----*/builtin_handler(command_array))
		{
			free_array(command_array);
			free(command);
			continue;
		}
		/*checking the accessibility of the command in order to execute it*/
		if (access(command_array[0],X_OK) == 0)
			command_executer(command_array[0], command_array, env, status);
		else
		{	/*if the user just entered the command without the whole path*/
			if (new_path = check_access(command_array[0], current))
			{
				command_executer(new_path, command_array, env, status);
				free(new_path);
			}
			else
			{
				print_error(argv[0] , count, command_array[0]);/*----lsa----*/
				*status = 127;
			}
		}
		free_array(command_array);
		free(command);
	}
	return (0);
}

