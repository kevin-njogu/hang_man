#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 2


int findMissingChars(char *pDisplayWord);
void gameEngine(char *pUserInput, char *pUserSolution, int missingChars);
void compareSolutions(char *pSolution, char *pSecretWord, char *pUserInput, int missingChars, char *pDisplayWord);
void retry(char *pSolution, char *pUserInput, int missingChars, char *pSecretWord, char *pDisplayWord);


int findMissingChars(char *pDisplayWord)
{
    int count = 0;
    for (int i = 0; pDisplayWord[i] != '\0'; i++)
    {
        if (pDisplayWord[i] == '-')
            count++;
    }
    return count;
}


void gameEngine(char *pUserInput, char *pUserSolution, int missingChars)
{
    int dashCounter = 0;
    for (int i = 0; i < missingChars; i++) {
        printf("Enter char: ");
        scanf(" %c", &pUserInput[i]);
    }

    for (int i = 0; i < strlen(pUserSolution); i++)
    {
        if (pUserSolution[i] == '-')
        {
            pUserSolution[i] = pUserInput[dashCounter];
            dashCounter++;
        }
    }
}


void compareSolutions(char *pSolution, char *pSecretWord, char *pUserInput, int missingChars, char *pDisplayWord)
{
    int result = strcmp(pSolution, pSecretWord);

    if (result == 0)
        printf("You win, the man does not hang!!\n");
    else
        retry(pSolution, pUserInput, missingChars, pSecretWord, pDisplayWord);

}


void retry(char *pSolution, char *pUserInput, int missingChars, char *pSecretWord, char *pDisplayWord)
{
    int tries = 2;

    while (tries > 0)
    {
        printf("Incorrect, please try again!!!\n");
        strcpy(pSolution, pDisplayWord);
        gameEngine(pUserInput, pSolution, missingChars);
        if (strcmp(pSolution, pSecretWord) == 0)
        {
            printf("You win, the man does not hang!!\n");
            return;
        }
        tries--;
    }
    printf("You lose, the man hangs!!\n");
}


int main()
{
    char secretWord[] = {"secret"};
    char displayWord[] = {"-ecr-t"};

    int missingChars = findMissingChars(displayWord);
    char userInput[missingChars + 1];
    char userSolution[strlen(displayWord) + 1];

    strcpy(userSolution, displayWord);

    printf("The word is %s. Please fill in the missing charcters.\n", displayWord);
    printf("You have three attempts!!\n");

    gameEngine(userInput, userSolution, missingChars);
    compareSolutions(userSolution, secretWord, userInput, missingChars, displayWord);

    return 0;
}
