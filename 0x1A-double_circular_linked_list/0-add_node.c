#include "list.h"

/**
 * add_node_end - add a new node to the end of a double circular linked list
 * @list: pointer to the first node of the list
 * @str: string to duplicate in new node
 * Return: adress of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *new;

	if (!str || !list)
		return (NULL);
	new = malloc(sizeof(list));
	if (new == NULL)
		return (NULL);
	new->next = new;
	new->prev = new;
	new->str = strdup(str);
	if (!(*list))
	{
		(*list) = new;
		return (new);
	}
	(*list)->prev->next = new;
	new->prev = (*list)->prev;
	new->next = (*list);
	(*list)->prev = new;
	return (new);
}

/**
 * add_node_begin - same as previous but in the beggining
 * @list: pointer to the first node of the list
 * @str: string to duplicate in new node
 * Return: adress of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *new;

	if (!str || !list)
		return (NULL);
	new = malloc(sizeof(list));
	if (new == NULL)
		return (NULL);
	new->next = new;
	new->prev = new;
	new->str = strdup(str);
	if (!(*list))
	{
		*list = new;
		return (new);
	}
	(*list)->prev->next = new;
	new->prev = (*list)->prev;
	(*list)->prev = new;
	new->next = (*list);
	(*list) = new;
	return (*list);
}
