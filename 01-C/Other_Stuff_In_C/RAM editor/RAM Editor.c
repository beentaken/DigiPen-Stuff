/****************************
Filename: NewFile.c
Name: Blakely North
Date Last Edited:
Brief Description:
gcc -Wall -Wextra -O -ansi -pedantic -o NewFile NewFile.c
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
  int address, i;
  
  return 0;
}
