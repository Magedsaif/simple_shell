int main(int argc, char *argv[], char *env[])
{
	int mode;
	int *status;
	char *line, **line_vector = NULL, *new_path;
	list_path *current;
	/*mode checking*/
	current = set_all_paths_to_list();
	mode = check_mode(argc);
	if (mode != INTERACTIVE)
		return (0);

	if (mode == NON_INTERACTIVE)
		check_file();
	while (1)
	{
		if (mode == NON_INTERACTIVE)
			line = get_command_from_file(argv[1]);
		else if (mode == INTERACTIVE)
			line = get_command_from_user(current);
		if(!line)
			continue;
		is_exit(line, line_vector, current);
		handle_comments(line);
		line_vector = get_av_with_flags(line, *status);
		if (is_built_in(line_vector) == 0)
			continue;
		if (access(line_vector[0], X_OK) == 0)
			execute_command(line_vector[0], line_vector, env, status);
		else
		{
			if (new_path = check_access(line_vector[0], current))
			{
				free(line_vector[0]);
				line_vector[0] = new_path;
				execute_command(line_vector[0], line_vector, env, status);
			}
		}
		free(line);
		free_vector(line_vector);
	}
	return (0);
}

