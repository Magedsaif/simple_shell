#include<stdlib.h>
/* Betty Ok*/
/**
* free_all - Free allocated memory
* @command: Pointer to the command string
* @command_array: Pointer to the array of command and its arguments
* This function frees the memory allocated.
* command and its arguments.
*/
void free_all(char *command, char **command_array)
{
	free(command);
	free_vector(command_array);
}
