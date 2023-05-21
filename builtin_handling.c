#include "shell.h"
/**
 *
 *
 *
 *
 *
*/
void print_env(int *status)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
		fflush(stdout);
	}
	*status = 0;
}
/**
 *
 *
 *
 *
 *
*/

char *get_process_id()
{
	char *ppid_s;
	pid_t pid = getpid();

	ppid_s = num_to_char(pid);

	return (ppid_s);
}

int builtin_handler(char *command, char **command_array ,list_paths *current, char *shell_name , int count, int *status)
{
	int i, n = -1;
	char *built_in[] = {"env", "exit"};

	for (i = 0; i < 2; i++)
	{
		if (_strcmp(built_in[i], command_array[0]) == 0)
		{
			n = i;
			break;
		}
	}
	if(n == -1)
		return (n);

	switch (n)
	{
    case 0:
        print_env(status);
        break;
    case 1:
        is_exit(command, command_array, current, shell_name, count, status);
        break;
    default:
        return (-1);
        break;
	}
	return(0);
}

char *get_status(int n)
{
	char *status;
	status = num_to_char(n);
	return status;

}
