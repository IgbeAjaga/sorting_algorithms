#include "sort.h"
/**
*switching - swapping of two elements in an array
*@array: The array to be sorted
*@obj1: one element of the array
*@obj2: another element of the array
*/
void switching(int *array, ssize_t obj1, ssize_t obj2)
{
	int tmp_holder;

	tmp_holder = array[obj1];
	array[obj1] = array[obj2];
	array[obj2] = tmp_holder;
}
/**
 *lomuto_partition - Chooses the last element as pivot and partitions array
 *@array: The array to be sorted
 *@high: The starting index of the partition
 *@low: The ending index of the partition
 *@size: The size of the array
 *Return: The index of the pivot element after partitioning
 */
int lomuto_partition(int *array, ssize_t high, ssize_t low, size_t size)
{
	int pivot = array[low];
	ssize_t current = high, seeker;

	for (seeker = high; seeker < low; seeker++)
	{
		if (array[seeker] < pivot)
		{
			if (array[current] != array[seeker])
			{
				switching(array, current, seeker);
				print_array(array, size);
			}
			current++;
		}
	}
	if (array[current] != array[low])
	{
		switching(array, current, low);
		print_array(array, size);
	}
	return (current);
}
/**
 *quick_recursive - Recursive function to perform Quick sort
 *@array: The array to be sorted
 *@high: The starting index of the partition
 *@low: The ending index of the partition
 *@size: The size of the array
 */
void quick_recursive(int *array, ssize_t high, ssize_t low, int size)
{
	ssize_t pivot = 0;


	if (high < low)
	{
		pivot = lomuto_partition(array, high, low, size);

		quick_recursive(array, high, pivot - 1, size);
		quick_recursive(array, pivot + 1, low, size);
	}
}
/**
 *quick_sort - Sorts an array of integers in ascending order using Quick sort
 *@array: The array to be sorted
 *@size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quick_recursive(array, 0, size - 1, size);
}
