#include "sort.h"
#include <stdio.h>

/**
 * swap - Swaps two integers
 * @a: First integer
 * @b: Second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * sift_down - Performs sift-down operation on a binary tree
 * @array: Array representation of the binary tree
 * @size: Size of the array
 * @root: Index of the root of the subtree
 * @end: Index of the last element in the heap
 */
void sift_down(int *array, size_t size, size_t root, size_t end)
{
	size_t left_child, right_child, max;

	while ((left_child = (2 * root) + 1) <= end)
	{
		right_child = left_child + 1;
		max = left_child;

		if (right_child <= end && array[right_child] > array[left_child])
			max = right_child;

		if (array[root] < array[max])
		{
			swap(&array[root], &array[max]);
			print_array(array, size);
			root = max;
		}
		else
			break;
	}
}

/**
 * heapify - Builds a max heap from an array
 * @array: The array to heapify
 * @size: The size of the array
 */
void heapify(int *array, size_t size)
{
	size_t parent;

	for (parent = (size / 2) - 1; (int)parent >= 0; parent--)
		sift_down(array, size, parent, size - 1);
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort
 * @array: The array to sort
 * @size: The size of the array
 */
void heap_sort(int *array, size_t size)
{
	size_t end;

	if (array == NULL || size < 2)
		return;

	end = size - 1;
	heapify(array, size);

	while (end > 0)
	{
		swap(&array[end], &array[0]);
		print_array(array, size);
		end--;
		sift_down(array, size, 0, end);
	}
}
