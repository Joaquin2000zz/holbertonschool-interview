#include "lists.h"

/**
 * insert_node - given sorted linked list, insert node in ascending order
 * @head: pointer pointing to the pointer node
 * @number: number to insert in new node
 * Return: new node
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new = NULL, *aux = *head, *prev = NULL;

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);
	new->n = number, new->next = NULL;

	if (!(*head))
	{
		*head = new;
		return (new);
	}
	if (!aux->next)
	{
		if (aux->n < number)
			aux->next = new;
		else
		{
			new->next = aux;
			*head = new;
		}
		return (new);
	}
	while (aux->next)
	{
		if (aux->n > number)
			break;
		prev = aux, aux = aux->next;
	}
	if (aux->n == number)
	{
		aux = new;
		return (new);
	}
	prev->next = new;
	new->next = aux;
	return (new);
}
