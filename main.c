#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main()
{
    bool running = true;
    do
    {
        char playAgain;
        const char words[][15] = {"cat", "dog", "house", "tree", "flower", "car", "bird", "fish", "apple", "orange", "banana", "grape", "strawberry", "blueberry", "lemon", "lime", "watermelon", "sun", "moon", "star", "rain", "snow", "baby", "bed", "book", "chair", "cloud", "coffee", "computer", "door", "elephant", "eye", "family", "friend", "game", "girl", "hat", "ice cream", "jacket", "kangaroo", "kitchen", "knife", "leaf", "lion", "milk", "monkey", "mother", "mountain", "music", "night", "nose", "ocean", "pencil", "phone", "plant", "pizza", "rainbow", "river", "road", "rock", "school", "sea", "shirt", "shoe", "sky", "sofa", "spoon", "squirrel", "table", "teacher", "train", "TV", "umbrella", "water", "weather", "wind", "window", "zebra"};

        // rng
        srand(time(NULL));
        int randNum = (rand() % (sizeof(words) / sizeof(words[0])));

        // get a random word from the words array
        const char *tempChar = words[randNum];
        char randWord[15];
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
        bool userExit = false;
        do
        {
            // clear screen
            printf("\033[2J");
            
            printf(wrongGuess ? "Wrong guess! Guess again:\n" : "Guess:\n");
            wrongGuess = false;
            char userGuess[15];

            // print out wordSpace
            for (int i = 0; i < wordLength; i++)
                printf("%c ", wordSpace[i]);

            // take a guess
            printf("\n\n");
            scanf("%s", userGuess);

            int inputLength = strlen(userGuess);
            char currentLetter = userGuess[0];
            // user exit
            if (strcmp(userGuess, "exit") == 0)
            {
                userExit = true;
                continue;
            }

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
        } while (!wordIsFound && !userExit);
        if (!userExit)
        {
            printf("Congrats! The word was: %s!\n", randWord);
            printf("\nDo you want to play again? (y/n)\n");
            scanf(" %c", &playAgain);
            running = playAgain == 'y' ? true : false;
        }
        else
        {
            printf("Do you want to quit? (y/n)\n");
            scanf(" %c", &playAgain);
            running = playAgain == 'y' ? false : true;
        }
    } while (running);
    return 0;
}