/****************************
Filename: 1-MileAndKilometerConverter.c
Name: Blakely North
Date Last Edited:
Brief Description:
gcc -Wall -Wextra -O -ansi -pedantic -o a 1-MileAndKilometerConverter.c
****************************/
/*printf, scanf*/
#include <stdio.h>
/*rand, srand*/
#include <stdlib.h>
/*time*/
#include <time.h>

int main(void)
{
    /* i is for the og distance, j is for the result. */
    float i, j;
    /* User input. Is ither M/m or K/k.*/
    char KmOrMi = 'k';

    printf("What do you want to convert to?\nInput K for kilometers or M for miles.\n");
    KmOrMi = getchar();

    switch (KmOrMi)
    {
    case 'k':
    case 'K':
        printf("How many miles?\n");
        scanf("%f", &i);
        j = i * 1.609344;
        printf("%f miles is %f kilometers\n", i, j);
        return 0;

    case 'm':
    case 'M':
        printf("How many kilometers?\n");
        scanf("%f", &i);
        j = i * 0.621371;
        printf("%f kilometers is %f miles\n", i, j);
        break;

    default:
        printf("Please input a valid response (K or M).\n");
        break;
    }

    return 0;
}
