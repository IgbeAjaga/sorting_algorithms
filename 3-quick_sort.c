#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quicksort_recursive(array, 0, size - 1);
}

/**
 * quicksort_recursive - Recursive function to perform Quick sort
 * @array: The array to be sorted
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 */
void quicksort_recursive(int *array, int low, int high)
{
    if (low < high)
    {
        int pivot = partition(array, low, high);
        quicksort_recursive(array, low, pivot - 1);
        quicksort_recursive(array, pivot + 1, high);
    }
}

/**
 * partition - Chooses the last element as pivot and partitions the array
 * @array: The array to be sorted
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 *
 * Return: The index of the pivot element after partitioning
 */
int partition(int *array, int low, int high)
{
    int pivot = array[high];
    int i = low - 1;
    int j, temp;

    for (j = low; j < high; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            if (i != j)
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                print_array(array, high + 1);
            }
        }
    }

    if (array[i + 1] != array[high])
    {
        temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;
        print_array(array, high + 1);
    }

    return i + 1;
}
