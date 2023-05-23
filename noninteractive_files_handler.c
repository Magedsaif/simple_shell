#include"shell.h"
/**
 * file_non_interactive - .
 * @file_name: .
 * @program_name: .
 * Return: .
 */
char **noninteractive_files_handler(char *file_name, char *shell_name)
{
	struct stat fileStat;
	char *text, **command_lines;
	size_t letters_read;
	int fd;
	

	if (stat(file_name, &fileStat) != -1)
	{
		if (S_ISREG(fileStat.st_mode))
		{
			fd = open(file_name, O_RDONLY);
			if (fd  == -1)
				exit(ERROR);
			text = malloc((fileStat.st_size + 1) * sizeof(char));
			if (!text)
				return (NULL);
			letters_read = read(fd, text, fileStat.st_size);
			if ((int) letters_read == -1)
			{
				perror("reading error");
			}
			close(fd);
			text[letters_read - 1] = '\0';
			if (text)
				command_lines = text_to_array(text);
			return (command_lines);
		}
		else
			exit(0);
	}
	else
	{
		cant_open_handler(shell_name, 0, file_name);
		exit(127);
	}
	return (NULL);
}
