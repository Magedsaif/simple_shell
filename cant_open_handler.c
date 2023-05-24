#include "shell.h"
/**
* cant_open_handler - handles errors that occur when a file cannot be opened
* @program_name: the name of the program attempting to open the file
* @counter: a counter variable to keep track.
* @file_name: the name of the file that cannot be opened
*
* Return : void.
*/
void cant_open_handler(char *program_name, int counter, char *file_name)
{

	char *counter_s;

	counter_s = number_to_character(counter);
	write(STDERR_FILENO, program_name, _strlen(program_name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, counter_s, _strlen(counter_s));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, "Can't open ", 11);
	write(STDERR_FILENO, file_name, _strlen(file_name));
	write(STDERR_FILENO, "\n", 1);
}
