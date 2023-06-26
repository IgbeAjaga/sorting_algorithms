#include "sort.h"

/**
 * partition - Partitions the array using the Lomuto partition scheme
 *
 * @array: The array of integers to be sorted
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 *
 * Return: The index of the pivot element
 */
int partition(int *array, int low, int high)
{
    int pivot = array[high];
    int i = low - 1;
    int j, temp;

    for (j = low; j <= high - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            print_array(array, high + 1);
        }
    }

    temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    print_array(array, high + 1);

    return (i + 1);
}

/**
 * quicksort - Implements the Quick sort algorithm recursively
 *
 * @array: The array of integers to be sorted
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 */
void quicksort(int *array, int low, int high)
{
    if (low < high)
    {
        int pivot = partition(array, low, high);

        quicksort(array, low, pivot - 1);
        quicksort(array, pivot + 1, high);
    }
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the Quick sort algorithm
 *
 * @array: The array of integers to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quicksort(array, 0, size - 1);
}
