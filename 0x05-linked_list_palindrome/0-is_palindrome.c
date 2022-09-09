#include "lists.h"
/**
 * is_palindrome - checks if singly linked list is palindrome
 * @head: pointer to the head node
 * Return: 1 if is palindrome. otherwise, returns 0
 */
int is_palindrome(listint_t **head)
{
    listint_t *aux;
    int n = 0, i, j, radius, buffer[9999];

    if (!head || !(*head))
        return (0);
    aux = *head;

    while (aux)
        buffer[n] = aux->n , n++, aux = aux->next;

    radius = n / 2;
    if (n % 2 == 0)
    {
        i = radius - 1, j = radius;
    }
    else
        i = radius, j = radius;

    while (i > -1 && j < n)
    {
        if (buffer[i] != buffer[j])
        {
            return (0);
        }
        buffer[i] = 0, buffer[j] = 0;
        i--, j++;
    }
    return (1);
}
