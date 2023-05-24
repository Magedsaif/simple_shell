/**
 * char_count - Counts the occurrences of a specific character in a string.
 * @string: The input string.
 * @character: The character to count.
 * Return: The number of occurrences of the character in the string.
 */
unsigned int char_count(char *string, char character)
{
	unsigned int counter = 0;

	while (*string != '\0')
	{
		if (*string != character && *(string + 1) == character)
			counter++;
		string++;
	}
	return (counter + 1);
}
