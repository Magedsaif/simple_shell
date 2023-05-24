#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"
/*BETTY OKAY*/

/**
* custom_setenv - Set environment variable
* @key: The name of the environment variable
* @value: The value to be assigned to the environment variable
* @current: Pointer to the list_paths structure
* This function sets the value of an environment variable.
*/

void custom_setenv(char *key, char *value, list_paths *current)
{
	int count = 0;
	char *full_env = NULL;

	if (key == NULL || value == NULL)
	{
		return;
	}
	if (current == NULL)
	{
		return;
	}
	count = _strlen(key) + _strlen(value) + 2;
	full_env = malloc(count);
	if (full_env == NULL)
	{
		return;
	}
	_strcpy(full_env, key);
	_strcat(full_env, "=");
	_strcat(full_env, value);
	full_env[count - 1] = '\0';
	free(full_env);

}
