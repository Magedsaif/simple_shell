#include "shell.h"

/**
* _strlen - returns the length of a string
* @s: a pointer to the string
*
* This function takes a pointer to a
* string and counts the number of characters
* in the string using a loop. It returns the length of
* the string as an integer.
*
* Return: the length of the string as an integer.
*/
int _strlen(char *s)
{
	int length = 0;

	while (*s != '\0')
	{
		length++;
		s++;
	}
	return (length);
}

/**
* _strdup - Returns a pointer to a newly allocated space in memory,
* which contains a copy of the string given as a parameter.
* @str: The string to duplicate
* Return: If str is NULL or if malloc() fails - NULL
*/
char *_strdup(char *str)
{
	char *newstr;
	unsigned int i = 0;
	unsigned int j;

	if (str == NULL)
	{
		return (NULL);
	}
	while (str[i] != '\0')
	{
		i++;
	}
	newstr = malloc(i + 1);
	if (newstr == NULL)
	{
		return (NULL);
	}
	for (j = 0; j <= i + 1; j++)
	{
		newstr[j] = str[j];
	}
	return (newstr);

}

/**
* _strcmp - Compares two strings.
*
* @s1: Pointer to the first string to be compared.
* @s2: Pointer to the second string to be compared.
*
* Return: An integer less than, equal to, or greater than zero
*/
int _strcmp(char *s1, char *s2)
{
		while (*s1 && *s2 && *s1 == *s2)
		{
			if (*s1 != *s2)
			{
				return ((int)*s1 - (int)*s2);
			}
			s1++;
			s2++;
		}

	return ((int)*s1 - (int)*s2);
}

/**
 * _strncpy - function copies the string pointed to by src
 *
 * @dest: destination of copy
 * @src: source array to copy
 * @n: number of bytes from src
 * Return: a pointer to the resulting string dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int len, i;

	len = _strlen(src);
	for (i = 0; i < n; i++)
	{
		if (i < len)
			dest[i] = src[i];
		else
			dest[i] = '\0';
	}
	return (dest);

}

/**
 * _strncat - concats two arrays
 *
 * @dest: destination of concat
 * @src: source array to concat
 * @n: number of bytes from src
 * Return: a pointer to the resulting string dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int i;
	int j;

	for (j = 0; dest[j] != '\0'; j++)
	{}

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[j + i] = src[i];
	}

	return (dest);

}
