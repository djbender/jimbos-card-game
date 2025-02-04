#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#include "../include/utils.h"

const int RANK_LENGTH = 13;
const int SUIT_LENGTH = 4;
const int INITIAL_DECK_LENGTH = SUIT_LENGTH * RANK_LENGTH;
const int INITIAL_HAND_LENGTH = 8;

enum Rank {
    ACE = 1,
    TWO,   // 2
    THREE, // etc
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING // 13
};

const char *RANK_NAMES[] = {
    "Ace",
    "Two",
    "Three",
    "Four",
    "Five",
    "Six",
    "Seven",
    "Eight",
    "Nine",
    "Ten",
    "Jack",
    "Queen",
    "King"
};

const char *SHORT_RANK_NAMES[] = {
    "A",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "10",
    "J",
    "Q",
    "K"
};

// since Rank is 1-indexed, might as well do the same with Suit for symmetry
enum Suit {
    CLUBS = 1,
    DIAMONDS = 2,
    HEARTS = 3,
    SPADES = 4
};

const char *SuitNames[] = {
    "Clubs",
    "Diamonds",
    "Hearts",
    "Spades"
};


const char *SHORT_SUIT_NAMES[] = {
    "♣",
    "♡",
    "♠",
    "♢"
};

struct card {
    enum Rank rank;
    enum Suit suit;
};

const char *rank_name(int r);
const char *suit_name(int s);
const char *short_rank_name(int r);
const char *short_suit_name(int s);

void deal_hand(struct card hand[], struct card deck[], int dealCardsLength, int *deckLength);
void shuffle(struct card deck[], int length);
void print_card(struct card c);
void print_deck(struct card deck[], int deckLength);
void build_deck(struct card starting_deck[], int deckLength);
void print_select_cards_prompt(struct card hand[], int handLength);

int main(void) {
    int deckLength = INITIAL_DECK_LENGTH;
    struct card *deck = malloc(deckLength * sizeof(struct card));
    (void) build_deck(deck, deckLength);
    // (void) puts("Build Deck!");
    // (void) print_deck(deck, deckLength);
    (void) shuffle(deck, deckLength);
    // (void) puts("Shuffled Deck!");
    // (void) print_deck(deck, deckLength);
    int handLength = INITIAL_HAND_LENGTH;
    struct card *hand = malloc(handLength* sizeof(struct card));
    (void) deal_hand(hand, deck, handLength, &deckLength);

    (void) puts("Dealt hand:");
    (void) print_deck(hand, handLength);
    (void) puts("Remaining Deck:");
    (void) print_deck(deck, deckLength);
    (void) printf("deckLength: %d\n", deckLength);

    (void) print_select_cards_prompt(hand, handLength);

    (void) puts("Input card numbs seperated by spaces.");
    (void) printf("Play cards: ");

    char selectedCards[100];
    (void) s_gets(selectedCards, 100);
    // (void) printf("%s\n", selectedCards);

    int INPUT_HAND_LENGTH = 5;
    int inputHand[INPUT_HAND_LENGTH];

    (void) ints_from_string(selectedCards, inputHand, INPUT_HAND_LENGTH);
    printf("%d\n", inputHand[0]);
    printf("%d\n", inputHand[1]);
    printf("%d\n", inputHand[2]);
    printf("%d\n", inputHand[3]);
    printf("%d\n", inputHand[4]);
    // for(i = 0; i > INPUT_HAND_LENGTH; i++) {
    //
    // }


    (void) free(deck);
    return 0;
}

void print_select_cards_prompt(struct card hand[], int handLength)
{
    print_deck(hand, handLength);

    for(int i = 0; i < handLength; i++) {
        printf(" ^  ");
    }
    printf("\n");

    for(int i = 0; i < handLength; i++) {
        printf("%2d  ", i + 1);
    }
    printf("\n");
}

void deal_hand(struct card hand[], struct card deck[], int dealCardsLength, int *deckLength)
{
    (void) memcpy(hand, deck, dealCardsLength * sizeof(struct card));
    // Remove One Element
    // remove indexed item by resizing array and decrement logicalSize
    // memmove(
    //   array + removeIndex,
    //   array + removeIndex + 1,
    //   (--logicalSize - removeIndex) * sizeof(*array)
    // );
    //
    *deckLength -= dealCardsLength;
    // (void) printf("deckLength: %d\n", *deckLength);

    (void) memmove(
        deck,
        deck + dealCardsLength,
        (*deckLength - (dealCardsLength - 1)) * sizeof(*deck)
    );
}

void shuffle(struct card deck[], int length)
{
    (void) srand(time(NULL));
    // (void) srand(0);

    for(int i = 0; i < length; i++) {
        int swap_index = rand() % length;
        struct card temp = deck[i];
        deck[i] = deck[swap_index];
        deck[swap_index] = temp;
    }
}

void print_card(struct card c)
{
    (void) printf("%2s%s ", short_rank_name(c.rank), short_suit_name(c.suit));
}

void build_deck(struct card starting_deck[], int deckLength)
{
    int index = 0;
    for(int r = 1; r <= RANK_LENGTH; r++) {
        for(int s = 1; s <= SUIT_LENGTH; s++) {
            struct card myCard = { r, (s - 1) };
            if(index < deckLength) {
                starting_deck[index++] = myCard;
            } else {
                (void) exit(1);
            }
        }
    }
}

void print_deck(struct card deck[], int deckLength) {
    for(int c = 0; c < deckLength; c++) {
        if(deck[c].rank == 0) {
            break;
        }
        (void) print_card(deck[c]);
    }
    (void) puts("");
}

const char *rank_name(int r) {
    return RANK_NAMES[r - 1];
}
const char *suit_name(int s) {
    return SuitNames[s];
}
const char *short_rank_name(int r) {
    return SHORT_RANK_NAMES[r - 1];
}
const char *short_suit_name(int s) {
    return SHORT_SUIT_NAMES[s];
}
