#include"shell.h"
/**
 * 
 * 
 * 
 * 
 * 
*/
int directory_checkr(char *command)
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
