/****************************
Filename: sieve.c
Name: Blakely North
Date Last Edited: 10-10-2018
Brief Description: Starting point for a yes no game
gcc -Wall -Wextra -O -ansi -pedantic -o sieve main.c sieve.c
****************************/

#include <stdio.h> /* printf      */
#include <math.h>  /* sqrt        */
#include "sieve.h" /* TRUE, FALSE */

/* this takes an array of ints of the given size and will fill it with true if the index number is prime false otherwise */
void sieve(int array[], int size)
{
  int i, j;
  /* 0 & 1 aren't prime */
  array[0] = array[1] = FALSE;
  /* loop and set all other #'s to true */
  for( i = 2 ; i <= size ; i++)
  {
    array[i] = TRUE;
  }
  /*loop through # and if still true, remove its multiples*/
  for (i = 2; i <= sqrt(size); i++)
  {
    /*check if i is prime*/
    if(array[i])
    {
      /*loop through remaining #'s and remove any multiples*/
      for (j = i+1 ; j <= size; j++)
      {
        /* check if j is divisible by i */
        if( j % i == 0)
        {
          array[j] = FALSE;
        }
      }
    }
  }
}

int twin_primes(const int primes[], int size)
{
  return 0;
}

double brun_constant(const int primes[], int size)
{
  return 0.0;
}

/**/
