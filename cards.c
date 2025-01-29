#include <stdio.h>
#include <stdlib.h>

typedef enum {
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
} Rank;

const int RankLength = 13;
const char *RankNames[] = {
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

const char *ShortRankNames[] = {
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
typedef enum {
  CLUBS = 1,
  DIAMONDS = 2,
  HEARTS = 3,
  SPADES = 4
} Suit;

const int SuitLength = 4;
const char *SuitNames[] = {
  "Clubs",
  "Diamonds",
  "Hearts",
  "Spades"
};

const char *ShortSuitNames[] = {
  "♣",
  "♡",
  "♠",
  "♢"
};

typedef struct card {
  Rank rank;
  Suit suit;
} card;

const char* getRankName(int r) {
  return RankNames[r - 1];
}

const char* getSuitName(int s) {
  return SuitNames[s];
}

const char* getShortRankName(int r) {
  return ShortRankNames[r - 1];
}

const char* getShortSuitName(int s) {
  return ShortSuitNames[s];
}

void printCard(card c) {
  printf(
    "%s%s ",
    getShortRankName(c.rank),
    getShortSuitName(c.suit)
  );
}

void printDeck(card *deck) {
  for(int c = 0; c < 52; c++) {
    if(deck[c].rank == 0) {
      break;
    }
    printCard(deck[c]);
  }
  puts("");
}

int main() {
  card *startingDeck = malloc(52 * sizeof(card));
  int index = 0;
  for(int r = 1; r <= RankLength; r++) {
    for(int s = 1; s <= SuitLength; s++) {
      card myCard = { r, s-1 };
      startingDeck[index++] = myCard;
      printDeck(startingDeck);
    }
  }
  free(startingDeck);
}
