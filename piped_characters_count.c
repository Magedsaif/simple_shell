#include "shell.h"
/**
 * 
 * 
 * 
 * 
 * 
*/
unsigned int char_count_piped(char *string, char c)
{
	unsigned int counter = 0;

	while (*string != '\0')
	{
		if (*string != c)
			counter++;
		string++;
	}
	return (counter + 1);
}
