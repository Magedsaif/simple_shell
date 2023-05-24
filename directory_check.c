#include"shell.h"
/*betty done*/
/**
* directory_check - checks if a directory exists and is accessible
* @command: the name of the directory to check
* Return: 1 if the directory exists and is accessible, else 0
*/
int directory_check(char *command)
{
	struct stat st;

if (stat(command, &st) == 0)
{
if (S_ISDIR(st.st_mode))
{
return (0);
}
}
return (-1);
}
