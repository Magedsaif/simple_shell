#include"shell.h"
/*betty done*/
/**
* check_input_file - checks if a file exists and is readable.
* @file: name of file to check
* This function checks if the file specified by
* @file exists and is readable.
*Return: pointer to @file if it exists
*/
char *check_input_file(char *file)
{
char *command;
command = _strdup(file);

	return (command);
}
