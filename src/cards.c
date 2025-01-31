#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "../include/utils.h"

const int RANK_LENGTH = 13;
const int SUIT_LENGTH = 4;
const int INITIAL_DECK_LENGTH = SUIT_LENGTH * RANK_LENGTH;

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

void print_card(struct card c) {
        printf("%s%s ", short_rank_name(c.rank), short_suit_name(c.suit));
}

void print_deck(struct card deck[]) {
        for(int c = 0; c < INITIAL_DECK_LENGTH; c++) {
                if(deck[c].rank == 0) {
                        break;
                }
                print_card(deck[c]);
        }
        puts("");
}

void build_deck(struct card starting_deck[])
{
        int index = 0;
        for(int r = 1; r <= RANK_LENGTH; r++) {
                for(int s = 1; s <= SUIT_LENGTH; s++) {
                        struct card myCard = { r, (s - 1) };
                        if(index < INITIAL_DECK_LENGTH) {
                                starting_deck[index++] = myCard;
                        } else {
                                exit(1);
                        }
                }
        }
}

void shuffle(struct card deck[], int length)
{
        srand(time(NULL));
        // srand(0);

        for(int i = 0; i < length; i++) {
                int swap_index = rand() % length;
                struct card temp = deck[i];
                deck[i] = deck[swap_index];
                deck[swap_index] = temp;
        }
}

int main(void) {
        struct card *deck = malloc(INITIAL_DECK_LENGTH * sizeof(struct card));
        (void)build_deck(deck);
        puts("Build Deck!");
        (void)print_deck(deck);
        (void)shuffle(deck, INITIAL_DECK_LENGTH);
        puts("Shuffled Deck!");
        print_deck(deck);
        free(deck);
        return 0;
}
