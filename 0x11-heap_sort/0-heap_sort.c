#include "sort.h"

/**
 * swap - Function to swap the the position of two elements
 * @a: number to swap
 * @b: number to swap
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * heapify - Find largest among root, left child and right child
 * @array: int pointer
 * @slice: slice size
 * @i: largest index
 * @size: total size
 */
void heapify(int *array, size_t slice, size_t i, size_t size)
{
	size_t largest = i;
	size_t left = 2 * i + 1;
	size_t right = 2 * i + 2;

	if (left < slice && array[left] > array[largest])
		largest = left;

	if (right < slice && array[right] > array[largest])
		largest = right;

	/* Swap and continue heapifying if root is not largest*/
	if (largest != i)
	{
		swap(&array[i], &array[largest]);
		print_array(array, size);
		heapify(array, slice, largest, size);
	}
}

/**
 * heap_sort - sorts arrays of integers using the Heap sort algorithm
 * @array: int pointer with integers disorderly
 * @size: integer representing the size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i = 0;

	if (!array)
		return;

	if (size == 1)
	{
		print_array(array, size);
		return;
	}
	/* Build max heap */
	for (i = (int)size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);

	/* Heap sort*/
	for (i = (int)size - 1; i >= 0; i--)
	{
		swap(&array[0], &array[i]);

		/*Heapify root element to get highest element at root again*/
		heapify(array, i, 0, size);
		print_array(array, size);
	}
}
