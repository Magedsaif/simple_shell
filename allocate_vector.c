#include"shell.h"
/**
* allocate_vector - Allocates memory for a vector of strings.
* @size: The size of the vector.
* Return: A pointer to the allocated vector.
*/
char **allocate_vector(int size)
{
	return (malloc((size + 1) * sizeof(char *)));
}
