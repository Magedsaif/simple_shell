/**
* free_vector - Frees the memory allocated for a vector of strings.
* @vector: The vector to free.
*/

void free_vector(char **vector)
{
	int i = 0;

	if (vector == NULL)
	{
		return;
	}
	for (i = 0; vector[i] != NULL; i++)
	{
		free(vector[i]);
	}
	free(vector);

}

