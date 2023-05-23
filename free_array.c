#include"shell.h"
/**
 * free_array - Frees memory allocated for an array of strings.
 * @argv: The array of strings to be freed.
 * Return : nothing
 */

void free_array(char **argv)
{
	char **current_character;

	/* Check if the input pointer is NULL */
	if (argv == NULL)
	{
		return;
	}

	/* Set the current_char pointer to the start of the array */
	current_character = argv;

	/* Iterate over each string in the array */
	while (*current_character != NULL)
	{
		/* Free the memory for the current string */
		free(*current_character);
		/* Move to the next string in the array */
		current_character++;
	}

	/* Free the memory allocated for the array itself */
	free(argv);
}
