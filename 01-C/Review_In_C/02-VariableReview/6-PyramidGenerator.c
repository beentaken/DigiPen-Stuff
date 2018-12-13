/****************************
Filename: 6-PyramidGenerator.c
Name: Blakely North
Date Last Edited:
Brief Description:
gcc -Wall -Wextra -O -ansi -pedantic -o a 6-PyramidGenerator.c
****************************/
/*printf, scanf*/
#include <stdio.h>
/*rand, srand*/
#include <stdlib.h>
/*time*/
#include <time.h>

int main(void)
{
    /* i, k, and j are counters, input is for input, exit kills the program */
    int i = 1, j = 0, k, x = 0, px = x, input, spacesToPut = 0, starsToPut = 0, count = 0, exit = 0;
    while (exit == 0)
    {
        printf("How tall should the pyramid be?");
        scanf("%i", &input);
        count = (input * input) + input;
        for (spacesToPut -= input -1; j < (input * 2 - 1); j++, x++, spacesToPut--, starsToPut += 2)
        {            
            /* Puts spaces down */
            for (i += 2, spacesToPut--, starsToPut = (x * x - px * px); i < spacesToPut; i++)
            {
                putchar(' ');
            }
            /* Puts *'s down */
            for (k = i; i < starsToPut; i += 2, count--)
            {
                putchar('*');
            }
            putchar('\n');
            px = x;
        }
    }
    return 0;
}