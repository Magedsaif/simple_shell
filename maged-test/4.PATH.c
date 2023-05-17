#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

/*temperory shell.h*/
typedef struct list_paths
{
	char *path;
	unsigned int len;
	struct list_path *next;
} list_paths;
list_paths *paths_to_linkedlist();
list_paths *add_node(list_paths **head, const char *str);
char *_getenv(const char *name);
char *_strdup(char *str);
/*---------------------------------------------------------*/
/*turning the paths to linked lists*/

list_paths *paths_to_linkedlist()
{
    char *path_variable, *copied_variable, *token;
    list_paths *paths_linkedlists;

    paths_linkedlists = NULL;
    path_variable = _getenv("PATH");
    if (path_variable == NULL)
        return (NULL);

    copied_variable = strdup(path_variable);
    if (copied_variable == NULL)
        return (NULL);

    token = strtok(copied_variable, ":");
    while (token != NULL)
    {
        add_node(&paths_linkedlists, token);
        token = strtok(NULL, ":");
    }

    return (paths_linkedlists);
}

/*---------------------------------------------------------*/

/**
 * add_node - a function that adds a new node at the beginning of a list_t list
 * @head: pointer to the head of list with the type list_paths
 * @str: pointer to char
 * Return: the address of the new element, or NULL if it failed
*/
list_paths *add_node(list_paths **head, const char *path)
{
	list_paths *new;
	int i = 0;

	/*getting the count of elments (i), in str array of chars*/
	while (path[i] != '\0')
	{
		i++;
	}
	/*allocating memory to new node with type list_paths*/
	new = malloc(sizeof(list_paths));
	/*assuring it doesn't point to NULL*/
	if (new == NULL)
		return (NULL);


	/*duplicating the contents of path in path element of the new node created*/
	new->path = strdup(path);
	if (new->path == NULL)
	{
		free(new);
		return (NULL);
	}
	/*updating len element with the length of the new path entered*/
	new->len = i;
	/*updating the next pointer with a pointer to the new node*/
	new->next = (*head);

	*head = new;
	return (new);
}

