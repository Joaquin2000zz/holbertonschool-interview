#include "lists.h"
/**
 * insert_node - given sorted linked list, insert node in ascending order
 * @head: pointer pointing to the pointer node
 * @number: number to insert in new node
 * Return: new node
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *aux;
    listint_t *new;

    if (head == NULL && *head == NULL)
    {
        return (NULL);
    }
    aux = *head;
    new = malloc(sizeof(listint_t));
    if (new == NULL)
        return (NULL);

    new->n = number;
    if (*head == NULL)
    {
        new->next = NULL;
        *head = new;
        return (*head);
    }
    while (aux != NULL)
    {
        if (number > aux->n && aux->next != NULL && number <= aux->next->n)
        {
            new->next = aux->next;
            aux->next = new;
            return (new);
        }
        if (number <= aux->n)
        {
            new->next = aux;
            *head = new;
            return (*head);
        }
        if (aux->next == NULL)
        {
            aux->next = new;
            new->next = NULL;
            return (new);
        }
        aux = aux->next;
    }
    return (NULL);
}
