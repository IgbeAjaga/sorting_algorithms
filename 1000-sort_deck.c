#include <stdlib.h>
#include <stdio.h>
#include "deck.h"

/**
 * print_deck - Prints the deck of cards
 * @deck: Pointer to the head of the deck
 */
void print_deck(const deck_node_t *deck)
{
    size_t i;
    char kinds[4] = {'S', 'H', 'C', 'D'};

    i = 0;
    while (deck)
    {
        if (i)
            printf(", ");
        printf("{%s, %c}", deck->card->value, kinds[deck->card->kind]);
        if (i == 12)
            printf("\n");
        i = (i + 1) % 13;
        deck = deck->next;
    }
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @deck: Pointer to the head of the deck
 * @node1: First node to swap
 * @node2: Second node to swap
 */
void swap_nodes(deck_node_t **deck, deck_node_t *node1, deck_node_t *node2)
{
    deck_node_t *prev1, *prev2, *next1, *next2;

    prev1 = node1->prev;
    prev2 = node2->prev;
    next1 = node1->next;
    next2 = node2->next;

    if (prev1)
        prev1->next = node2;
    if (prev2)
        prev2->next = node1;

    node1->prev = prev2;
    node1->next = next2;
    node2->prev = prev1;
    node2->next = next1;

    if (next1)
        next1->prev = node2;
    if (next2)
        next2->prev = node1;

    if (*deck == node1)
        *deck = node2;
    else if (*deck == node2)
        *deck = node1;
}

/**
 * sort_deck - Sorts a deck of cards
 * @deck: Double pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck)
{
    deck_node_t *node, *next;
    int sorted;

    if (!deck || !(*deck) || !(*deck)->next)
        return;

    do
    {
        sorted = 0;
        node = *deck;

        while (node->next)
        {
            next = node->next;
            if (next->card->kind < node->card->kind || (next->card->kind == node->card->kind && next->card->value < node->card->value))
            {
                swap_nodes(deck, node, next);
                sorted = 1;
                print_deck(*deck);
            }
            else
                node = node->next;
        }
    } while (sorted);
}
