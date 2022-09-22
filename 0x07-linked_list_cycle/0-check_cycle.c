#include "lists.h"
#include <stdio.h>

/**
 * check_cycle - checks if the linked list passed has a cycle
 * @list - head node
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
    listint_t *one, *two;

    if (!list)
        return (1);

    one = list, two = list;

    while (one->next && two->next->next)
    {
        one = one->next;
        two = two->next->next;
        if (one == two)
            return (1);
    }
    return (0);
}