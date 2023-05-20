#include"shell.h"

/**
 * 
 * 
 * 
 * 
*/
void is_exit(char *command,char **command_array, list_paths *current)
{

	if (_strcmp(command, "exit") == 0)
	{
		free_array(current);
		free(command);
		exit(0);
	}
}
/**
 * 
 * 
 * 
 * 
 * 
*/
void free_array(char** argv) 
{
    char** current_char;
	if (argv == NULL) 
	{
        return;  
    }
    current_char = argv;
    while (*current_char != NULL) {
        free(*current_char);
        current_char++;
    }
    free(argv);
}
