#ifndef MAIN_H
#define MAIN_H


#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>

#define INTERACTIVE_MODE 1
#define NON_INTERACTIVE_MODE 0
#define ERROR -1

/**
 * struct list_paths - a struct made for nodes out of enviroment variable path
 * @path: enviroment variable path
 * @len: length of the path
 * @next: points to the next node
*/

typedef struct list_paths
{
	char *path;
	unsigned int len;
	struct list_path *next;
} list_paths;

extern char **environ;

int _strlen(char *s);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
char *_strncpy(char *dest, char *src, int n);
char *_strncat(char *dest, char *src, int n);
char *_getenv(const char *name);
void print_env(char ** line);
int check_mode(int argc);
char *check_access(char *line, list_paths *path_list);
void free_array(char** argv);
char *scan_cmd_user(list_paths *current);
void is_exit(char *command,char **command_array, list_paths *current);
void free_array(char** argv);
void command_executer(char *path, char **av, char **env, int *status);
char *scan_cmd_file(char *file);
void check_input_file(char *file);
#endif
