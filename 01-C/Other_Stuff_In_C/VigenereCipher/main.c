/******************************
 * Filename: NewFile.c
 * Name: Blakely North
 * Date Last Edited: 1-22-2019
 * Brief: The test file to use with vigenereCipher.c.  You will need to set it up to take input from the console for both the string to encrypt and the key to encrypt with, please use the provided arrays!  After encrypting also test the decrypting! 
 * Brief Description: Program shows printing out a string with a pointer
 * gcc -Wall -Wextra -O -ansi -pedantic -o NewFile NewFile.c
 ******************************/
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
	for (i = 0; i < passes; i++, string[i] = ((string[i] + key[i % keylen]) % 26) + 'A');
	/*print out the encoded string*/
	printf("The encrypted phrase is:\n%s", string);
	/*now reverse it back to normal by setting it to decode and print it out again*/

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