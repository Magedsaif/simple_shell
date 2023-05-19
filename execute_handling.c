#include "shell.h"
/**
 * _getenv - a fnction to get enviroment variabe
 * @name: name of enviroment variable to get the value of
 * Return: the value of the enviroment varable
*/

char *_getenv(const char *name)
{
	int i;
	char *variable_name;
	char *variable_value;
	char *value = NULL;

	/*loop through the enviroment variables strored at environ*/
	for (i = 0; environ[i] != NULL; i++)
	{	
		/*getting the name of the enviroment variable*/
		variable_name = strtok(environ[i], "=");
		/*getting the value corresponding to the name*/
		variable_value = strtok(NULL, "=");

		/*comparing the variable's name given by user and the list of EV's*/
		if (strcmp(variable_name, name) == 0)
		{
			/*if found assign the value of EV's to value*/
			value = variable_value;
			break;
		}
	}
	/*returning the value of assigned after finding the EV*/
	return (value);
}

void command_executer(char *path, char **av, char **env)
{
	pid_t parent_id;

	parent_id = fork();
	/*if there is error in forking*/
	if (parent_id < 0)
	{
		perror("forh has failed");
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
		wait(NULL);
	}

}

/*
 * mode_checking - check the mode of the terminal
 * @argc: arguements count in terminal
 * Return : mode to deal with
 */
int mode_checking(int argc)
{
	if(argc == 1)
		return (INTERACTIVE_MODE);
	else if(argc == 2)
		return (NON_INTERACTIVE_MODE);
	return (ERROR);
}
