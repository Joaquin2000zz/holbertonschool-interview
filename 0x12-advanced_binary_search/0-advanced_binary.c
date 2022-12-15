#include "search_algos.h"


/**
 * advanced_binary - searches for a value in a sorted array of integers
 * @array: is a pointer to the first element of the array to search in
 * @size: is the number of elements in array
 * @value: is the value to search for
 * Return: lower coincidence index
 */
int advanced_binary(int *array, size_t size, int value)
{
	int mid = ((size - 1) / 2), result = 0;
	size_t i = 0;

	if (!array || size < 1)
		return (-1);
	printf("Searching in array: ");
	for (; i < size; i++)
	{
		printf("%d", array[i]);
		if (i < (size - 1))
			printf(", ");
	}
	putchar('\n');
	if ((mid + array)[0] == value && mid == 0)
		return (mid);
	else if (size == 1)
		return (-1);
	if ((mid + array)[0] >= value)
		return (advanced_binary(array, mid + 1, value));
	mid++;
	result = advanced_binary(mid + array, size - mid, value);
	if (result == -1)
		return (-1);
	return (mid + result);
}
