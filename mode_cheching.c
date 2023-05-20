#include"shell.h"
/**
 * check_mode - a function that checks the mode of my terminal
 *
 * @argc: arguments count
 *
 * Return: 1 in case of interactive mode
 * 0 in case of non interactive mode
 * -1 in case of error
*/
int check_mode(int argc)
{
	/*checking for non inter active mode with 2 arguents*/
	if(argc == 2)
		return (NON_INTERACTIVE_MODE);
	/*checking for inter active mode by isatty function*/
	else if(isatty(STDIN_FILENO) && argc == 1)
		return (INTERACTIVE_MODE);
	/*else it's an error*/
	return (ERROR);
}
