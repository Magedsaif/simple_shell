#include "shell.h"
/**
 * command_executer - a function that execute commands
 * @path:.
 * @env:
 * @av:
 * Return:.
*/
void command_executer(char *path, char **av, char **env, int *status)
{
	pid_t parent_id;

	parent_id = fork();
	/*if there is error in forking*/
	if (parent_id < 0)
	{
		perror("fork has failed");
		exit(EXIT_FAILURE);
	}
	/*if the forking has succeeded then execute*/
	if (parent_id == 0)
	{
		execve(path, av, env);
		perror("execve has failed");
		exit(EXIT_FAILURE);
	}
	/*if pid is greater than 0 then that's not a child process*/
	else if (parent_id > 0)
	{	
		/*then wait till the child process execute it's commands*/
		waitpid(parent_id, status, WUNTRACED);
		*status  = WEXITSTATUS(*status);
	}
}
/**
 * 
 * 
 * 
 * 
 * 
*/
char *scan_cmd_user(list_paths *current)
{
	ssize_t read;
	size_t n = 0;
	char *command = NULL;
	/*prompt ($) and getting the input from the user*/
	write(STDOUT_FILENO, "($) ", 5);
	read = getline(&command, &n, stdin);
	/*dealing with end of file or ctrl + D*/
	if (read == EOF)
	{
		/*write new line and free*/
		write(STDOUT_FILENO, "\n", 1);
		free_list(current);
		free(command);
		exit(0);
	}

	if(read == 1 && command[0] == '\n')
	{
		free(command);
		return (NULL);
	}
	command[read - 1] = '\0';

	return (command);
}
