#include "shell.h"
/**
 * piped_characters_count - counts the occurrences of a character in a string
 *
 * @string: the string to search for the character
 * @c: the character to search for
 * Return: the number of occurrences of @c in @string
 */
unsigned int piped_characters_count(char *string, char c)
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
