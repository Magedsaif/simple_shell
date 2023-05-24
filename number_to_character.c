#include"shell.h"
/**
 * number_to_character - Converts an integer to a string.
 * @number: The integer to be converted.
 *
 * Return: The string representation of the integer,
 * or NULL on failure.
 */

char *number_to_character(int number)
{
	int count = 0, temprory = number;
	char *copied_number;

	/*Count the digits in the input number*/
	if (number == 0)
		count = 1;
	else
	{
		while (temprory != 0)
		{
			temprory = temprory / 10;
			count++;
		}
	}

	/* Allocate memory for the character array */
	copied_number = malloc(sizeof(char) * (count + 1));
	if (!copied_number)
	{
		perror("malloc error");
		return (NULL);
	}

	/* Set the null terminator at the end of the array */
	copied_number[count] = '\0';

	/* Convert each digit of the integer to a character and store in the array */
	while (count != 0)
	{
		count--;
		copied_number[count] = '0' + number % 10;
		number = (number / 10);
	}

	/* Return the converted string */
	return (copied_number);
}
