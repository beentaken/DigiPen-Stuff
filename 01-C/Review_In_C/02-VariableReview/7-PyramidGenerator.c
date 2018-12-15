/****************************
Filename: 6-PyramidGenerator.c
Name: Blakely North
Date Last Edited:
Brief Description:
gcc -Wall -Wextra -O -ansi -pedantic -o a 7-PyramidGenerator.c
****************************/
/*printf, scanf*/
#include <stdio.h>
/*rand, srand*/
#include <stdlib.h>
/*time*/
#include <time.h>

int main(void)
{
    int x = 0, j, i, input, amntOfStars, amntOfSpaces;
    printf("How tall should the pyramid be?");
    scanf("%i", &input);
    for (i = 0; i < input; i++, amntOfSpaces--)
    {
        for (j = 0; j < amntOfStars; j++)
        {
            putchar('*');
        }
        putchar('\n');
    }
    while (getchar() != '\n');
    return 0;
}