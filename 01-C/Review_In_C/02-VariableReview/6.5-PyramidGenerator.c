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
    int x = 1, j, i, input, amntOfSpaces;
    printf("How tall should the pyramid be? ");
    scanf("%i", &input);
    for (i = 0, j = 0; i < input; i++, amntOfSpaces--)
    {
        for (j = 0, x += 2; j < x; j++)
        {
            putchar('*');
        }
        /*
        for (j = 0; j < amntOfSpaces; j++)
        {
            putchar('\n');
        }
        */
        putchar('\n');
    }
    return 0;
}