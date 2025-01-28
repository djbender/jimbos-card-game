#include <stdio.h>

const char *CARD_VALUES[] = {
  "2",
  "3",
  "4",
  "5",
  "6",
  "7",
  "8",
  "9",
  "10",
  "JACK",
  "QUEEN",
  "KING",
  "ACE"
};
const int CARD_SIZE = sizeof(CARD_VALUES) / sizeof(CARD_VALUES[0]);

const char *SUITS[] = {
  "CLUB",
  "DIAMOND",
  "HEART",
  "SPADE"
};
const int SUITS_SIZE = sizeof(SUITS) / sizeof(SUITS[0]);

int main() {

  printf("size: %d\n", (int)(sizeof(CARD_VALUES) / sizeof(CARD_VALUES[0])));
  for(int i = 0; i < CARD_SIZE; i++) {
    printf("Entry: %s\n", CARD_VALUES[i]);
  }
  for(int i = 0; i < SUITS_SIZE; i++) {
    printf("Entry: %s\n", SUITS[i]);
  }
  for(int i = 0; i < CARD_SIZE; i++) {
    for(int j = 0; j < SUITS_SIZE; j++) {
      printf("Card: %s of %s\n", CARD_VALUES[i], SUITS[j]);
    }
  }
}
