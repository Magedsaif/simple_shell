#include "shell.h"
/**
 * get_process_id - Retrieves the string representation of the current
 * process ID.
 *
 * Return: A pointer to a string representing the process ID.
 */

char *get_process_id()
{
	char *ppid_s;
	pid_t pid = getpid();

	/* Convert the process ID to a string */
	ppid_s = num_to_char(pid);

	/* Return the string representation of the process ID */
	return (ppid_s);
}
