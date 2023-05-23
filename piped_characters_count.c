#include "shell.h"
/**
 * 
 * 
 * 
 * 
 * 
*/
unsigned int char_count_piped(char *str, char c)
{
	unsigned int count = 0;

	while (*str != '\0')
	{
		if (*str != c)
			count++;
		str++;
	}
	return (count + 1);
}
