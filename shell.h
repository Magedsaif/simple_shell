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

#define NOT_FOUND 127
#define PERMISSION_DENIED 126
#define EXIT_ERROR 2

#define INTERACTIVE_MODE 1
#define NON_INTERACTIVE_PIPED 2
#define NON_INTERACTIVE_MODE 0
#define ERROR -1
#define TOK_D " \t\r\n\a\""


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
	struct list_paths *next;
} list_paths;

extern char **environ;
list_paths *paths_to_linkedlist();
size_t print_list(const list_paths *h);
void free_list(list_paths *head);
/* list_paths *add_node(list_paths **head, const char *path);*/
list_paths *add_node(list_paths **head, char *path);
/*-----------*/
int _strlen(char *s);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _atoi(char *s);
/*----------*/
void print_env(int *status);
int check_mode(int argc);
char *check_access(char *line, list_paths *path_list);
char *scan_cmd_user(list_paths *current);
void is_exit(char *command,char **command_array, list_paths *current,char *shell_name, int count, int *status);
void free_array(char** argv);
void command_executer(char *path, char **av, char **env, int *status);
void scan_cmd_file(char *file);
char *check_input_file(char *file);
void free_list(list_paths *head);
/*char **line_to_vector(char *command, int status);*/
char **line_to_vector(char *line);
char *num_to_char(int num);
void print_error(char *shell_name , int count,char *command_array, int type_of_error);
char *num_to_char(int num);
int is_dir(char *line);
char *get_status(int n);
char *get_process_id();
char *_getenv(const char *name);
int builtin_handler(char *command, char **command_array ,list_paths *current, char *shell_name , int count, int *status);
#endif
