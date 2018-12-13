/****************************
Filename: 6.5-PyramidGenerator.c
Name: Blakely North
Date Last Edited:
Brief Description:
gcc -Wall -Wextra -O -ansi -pedantic -o a 6.5-PyramidGenerator.c
****************************/
/*printf, scanf*/
#include <stdio.h>
/*rand, srand*/
#include <stdlib.h>
/*time*/
#include <time.h>

int main(void)
{
    int x = 0, px = x, j, i, input, amntOfStars, amntOfSpaces;
    printf("How tall should the pyramid be?");
    scanf("%i", &input);
    for (amntOfSpaces = input - 1, i = 0; i < input; i++, amntOfSpaces--)
    {         
        px = x, amntOfStars = (x * x - px * px);
        for (j = 0; j < amntOfStars; j++)
        {
            putchar('*');
        }
        for (j = 0; j < amntOfSpaces; j++)
        {
            putchar('\n');
        }
        putchar('\n');
    }
    while (getchar() != '\n');
    return 0;
}