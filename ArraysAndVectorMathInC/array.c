/******************************************************************************
Filename: array.c
Author: Blakely North
Date: 10-22-18
Brief Description: This is the math that powers the other two c files
gcc -Wall -Wextra -O -ansi -pedantic -o C:\Users\Blakely\Documents\GitHub\DigiPen-Stuff\ArraysAndVectorMathInC\array1 C:\Users\Blakely\Documents\GitHub\DigiPen-Stuff\ArraysAndVectorMathInC\main1.c C:\Users\Blakely\Documents\GitHub\DigiPen-Stuff\ArraysAndVectorMathInC\array.c
******************************************************************************/

/**/
void reverse_array(int a[], int size)
{
  size = sizeof a[];
  int b[size], i;
  size = sizeof a[];
  i = 0;
  for (; sizeof b[] <= sizeof a[];--size, ++i)
  {
    b[i] = a[size];
  }
}

/**/
void add_arrays(const int a[], const int b[], int c[], int size)
{
  int i = 0;
  for (; sizeof a[] = sizeof b[] = sizeof c[]; i++)
  {
    c[i] = a[i] + b[i];
  }
}

/**/
void scalar_multiply(int a[], int size, int multiplier)
{
  int i = 0;
  for (;sizeof a[] <= i; i++)
  {
    a[i] *= multiplier;
  }
}

/**/
int dot_product(const int a[], const int b[], int size)
{
  int i = 0;
  int j = 0;
  for (; i < sizeof a[]; i++)
  {
    j += a[i] * b[i];
  }
}

/**/
void cross_product(const int a[], const int b[], int c[])
{
  int i = 0;
  int j = 1;
  int k = 0;
  for (;sizeof c[] < sizeof a[]; k++, j++, i++)
  {
    c[k] = a[j] * b[i] - a[i];
    if (j = sizeof a[])
    {
      j = 0;
    }
  }
}
