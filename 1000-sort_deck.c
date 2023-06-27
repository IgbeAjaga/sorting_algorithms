#include "deck.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_cards(const void *card1, const void *card2)
{
	const deck_node_t *node1 = *(const deck_node_t **)card1;
	const deck_node_t *node2 = *(const deck_node_t **)card2;

	int value1 = node1->card->kind * 13;
	int value2 = node2->card->kind * 13;

	const char *values[] = {
		"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"
	};

	int i;
	for (i = 0; i < 13; i++)
	{
		if (strcmp(node1->card->value, values[i]) == 0)
			value1 += i;
		if (strcmp(node2->card->value, values[i]) == 0)
			value2 += i;
	}

	return value1 - value2;
}

void sort_deck(deck_node_t **deck)
{
	size_t count = 0;
	size_t i;
	deck_node_t *current = *deck;
	deck_node_t **arr;

	while (current)
	{
		count++;
		current = current->next;
	}

	arr = malloc(count * sizeof(deck_node_t *));
	if (!arr)
	{
		fprintf(stderr, "Memory allocation failed\n");
		return;
	}

	current = *deck;
	for (i = 0; i < count; i++)
	{
		arr[i] = current;
		current = current->next;
	}

	qsort(arr, count, sizeof(deck_node_t *), compare_cards);

	for (i = 0; i < count - 1; i++)
	{
		arr[i]->next = arr[i + 1];
		arr[i + 1]->prev = arr[i];
	}

	arr[0]->prev = NULL;
	arr[count - 1]->next = NULL;
	*deck = arr[0];

	free(arr);
}
