#include "search.h"

/**
 * linear_skip - searches value in a sorted skip
 * list of integers.
 * @list: head pointer
 * @value: searched value
 * Return: searched node value or NULL
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *node = list;

	if (!list)
		return (NULL);

	while (node->express)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			node->express->index, node->express->n);
		if (node->express->n >= value)
		{
			printf("Value found between indexes [%lu] and [%lu]\n",
				node->index, node->express->index);
			break;
		}
		node = node->express;
	}
	if (!node->express)
	{
		for (list = node; list->next; list = list->next)
			;
		printf("Value found between indexes [%lu] and [%lu]\n",
				node->index, list->index);
	}
	for (list = node; list != node->express; list = list->next)
	{
		printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);
		if (value == list->n)
			break;
	}
	if (list == node->express)
		return (NULL);
	else
		return (list);
}