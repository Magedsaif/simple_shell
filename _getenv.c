#include"shell.h"
/*BETTY OKAY*/
/**
 * _getenv - a fUnction to get enviroment variabe
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
