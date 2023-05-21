#include"shell.h"

/**
 * 
 * 
 * 
 * 
*/
void is_exit(char *command,char **command_array, list_paths *current,
		char *shell_name, int count, int *status)
		{
	int n;
	if (_strcmp(command_array[0], "exit") == 0)
	{
		if(command_array[1] == NULL)
		{
			free(command);
			free_list(current);
			free_array(command_array);
			exit(*status);
		}
		else if(command_array[1] != NULL )
		{
			if(_strlen(command_array[1]) <= 9)
			{
				n = _atoi(command_array[1]);
				if(n != -1)
				{
					free(command);
					free_list(current);
					free_array(command_array);
					exit(n);
				}
				else
				{
					*status = EXIT_ERROR;
					print_error(shell_name, count, command_array[1], EXIT_ERROR);
				}
			}
			else
			{
				*status = EXIT_ERROR;
				print_error(shell_name, count, command_array[1], EXIT_ERROR);
			}
			
		}
	}
}
/**
 * 
 * 
 * 
 * 
 * 
*/
void free_array(char** argv) 
{
    char** current_char;
	if (argv == NULL) 
	{
        return;  
    }
    current_char = argv;
    while (*current_char != NULL) {
        free(*current_char);
        current_char++;
    }
    free(argv);
}
/**
 * 
 * 
 * 
 * 
*/
void print_error(char *shell_name , int count,char *command_array, int type_of_error)
{
	char *counter_s;

	counter_s = num_to_char(count);
	write(STDERR_FILENO, shell_name, _strlen(shell_name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, counter_s, _strlen(counter_s));
	write(STDERR_FILENO, ": ", 2);
	if(type_of_error == EXIT_ERROR)
		write(STDERR_FILENO, "exit", 4);
	else
		write(STDERR_FILENO, command_array, _strlen(command_array));
	write(STDERR_FILENO, ": ", 2);
	if(type_of_error == NOT_FOUND)
		write(STDERR_FILENO, "not found\n", 10);
	else if(type_of_error == PERMISSION_DENIED)
		write(STDERR_FILENO, "Permission denied\n", 18);
	else if(type_of_error == EXIT_ERROR)
	{
		write(STDERR_FILENO, "Illegal number: ", 16);
		write(STDERR_FILENO, command_array, _strlen(command_array));
		write(STDERR_FILENO, "\n", 1);
	}
	free(counter_s);
}

char *num_to_char(int num)
{
	/*count digits*/
	int c = 0, tmp = num;
	char *cp_num;
	if (num == 0)
	{
		c = 1;
	}
	else
	{
		while (tmp != 0)
		{
			tmp /= 10;
			c++;
		}
	}

	cp_num = malloc(sizeof(char) * (c + 1));
	if (!cp_num)
	{
		perror("malloc");
		return (NULL);
	}
	cp_num[c] = '\0';
	while (c != 0)
	{
		c--;
		cp_num[c] = '0' + num % 10;
		num /= 10;
	}

	return (cp_num);
}

int _atoi(char *s)
{
	unsigned int n, i;
	char positive;

	i = 0;
	n = 0;
	while (s[i] != '\0')
	{
		if (!((s[i] >= '0') && (s[i] <= '9')))
		{
			return(-1);
		}
		if (((s[i] >= '0') && (s[i] <= '9')))
		{
			n = (n * 10) + (s[i] - '0');
		}
		else if (s[i] == '+')
			positive++;

		i++;
	}

return (n);
}
