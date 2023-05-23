#include"shell.h"
/**
 * num_to_char - Converts an integer to a string.
 * @num: The integer to be converted.
 *
 * Return: The string representation of the integer,
 * or NULL on failure.
 */

char *num_to_char(int num)
{
	int c = 0, tmp = num;
	char *cp_num;

	/*Count the digits in the input number*/
	if (num == 0)
	{
		c = 1;
	}
	else
	{
		while (tmp != 0)
		{
			tmp /= 10;
			c++;
		}
	}

	/* Allocate memory for the character array */
	cp_num = malloc(sizeof(char) * (c + 1));
	if (!cp_num)
	{
		perror("malloc");
		return (NULL);
	}

	/* Set the null terminator at the end of the array */
	cp_num[c] = '\0';

	/* Convert each digit of the integer to a character and store in the array */
	while (c != 0)
	{
		c--;
		cp_num[c] = '0' + num % 10;
		num /= 10;
	}

	/* Return the converted string */
	return (cp_num);
}
