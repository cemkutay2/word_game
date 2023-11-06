#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main()
{
    bool running = true;
    do{
        char playAgain;
        const char *words[] = {"cat", "dog", "house", "tree", "flower", "car", "bird", "fish", "apple", "orange", "banana", "grape", "strawberry", "blueberry", "lemon", "lime", "watermelon", "sun", "moon", "star", "rain", "snow"};

        // rng
        srand(time(NULL));
        int randNum = (rand() % (sizeof(words) / sizeof(words[0])));

        // get a random word from the words array
        const char *tempChar = words[randNum];
        char randWord[50];
        strcpy(randWord, tempChar);
        
        // create wordSpace array
        int wordLength = strlen(randWord);
        char wordSpace[wordLength];
        for (int i = 0; i < wordLength; i++)
        {
            wordSpace[i] = '_';
        }

        // game loop
        bool wordIsFound = false;
        bool wrongGuess = false;
        do
        {
            // clear screen
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            printf(wrongGuess ? "Wrong guess! Guess again:\n" : "Guess:\n");
            wrongGuess = false;
            char userGuess[100];

            // print out the main array
            for (int i = 0; i < wordLength; i++)
                printf("%c ", wordSpace[i]);

            // take a guess
            printf("\n\n");
            scanf("%s", &userGuess[0]);

            int inputLength = strlen(userGuess);
            char currentLetter = userGuess[0];
            
            // if word is found end loop
            if (strcmp(userGuess, randWord) == 0)
            {
                wordIsFound = true;
                continue;
            }
            else if (inputLength > 1)
            {
                wrongGuess = true;
                continue;
            }
            // change the main array
            for (int i = 0; i < wordLength; i++)
            {
                if (currentLetter == randWord[i])
                    wordSpace[i] = currentLetter;
            }
        } while (!wordIsFound);

        printf("Congrats! The word was: %s!\n",randWord);
        printf("\nDo you want to play again? (y/n)\n");
        scanf(" %c", &playAgain);
        running = playAgain == 'y' ? true : false;
    } while (running);
    return 0;
}