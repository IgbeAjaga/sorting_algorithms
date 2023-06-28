#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * print_array - Prints the elements of an array
 * @array: The array to print
 * @size: The size of the array
 */
void print_array(int *array, size_t size)
{
    size_t i;

    for (i = 0; i < size; ++i)
    {
        printf("%d", array[i]);
        if (i != size - 1)
            printf(", ");
    }
    printf("\n");
}

/**
 * swap - Swaps two elements in an array
 * @a: The first element
 * @b: The second element
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * compare_swap - Compares and swaps two elements based on the given direction
 * @array: The array containing the elements
 * @i: The index of the first element
 * @j: The index of the second element
 * @dir: The direction (1 for ascending, 0 for descending)
 */
void compare_swap(int *array, size_t i, size_t j, int dir)
{
    if ((array[i] > array[j] && dir == 1) || (array[i] < array[j] && dir == 0))
        swap(&array[i], &array[j]);
}

/**
 * bitonic_merge - Performs the bitonic merge operation
 * @array: The array to be sorted
 * @low: The starting index of the sequence
 * @count: The number of elements to be sorted
 * @dir: The direction (1 for ascending, 0 for descending)
 */
void bitonic_merge(int *array, size_t low, size_t count, int dir)
{
    if (count > 1)
    {
        size_t k = count / 2;
        size_t i;

        for (i = low; i < low + k; ++i)
            compare_swap(array, i, i + k, dir);

        bitonic_merge(array, low, k, dir);
        bitonic_merge(array, low + k, k, dir);
    }
}

/**
 * bitonic_sort_recursive - Recursive function to perform bitonic sort
 * @array: The array to be sorted
 * @low: The starting index of the sequence
 * @count: The number of elements to be sorted
 * @dir: The direction (1 for ascending, 0 for descending)
 */
void bitonic_sort_recursive(int *array, size_t low, size_t count, int dir)
{
    if (count > 1)
    {
        size_t k = count / 2;

        bitonic_sort_recursive(array, low, k, 1);
        bitonic_sort_recursive(array, low + k, k, 0);
        bitonic_merge(array, low, count, dir);
    }
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order using Bitonic sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void bitonic_sort(int *array, size_t size)
{
    bitonic_sort_recursive(array, 0, size, 1);
}
