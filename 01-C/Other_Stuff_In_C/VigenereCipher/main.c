/****************
main.c
By:
Date: 
Brief: The test file to use with vigenereCipher.c.  You will need to set it up to take input from the console for both the string to encrypt and the key to encrypt with, please use the provided arrays!  After encrypting also test the decrypting! 
gcc -O -Wall -Wextra -ansi -pedantic -o vcipher vigenereCipher.c main.c
****************/
#include <stdio.h>
#include "vigenereCipher.h"

int main(void)
{
	unsigned char string[256];
	unsigned char key[32];
	int i, passes, *k, keylen, stringlen;

	/*ask for the string to encrypt and store it in string*/
	printf("What phrase do you want to encrypt?\n>");
	scanf(" %s", string);
	
	/*ask for the key to encrypt with and store it in key*/
	printf("What encryption key do you want to use?\n>");
	scanf(" %s", key);
	*k = key;
	for (i = 0; *k != '\0'; ++keylen, ++k);

	/*ask for how many passes to encrypt with*/
	printf("How many passes to do?\n>");
	scanf(" %i", passes);
	*k = string;
	for (i = 0; *k != '\0'; ++stringlen, ++k);
	/*encrypt string with the key, make sure set to encode!*/
	for (j = 0, i = 0; i < passes; i++, (int)string[i] += (key[i % 26]));
	/*print out the encoded string*/
	printf("The encrypted phrase is:\n%s", string);
	/*now reverse it back to normal by setting it to decode and print it out again*/

	return 0;
}