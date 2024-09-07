#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h> 
#include "Proj1.h"

#define ARRAY_SIZE 26 
#define MAX_TRIES 3

int main() {
    int tries = MAX_TRIES; // Number of tries allowed
    WordWithHint arr[ARRAY_SIZE] = {
        {"Ant", "The tiny creature that proves that good things come in small, hardworking packages"},
        {"Book", "The magical portal that lets you live a thousand lives without ever leaving your chair"},
        {"Coffee", "The magical potion that turns 'I need sleep' into 'I can conquer the world'"}, 
        {"Desk", "The surface that holds your clutter and your dreams of being more organized"},
        {"Elevator", "The small room that takes you up and down"},
        {"Fridge", "The box that keeps your food fresh and always seems to surprise you with hidden treasures"},
        {"Guitar", "The instrument that turns a quiet room into a karaoke session (whether you're good or not)"},
        {"Headphones", "The devices that turn any moment into a personal concert, and help you ignore the world around you"},
        {"Ice Cream", "The dessert that makes all our problems disappear, one spoonful at a time"},
        {"Joke", "The thing that everyone pretends to laugh at during lecture, even if it’s not that funny"},
        {"Keyboard", "The tool that transforms your thoughts into typed words, and occasionally a place for snack crumbs"},
        {"Lamp", "The thing that makes everything look better, even if it's actually just a mess"}, 
        {"Mirror", "The object that makes you question if your hairstyle is actually a work of art or a morning mess"}, 
        {"Notebook", "The item that holds all your best ideas and doodles that never actually get put into action"}, 
        {"Oven", "The box that turns raw ingredients into delicious meals while you wonder how anyone survived before it existed"}, 
        {"Pillow", "The fluffy object that’s your best friend during movie marathons and nap time"},
        {"Question", "The thing we dread when there's a surprise us from the instructor"}, 
        {"Remote", "The device that gives you the power to change the channel, but also causes endless arguments over what to watch"},
        {"Socks", "The items that always seem to disappear in the laundry but make you feel like a grown-up when you finally find a matching pair"}, 
        {"Tea", "The hot beverage that helps you pretend you’re sophisticated"}, 
        {"University", "A place where we hate to go :((("}, 
        {"Vacation", "The break that makes you wish every day could be spent lounging and relaxing, no matter where you are"}, 
        {"Wallet", "The small item that holds your money, IDs, and receipts you forgot to throw away"}, 
        {"Xylophone", "The colorful instrument that makes you feel like a child prodigy, even if you can’t play a note"}, 
        {"Yawn", "The universal sign that you need more sleep"}, 
        {"Zoom", "The video conferencing tool that turned every meeting into a chance to master the art of 'pretending to listen'"}
    };

    // Get a random word and its hint
    WordWithHint randomArr = getRandomarr(arr, ARRAY_SIZE);
    const char* word = randomArr.word; // Get the random word
    int wordLength = strlen(word);
    
    bool guessed[wordLength]; // Array to track guessed letters
    memset(guessed, false, sizeof(guessed)); // Initialize the guessed array with false
    
    char gusseLetters[100]; // Array to store guessed letters
    char previousGuesses[100] = {0}; // Array to store previous guesses
    int numGuesses = 0; // Number of guesses made
    bool wordGuessed = false;

    puts("HANGMAN GAME ^_^"); // Start the game

    printf("We will help you with a hint: %s\n", randomArr.hint); // Display the hint

    DisplayWord(word, guessed); // Display the initial state of the word

    while (tries > 0 && !wordGuessed) {
        printf("Guess the letters: ");
        scanf("%s", gusseLetters); 

        // Convert all entered letters to lowercase
        for (int j = 0; j < strlen(gusseLetters); j++) {
            char currentGuess = tolower(gusseLetters[j]); // Convert to lowercase

            if (isAlreadyGuessed(currentGuess, previousGuesses, numGuesses)) {
                printf("Repeated, try again\n");
                continue;
            }

            previousGuesses[numGuesses++] = currentGuess;

            bool correctGuess = false;
            for (int i = 0; i < wordLength; i++) {
                if (tolower(word[i]) == currentGuess) { // Convert to lowercase
                    guessed[i] = true;
                    correctGuess = true;
                }
            }

            if (correctGuess) {
                printf("Nice guess!\n");
            } else {
                printf("Wrong guess.\n");
                tries--; // Decrease tries on wrong guess
            }
        }

        DisplayWord(word, guessed); // Display the updated word
        DrawHangman(tries); // Display the hangman

        // Check if the word has been fully guessed
        wordGuessed = true;
        for (int i = 0; i < wordLength; i++) {
            if (!guessed[i]) {
                wordGuessed = false;
                break;
            }
        }
    }

    // Display the result of the game
    if (wordGuessed) {
        printf("Yaaaaaaaayy, you guessed it right!\n");
    } else {
        printf("You ran out of trials.\n");
    }

    return 0;
}
