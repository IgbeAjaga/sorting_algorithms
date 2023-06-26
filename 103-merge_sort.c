#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge - Merges two subarrays into one sorted array
 * @array: The main array containing the subarrays
 * @left: The left subarray
 * @left_size: The size of the left subarray
 * @right: The right subarray
 * @right_size: The size of the right subarray
 **/
void merge(int *array, int *left, size_t left_size, int *right, size_t right_size)
{
	size_t i = 0, j = 0, k = 0;
	int *merged;

	printf("Merging...\n[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);

	merged = malloc(sizeof(int) * (left_size + right_size));
	if (merged == NULL)
		return;

	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
			merged[k++] = left[i++];
		else
			merged[k++] = right[j++];
	}

	while (i < left_size)
		merged[k++] = left[i++];

	while (j < right_size)
		merged[k++] = right[j++];

	for (i = 0; i < left_size + right_size; i++)
		array[i] = merged[i];

	printf("[Done]: ");
	print_array(array, left_size + right_size);

	free(merged);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using
 *              the Merge sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 **/
void merge_sort(int *array, size_t size)
{
	size_t mid;
	int *left, *right;

	if (array == NULL || size < 2)
		return;

	mid = size / 2;
	left = array;
	right = array + mid;

	merge_sort(left, mid);
	merge_sort(right, size - mid);

	merge(array, left, mid, right, size - mid);

	if (size > 2)
		free(right);
}
