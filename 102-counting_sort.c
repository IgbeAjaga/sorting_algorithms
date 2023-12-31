#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * counting_sort - Sorts an array of integers in ascending order
 *                using the Counting sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void counting_sort(int *array, size_t size)
{
	int max_value = 0, i, *count_arr = NULL;
	int *output = NULL;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > max_value)
			max_value = array[i];
	}

	count_arr = malloc(sizeof(int) * (max_value + 1));
	if (count_arr == NULL)
		return;

	for (i = 0; i <= max_value; i++)
		count_arr[i] = 0;

	for (i = 0; i < (int)size; i++)
		count_arr[array[i]]++;

	for (i = 1; i <= max_value; i++)
		count_arr[i] += count_arr[i - 1];

	print_array(count_arr, max_value + 1);

	output = malloc(sizeof(int) * size);
	if (output == NULL)
	{
		free(count_arr);
		return;
	}

	for (i = size - 1; i >= 0; i--)
	{
		output[count_arr[array[i]] - 1] = array[i];
		count_arr[array[i]]--;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = output[i];

	free(output);
	free(count_arr);
}
