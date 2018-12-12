/****************************
Filename: 2-GuessingGame.c
Name: Blakely North
Date Last Edited:
Brief Description:
gcc -Wall -Wextra -O -ansi -pedantic -o a 2-GuessingGame.c
****************************/
/*printf, scanf*/
#include <stdio.h>
/*rand, srand*/
#include <stdlib.h>
/*time*/
#include <time.h>

/* generate a random number */
int randomnum(int low, int high)
{
    int RNDNum;
    RNDNum = rand() % ((high + 1) - low) + low;
    return RNDNum;
}

int main(void)
{
    /* 
    /* low and high values*/
    int low = 0, high;
    /* rnd output*/
    int RNDNum;
    /* user input*/
    int input;
    /* when tho exit? */
    int exit = 0;
    while (exit == 0)
    {
        printf("What is the highest value that you want to guess to?\n");
        high = getchar();
        srand(time(NULL));
        RNDNum = randomnum(low, high);
        printf("Input your guess:");
        input = getchar();

        if (input < RNDNum)
            printf("Lower.\n");

        else if (input > RNDNum)
            printf("Higher\n");

        else if (input == RNDNum)
            exit = printf("Correct!\n");
    }
    
    return 0;
}
