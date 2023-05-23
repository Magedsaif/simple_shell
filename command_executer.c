#include "shell.h"
/*BETTY OKAY*/
/**
 * command_executer - Executes commands given.
 *
 * @path: The path of the command to execute.
 * @av: An array of strings containing the command and its arguments.
 * @env: An array of strings representing the environment variables.
 * @status: A pointer to an integer variable to set the status.
 *
 * Returns: NOTHING.
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

