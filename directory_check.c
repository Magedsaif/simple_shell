#include"shell.h"
/*betty done*/
/**
* directory_check - checks if a directory exists and is accessible
* @command: the name of the directory to check
* @argument_vector:.
* @count:.
* @command_array:.
* @status:.
* @command_line_before:.
* Return: 1 if the directory exists and is accessible, else 0
*/
int dir_check(char *command, char **argument_vector, int count,
char **command_array, int *status, char *command_line_before)
{
	struct stat st;

if (stat(command, &st) == 0)
{
	if (S_ISDIR(st.st_mode))
	{
		print_error(argument_vector[0], count, command_array[0], PERMISSION_DENIED);
		*status = PERMISSION_DENIED;
		free_all(command_line_before, command_array);
		return (0);
	}
}
return (-1);
}
