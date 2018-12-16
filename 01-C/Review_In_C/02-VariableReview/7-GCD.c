/****************************
Filename: GCD.c
Name: Blakely North
Date Last Edited:
Brief Description:
gcc -Wall -Wextra -O -ansi -pedantic -o a GCD.c
****************************/
/*printf, scanf*/
#include <stdio.h>
/*rand, srand*/
#include <stdlib.h>
/*time*/
#include <time.h>

/******************************
Actions to be Performed


1----------
Assign the larger number to M, and the smaller number to N.


2-----------
Divide M by N (M/N) and assign the remainder to R.


3-----------
If R is not 0, then assign the value of N to M, assign the value of R to N, and return to 

If R = 0, then the GCD is N and the algorithm terminates.

*****************************************/

int main(void)
{
	char exit = 'n';
	do
	{
		int M, N, R;
		printf("Enter two numbers with a space between them.\n");
		scanf("%i %i", &M, &N);
		do
		{
			/* Assign the larger number to M, and the smaller number to N. */
			if (M < N)
				R = M, M = N, N = R, R = 0;
			/* Divide M by N (M/N) and assign the remainder to R. */
			R = M % N;
			/*If R is not 0, then assign the value of N to M, assign the value of R to N, and return to  step 2*/
			if (R != 0)
				M = N, N = R;
			/* If R = 0, then the GCD is N and the algorithm terminates.*/
			else
				printf("The GCD is %i", N);
		} while (R != 0);
		printf("Do you want to exit? [y/N]");
		scanf("%c", &exit);

	} while (exit == 'n' || exit == 'N');
	return 0;
}
