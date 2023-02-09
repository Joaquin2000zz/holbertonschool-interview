#include "sort.h"

/**
 * merge - merges two arrays into a sorted slice
 * @array: entire array
 * @l: left slice
 * @r: right slice
 * @size: size of entire array
*/
void merge(int *array, int *l, int *r, size_t size)
{
	int s_i, s_d;
	int i = 0, j = 0, k = 0;

	s_i = size / 2;
	s_d = size - s_i;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(l, s_i);
	printf("[right]: ");
	print_array(r, s_d);

	while (i < s_i && j < s_d)
	{
		if (l[i] < r[j])
			array[k++] = l[i++];
		else
			array[k++] = r[j++];
	}

	while (i < s_i)
		array[k++] = l[i++];

	while (j < s_d)
		array[k++] = r[j++];
	printf("[Done]: ");
	print_array(array, size);
}

/**
 * merge_sort - sorts arrays in ascending order
 * @array: pointer tp first element of the array
 * @size: array size
*/
void merge_sort(int *array, size_t size)
{
	int r[1024];
	int l[1024];
	size_t m = 0, i = 0;

	if (!array)
		return;

	if (size < 2)
		return;

	m = size / 2;

	for (i = 0; i < m; i++)
		l[i] = array[i];
	for (i = m; i < size; i++)
	{
		r[i - m] = array[i];
	}
	merge_sort(l, m);
	merge_sort(r, size - m);
	merge(array, l, r, size);
}
