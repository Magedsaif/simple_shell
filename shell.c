#include"shell.h"

int main(int argc, char* argv[], char *env[])
{
	int mode;
	char *command, **command_array;
	list_paths *current;
	/*tuning the */
	current = paths_to_linkedlist();
	/*checking the operating mode by getting the argument count*/
	mode = mode_checing(argc);
	if (mode != INTERACTIVE_MODE )
		return (0);
	/*checking the file after the command*/
	if(mode == NON_INTERACTIVE_MODE)
		check_input_file();
	while (1)
	{	/*dealing with commands from a passed file*/
		if (mode == NON_INTERACTIVE_MODE)
			command = scan_cmd_file(argv[1]);
		/*dealing with commands from a user turning it into victor*/
		else if (mode = INTERACTIVE_MODE)
			command_array = scan_cmd_user(current);
		if(!command)
			continue;
		/*check if there is an exit command in the vector*/
		is_exit(command, command_array, current);
	}
	
		
		
		
}
