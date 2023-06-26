#include "sort.h"
#include <stdio.h>

/**
 * bitonic_merge - Recursive function to perform bitonic merge
 * @array: Pointer to the array
 * @low: Starting index of the subarray
 * @count: Number of elements to be sorted
 * @dir: Sorting direction (1 for ascending, 0 for descending)
 */
void bitonic_merge(int *array, size_t low, size_t count, int dir)
{
	if (count > 1)
	{
		size_t k = count / 2;
		size_t i;

		for (i = low; i < low + k; i++)
			if (dir == (array[i] > array[i + k]))
			{
				int temp = array[i];
				array[i] = array[i + k];
				array[i + k] = temp;
			}

		bitonic_merge(array, low, k, dir);
		bitonic_merge(array, low + k, k, dir);
	}
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order using
 *                the Bitonic sort algorithm
 * @array: Pointer to the array to be sorted
 * @size: Number of elements in the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (size < 2 || !array)
		return;

	printf("Merging [%lu/%lu] (UP):\n", size, size);
	print_array(array, size);

	bitonic_sort(array, size / 2);
	bitonic_sort(array + size / 2, size / 2);

	bitonic_merge(array, 0, size, 1);

	printf("Result [%lu/%lu] (UP):\n", size, size);
	print_array(array, size);
}
