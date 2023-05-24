#include "shell.h"
#include <stddef.h>
/*betty done*/
/**
 * get_non_interactive_command - Retrieves the command.
 * @command_lines: Array of command lines
 * @count: Current count
 *
 * Return: Pointer to the command or NULL if not found
 */
char *get_non_interactive_command(char **command_lines, int count)
{
	if (command_lines[count - 1])
		return (command_lines[count - 1]);
	else
		return (NULL);
}
