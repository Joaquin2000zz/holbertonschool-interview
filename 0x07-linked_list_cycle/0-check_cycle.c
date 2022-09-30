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
    int flag = 0;

    if (!list)
        return (0);

    one = list, two = list;

    while (one && two)
    {
        if (one == two && flag)
            return (1);
        flag = 1;
        one = one->next;
        if (two->next)
            two = two->next->next;
        else
            break;

    }
    return (0);
}