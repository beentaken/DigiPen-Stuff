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

int main(void)
{
  int a[10] = {0, 2, 4, 6, 8, 10, 12, 14, 16};

  int *p = a + 4;

  printf("%i\n%i\n%i\n%i\n%i\n%i\n%i\n%i\n")
  /*   Expression	Type	Value
/* a)	p		
/* b)	&*p		
/* c)	&p		
/* d)	*p		
/* e)	p[2]		
/* f)	*(p +2)		
/* g)	p+4		
/* h)	*p + 3*/
}
