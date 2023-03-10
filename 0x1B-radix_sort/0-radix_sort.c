#include "sort.h"
/**
 * counting_sort - sort the elements according to ith place digits
 * @array: pointer to the first element of the array
 * @size: array's size
 * @place: ith digit place
 */
void counting_sort(int *array, int size, int place)
{
    int *output = NULL, *count = NULL, max = (array[0] / place) % 10, i = 1;

    output = malloc((size + 1) * sizeof(int));
    if (!output)
        return;
    for (; i < size; i++)
        max = ((array[i] / place) % 10) > max ? array[i] : max;
    count = malloc((max + 1) * sizeof(int));
    if (!count)
        return;
    for (i = 0; i < max; i++)
        count[i] = 0;
    for (i = 0; i < size; i++)
        count[(array[i] / place) % 10]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = size - 1; i >= 0; i--)
    {
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
    }
    for (i = 0; i < size; i++)
        array[i] = output[i];
    print_array(array, size);
    free(output);
    free(count);
}

/**
 * radix_sort - sorts an array of integers in ascending order using radix sort
 * @array: pointer to the first element of the array
 * @size: array's size
 */
void radix_sort(int *array, size_t size)
{
    int max = 0, i = 0, place = 1;

    if (size == 1)
        return;
    for (; i < (int)size; i++)
        max = max < array[i] ? array[i] : max;
    for (; max / place > 0; place *= 10)
        counting_sort(array, (int)size, place);
}
