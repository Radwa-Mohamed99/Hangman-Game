#ifndef PROJ1_H
#define PROJ1_H

typedef enum {
    false, //0
    true   //1
}bool;

typedef struct {
    char word[100];  
    char hint[300]; 
} WordWithHint;

WordWithHint getRandomarr(WordWithHint arr[], int size);

void DisplayWord(const char word[], const bool guessed[]);

bool isAlreadyGuessed(const char guess, const char previousGuesses[], int numGuesses);

void DrawHangman(int tries);

#endif
