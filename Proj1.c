#include "Proj1.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

WordWithHint getRandomarr(WordWithHint arr[], int size) {
   srand(time(NULL)); 
   int index = rand() % size;
   return arr[index]; 
}

void DisplayWord(const char word[], const bool guessed[]) {
   for (int i = 0; word[i] != '\0'; i++) { 
      if (guessed[i]) {
         printf("%c", word[i]);
      } else {
         printf("_ ");
      }
   }
   printf("\n");
}

bool isAlreadyGuessed(char guess, const char* previousGuesses, int numGuesses) {
    for (int i = 0; i < numGuesses; i++) {
        if (previousGuesses[i] == guess) {
            return true; // Letter already guessed
        }
    }
    return false; // Letter not guessed yet
}

void DrawHangman(int tries) {
   switch (tries) {
      case 3:
         printf("  +---+\n");
         printf("  |   |\n");
         printf("      |\n");
         printf("      |\n");
         printf("      |\n");
         printf("      |\n");
         printf("=========\n");
         break;

      case 2:
         printf("  +---+\n");
         printf("  |   |\n");
         printf("  O   |\n");
         printf("      |\n");
         printf("      |\n");
         printf("      |\n");
         printf("=========\n");
         break;

      case 1:
         printf("  +---+\n");
         printf("  |   |\n");
         printf("  O   |\n");
         printf(" /|\\  |\n");
         printf("      |\n");
         printf("      |\n");
         printf("=========\n");
         break;

      case 0:
         printf("  +---+\n");
         printf("  |   |\n");
         printf("  O   |\n");
         printf(" /|\\  |\n");
         printf(" / \\  |\n");
         printf("      |\n");
         printf("=========\n");
         break;
   }
}
