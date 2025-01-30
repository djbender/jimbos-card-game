#include <stdio.h>
#include <stdlib.h>

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

const int RANK_LENGTH = 13;
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

const int SUIT_LENGTH = 4;
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

const char* rank_name(int r) {
        return RANK_NAMES[r - 1];
}

const char* suit_name(int s) {
        return SuitNames[s];
}

const char* short_rank_name(int r) {
        return SHORT_RANK_NAMES[r - 1];
}

const char* short_suit_name(int s) {
        return SHORT_SUIT_NAMES[s];
}

void print_card(struct card c) {
        printf(
                        "%s%s ",
                        short_rank_name(c.rank),
                        short_suit_name(c.suit)
              );
}

void print_deck(struct card *deck) {
        for(int c = 0; c < 52; c++) {
                if(deck[c].rank == 0) {
                        break;
                }
                print_card(deck[c]);
        }
        puts("");
}

int main() {
        struct card *startingDeck = malloc(52 * sizeof(struct card));
        int index = 0;
        for(int r = 1; r <= RANK_LENGTH; r++) {
                for(int s = 1; s <= SUIT_LENGTH; s++) {
                        struct card myCard = { r, s-1 };
                        startingDeck[index++] = myCard;
                        print_deck(startingDeck);
                }
        }
        free(startingDeck);
        return 0;
}
