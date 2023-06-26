#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using insertion sort algorithm
 * @list: Double pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    current = (*list)->next;

    while (current != NULL)
    {
        listint_t *tmp = current->next;
        listint_t *prev = current->prev;

        while (prev != NULL && prev->n > current->n)
        {
            prev->next = current->next;
            if (current->next != NULL)
                current->next->prev = prev;

            current->prev = prev->prev;
            current->next = prev;

            if (prev->prev != NULL)
                prev->prev->next = current;
            else
                *list = current;

            prev->prev = current;
            prev = current->prev;
            print_list(*list);
        }

        current = tmp;
    }
}
