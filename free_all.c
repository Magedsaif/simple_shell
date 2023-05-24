/**
 *
 * 
 */
void free_all(char *command, char **command_array)
{
	free(command);
	free_vector(command_array);
}
