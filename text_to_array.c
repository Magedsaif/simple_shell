#include"shell.h"
/**
 * text_to_array - converts text to an array of strings
 *
 * @text_read: the text to convert
 *
 * Return: a pointer to a char array containing the converted text
 */
char **text_to_array(char *text_read)
{
	char *token, *command, *copied_text;
	char **command_lines;
	int i = 0;
	unsigned int characters_count;

	copied_text = _strdup(text_read);
	if (copied_text == NULL)
		return (NULL);
	characters_count = piped_characters_count(copied_text, '\n');
	command_lines = malloc(characters_count * sizeof(char *));
	token = strtok(copied_text, "\n");
	command = _strdup(token);
	command_lines[i++] = command;
	while (token != NULL)
	{
		token = strtok(NULL, "\n");
		if (token != NULL)
		{
			command = _strdup(token);
			command_lines[i++] = command;
		}
	}
	free(text_read);
	return (command_lines);
}
