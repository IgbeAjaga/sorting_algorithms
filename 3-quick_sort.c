#include "sort.h"

/**
 * swap - Swaps two elements in an array
 * @a: Pointer to the first element
 * @b: Pointer to the second element
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - Takes the last element as the pivot and places it in the correct
 *             position in the sorted array.
 * @array: The array to be sorted
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 *
 * Return: The index of the pivot element
 */
int partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, high + 1);
		}
	}

	swap(&array[i + 1], &array[high]);
	print_array(array, high + 1);

	return (i + 1);
}

/**
 * quicksort - Recursive function that implements the quick sort algorithm
 * @array: The array to be sorted
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 */
void quicksort(int *array, int low, int high)
{
	if (low < high)
	{
		int pi = partition(array, low, high);

		quicksort(array, low, pi - 1);
		quicksort(array, pi + 1, high);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using the Quick sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	quicksort(array, 0, size - 1);
}

