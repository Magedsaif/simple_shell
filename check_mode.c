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
	struct stat stdin_stat;

	fstat(STDIN_FILENO, &stdin_stat);
	if ( argc == 1 && isatty(STDIN_FILENO))
		return (INTERACTIVE_MODE);
	if ((argc >= 1))
		return (NON_INTERACTIVE_MODE);
	if ((argc == 1 && !isatty(STDIN_FILENO) ))
		return (NON_INTERACTIVE_PIPE);
	return (ERROR);
}
