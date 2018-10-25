/******************************************************************************
Filename: array.c
Author: Blakely North
Date: 10-22-18
Brief Description: This is the math that powers the other two c files
gcc -Wall -Wextra -O -ansi -pedantic -o array1 main1.c array.c
gcc -Wall -Wextra -O -ansi -pedantic -o C:\Users\Blakely\Documents\GitHub\DigiPen-Stuff\ArraysAndVectorMathInC\array1 C:\Users\Blakely\Documents\GitHub\DigiPen-Stuff\ArraysAndVectorMathInC\main1.c C:\Users\Blakely\Documents\GitHub\DigiPen-Stuff\ArraysAndVectorMathInC\array.c
******************************************************************************/

/* frusterate */
void reverse_array(int a[], int size)
{
  int i, temp2, temp, csize, k[size];
  for (i = 0, csize = size ;i < (size / 2); ++i, --csize)
  {
    temp = a[csize];
    temp2 = a[i];
    a[i] = temp;
    a[csize] = temp2;
  }
}

/**/
void add_arrays(const int a[], const int b[], int c[], int size)
{
  int i;
  for (i = 0; size > i ; i++)
  {
    c[i] = a[i] + b[i];
  }
}

/**/
void scalar_multiply(int a[], int size, int multiplier)
{
  int i = 0;
  for (; size > i; i++)
  {
    a[i] *= multiplier;
  }
}

/**/
int dot_product(const int a[], const int b[], int size)
{
  int i = 0;
  int result = 0;
  for (; i < size; i++)
  {
    result += a[i] * b[i];
  }
}

/**/
void cross_product(const int a[], const int b[], int c[])
{
  /* check if each variable is above 2 if so set to 0 */

  c[0] = a[1]*b[2] - a[2]*b[1];

  c[1] = -(b[2]*a[0] - b[0]*a[2]);

  c[2] = a[0]*b[1] - a[1]*b[0];
}
