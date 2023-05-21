#include "shell.h"
/**
 * 
 * 
 * 
 * 
*/

char *check_input_file(char *file)
{
    char* command;
    command = _strdup(file);
    
	return (command);
}

/**
 * 
 * 
 * 
 * 
 * 
*/

void scan_cmd_file(char *file)
{
    struct stat fileStat;
    
    
    if (stat(file, &fileStat) == 0) {
        printf("File Size: %ld bytes\n", fileStat.st_size);
        printf("File Permissions: %o\n", fileStat.st_mode);
        printf("File Inode: %lu\n", fileStat.st_ino);
        

    
        if (S_ISREG(fileStat.st_mode)) {
            printf("File is a regular file.\n");
        }

        if (S_ISDIR(fileStat.st_mode)) {
            printf("File is a directory.\n");
        }
    } else 
	{
        printf("Failed to retrieve file information.\n");
    }
}
