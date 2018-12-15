/****************************
Filename: 6.5-PyramidGenerator.c
Name: Blakely North
Date Last Edited:
Brief Description:
<<<<<<< HEAD:01-C/Review_In_C/02-VariableReview/7-PyramidGenerator.c
gcc -Wall -Wextra -O -ansi -pedantic -o a 7-PyramidGenerator.c
=======
gcc -Wall -Wextra -O -ansi -pedantic -o a 6.5-PyramidGenerator.c
>>>>>>> 72372473dd912178770ac568bba1f675ec3028d0:01-C/Review_In_C/02-VariableReview/6.5-PyramidGenerator.c
****************************/
/*printf, scanf*/
#include <stdio.h>
/*rand, srand*/
#include <stdlib.h>
/*time*/
#include <time.h>

int main(void)
{
<<<<<<< HEAD:01-C/Review_In_C/02-VariableReview/7-PyramidGenerator.c
    int x = 0, j, i, input, amntOfStars, amntOfSpaces;
    printf("How tall should the pyramid be?");
    scanf("%i", &input);
    for (i = 0; i < input; i++, amntOfSpaces--)
    {
        for (j = 0; j < amntOfStars; j++)
        {
            putchar('*');
        }
=======
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
>>>>>>> 72372473dd912178770ac568bba1f675ec3028d0:01-C/Review_In_C/02-VariableReview/6.5-PyramidGenerator.c
        putchar('\n');
    }
    return 0;
}