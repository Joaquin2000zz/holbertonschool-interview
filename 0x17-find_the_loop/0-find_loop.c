#include "lists.h"

/**
 * find_listint_loop - detects loop in linked list
 * @head: pointer to list
 * Return: pointer to first node in loop
*/

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *a = head, *b = head;

	if (!head)
		return (NULL);

	while (a && a->next)
	{
		b = b->next;
		a = a->next->next;
		if (b == a)
		{
			b = head;
			while (b != a)
			{
				b = b->next;
				a = a->next;
			}
			return (b);
		}
	}
	return (NULL);
}
