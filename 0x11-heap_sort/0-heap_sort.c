#include "sort.h"

/**
 * swap - swaps two ints
 * @a: pointer to int
 * @b: pointer to int
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * heapify - takes an array and makes it max heap
 * @arr: pointer to array
 * @n: int
 * @i: int
 * @total_size: int
 */
void heapify(int *arr, int n, int i, size_t total_size)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && arr[left] > arr[largest])
		largest = left;

	if (right < n && arr[right] > arr[largest])
		largest = right;

	if (largest != i)
	{
		swap(&arr[i], &arr[largest]);
		print_array(arr, total_size);
		heapify(arr, n, largest, total_size);
	}
}

/**
 * heap_sort - sorts an int array by heapify
 * @array: pointer to the arra
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	size_t i;

	if (array)
	{
		for (i = size / 2 - 1; (int)i >= 0; i--)
			heapify(array, size, i, size);

	for (i = size - 1; (int)i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		heapify(array, i, 0, size);
	}
	}
}
