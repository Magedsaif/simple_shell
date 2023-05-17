#include <string.h>
#include <stdio.h>
#include <stdlib.h>
char *_getenv(const char *name);
extern char **environ;

int main () 
{

	const char *str_name = "PATH";
	const char s[2] = ":";
	char *token;


	char *str_value = _getenv(str_name);
	/* get the first token */
	token = strtok(str_value, s);

	/* walk through other tokens */
	while( token != NULL )
	{
	printf( "%s\n", token );

	token = strtok(NULL, s);
	}
return(0);
}



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
