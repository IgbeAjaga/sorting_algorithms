#ifndef DECK_H
#define DECK_H

/**
 * enum kind_e - Represents the kinds of cards in a deck
 * @SPADE: Spades
 * @HEART: Hearts
 * @CLUB: Clubs
 * @DIAMOND: Diamonds
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Represents a playing card
 * @value: Value of the card (Ace, 2-10, Jack, Queen, King)
 * @kind: Kind of the card (SPADE, HEART, CLUB, DIAMOND)
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Represents a node in the deck of cards
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node in the list
 * @next: Pointer to the next node in the list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void print_deck(const deck_node_t *deck);
void sort_deck(deck_node_t **deck);
void swap_nodes(deck_node_t **deck, deck_node_t *node1, deck_node_t *node2);

#endif /* DECK_H */
