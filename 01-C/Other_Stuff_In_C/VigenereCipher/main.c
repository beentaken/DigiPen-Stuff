/******************************
 * Filename: main.c
 * Name: Blakely North
 * Date Last Edited: 1-22-2019
 * Brief: The test file to use with vigenereCipher.c.  You will need to set it up to take input from the console for both the string to encrypt and the key to encrypt with, please use the provided arrays!  After encrypting also test the decrypting! 
 * Brief Description: Program shows printing out a string with a pointer
   gcc -Wall -Wextra -O -ansi -pedantic -o main main.c
 ******************************/
#include "vigenereCipher.h"

int main(void)
{
	unsigned char string[256];
	unsigned char key[32];
	int i = 0, passes, keylen, stringlen, method;
	char _case;

	printf("Encode (0) or decode (1)?");
	scanf(" %i", &method);
	if (method == ENCODE)
	{
		/*ask for the string to encrypt and store it in string*/
		printf("What phrase do you want to encrypt?\n>");
		fgets((char*)string, 256, stdin);

		/*ask for the key to encrypt with and store it in key*/
		printf("What encryption key do you want to use?\n>");
		fgets((char *)key, 32, stdin);

		/*ask for how many passes to encrypt with*/
		printf("How many passes to do?\n>");
		scanf(" %i", &passes);

		stringlen = strlen((char *)string);
		keylen = strlen((char *)key);
		/*encrypt string with the key, make sure set to encode!*/
		if (string[i] >= 'a')
			_case = 'a';
		else
			_case = 'A';

		for (passes *= stringlen; i < passes; string[i % stringlen] += ((key[i % keylen] - _case) % 26) + _case, ++i)
		{
			if ((string[i % stringlen] >= 'a') && ((string[i % stringlen] <= 'z')))
				_case = 'a';
			else if ((string[i % stringlen] >= 'A') && (string[i % stringlen] <= 'Z'))
				_case = 'A';
			else if (string[i % stringlen] == ' ')
				_case = ' ';
			else
			{
				printf("Error. Only capital letters, lowercase letters, and spaces are allowed.");
				break;
			}
		}
		printf("The encrypted phrase is:\n%s", string);
		/*now reverse it back to normal by setting it to decode and print it out again*/
	}
	else if(method == DECODE)
	{
		/*ask for the string to decrypt and store it in string*/
		printf("What phrase do you want to decrypt?\n>");
		scanf(" %s", string);
		
		/*ask for the key to decrypt with and store it in key*/
		printf("What encryption key do you want to use?\n>");
		scanf(" %s", key);

		/*ask for how many passes to decrypt with*/
		printf("How many passes to do?\n>");
		scanf(" %i", passes);

		stringlen = strlen(string);
		keylen = strlen(key);
		/*decrypt string with the key, make sure set to encode!*/

		if (string[i] >= 'a')
			_case = 'a';
		else
			_case = 'A';

		for (passes *= stringlen; i < passes; string[i % stringlen] -= ((key[i % keylen] - _case) % 26) + _case, ++i)
		{
			if ((string[i % stringlen] >= 'a') && ((string[i % stringlen] <= 'z')))
				_case = 'a';
			else if ((string[i % stringlen] >= 'A') && (string[i % stringlen] <= 'Z'))
				_case = 'A';
			else if (string[i % stringlen] == ' ')
				_case = ' ';
			else
			{
				printf("Error. Only capital letters, lowercase letters, and spaces are allowed.");
				break;
			}
			
		}		
		printf("The decrypted phrase is:\n%s", string);
	}
	else
	printf("error")
	

	/******* Not my work below - Just a sample to work off incase I need help that I found on the Internet *******/

	/*#include<stdio.h>
 *#include<string.h>
 *
 *int main(){
 *    char msg[] = "THECRAZYPROGRAMMER";
 *    char key[] = "HELLO";
 *    int msgLen = strlen(msg), keyLen = strlen(key), i, j;
 *
 *    char newKey[msgLen], encryptedMsg[msgLen], decryptedMsg[msgLen];
 *
 *    //generating new key
 *    for(i = 0, j = 0; i < msgLen; ++i, ++j){
 *        if(j == keyLen)
 *            j = 0;
 *
 *        newKey[i] = key[j];
 *    }
 *
 *    newKey[i] = '\0';
 *
 *    //encryption
 *    for(i = 0; i < msgLen; ++i)
 *        encryptedMsg[i] = ((msg[i] + newKey[i]) % 26) + 'A';
 *
 *    encryptedMsg[i] = '\0';
 *
 *    //decryption
 *    for(i = 0; i < msgLen; ++i)
 *        decryptedMsg[i] = (((encryptedMsg[i] - newKey[i]) + 26) % 26) + 'A';
 *
 *    decryptedMsg[i] = '\0';
 *
 *    printf("Original Message: %s", msg);
 *    printf("\nKey: %s", key);
 *    printf("\nNew Generated Key: %s", newKey);
 *    printf("\nEncrypted Message: %s", encryptedMsg);
 *    printf("\nDecrypted Message: %s", decryptedMsg);
 *
 *        return 0;
 *}	
 */
	return 0;
}