#include <stddef.h>
#include "shell.h"
/**
 * handle_comments - Removes comments from the input string.
 *
 * @input: The input string.
 */
void handle_comments(char *input)
{
	int i = 0;
	char current_char;
	int quote = 0;

	for (i = 0; input[i] != '\0'; i++)
	{
		current_char = input[i];

		if (current_char == '"')
		{
			quote = !quote;
		}
		if (current_char == '#' && !quote)  /*  echo "hello #world"  */
		{
			input[i] = '\0';
			break;
		}

	}

}
