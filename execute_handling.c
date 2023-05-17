#include "shell.h"
/**
 * _getenv - a unction to get enviroment variabe
 * @name: name of enviroment variable to get the value of
 * Return: the value of the enviroment varable
*/

char *_getenv(const char *name)
{
	int i;
	char *env_name;
	char *env_value;
	char *value = NULL;

	for (i = 0; environ[i] != NULL; i++)
	{
		env_name = strtok(environ[i], "=");
		env_value = strtok(NULL, "=");

		if (strcmp(env_name, name) == 0)
		{
			value = env_value;
			break;
		}
	}
	return (value);
}

void command_executer(char *path, char **av, char **env)
{

}
