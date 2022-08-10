#include "lists.h"

listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new = NULL, *aux = *head, *prev = NULL;

    new->n = number, new->next = NULL;
    
    if (!(*head)) 
    {
        *head = new;
        return new;
    }
    if (!aux->next)
    {
        if (aux->n < number)
        {
            aux->next = new;
            return new;
        }
        else
        {
            new->next = aux;
            return new;
        }
    }
    while (aux->next)
    {
        if (aux->next->n > number)
            break;
        prev = aux, aux = aux->next;
    }
    if (aux->n == number)
    {
        aux = new;
        return new;
    }
    prex->next = new;
    new->next = aux;
    return new;
}