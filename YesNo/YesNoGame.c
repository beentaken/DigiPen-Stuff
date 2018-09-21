/****************************
Filename: YesNoGame.c
Name: Blakely North
Date Last Edited: 9-19-2018
Brief Description: Starting point for a yes no game
gcc -Wall -Wextra -O -ansi -pedantic -o yesnogame YesNoGame.c
****************************/
/*printf, scanf*/
#include <stdio.h>
/*rand, srand*/
#include <stdlib.h>
/*time*/
#include <time.h>
int main(void)
{
	/*valid inputs will be y, n, and q to quit*/
	char input;
	/*-1 descibes the starter event*/
	int eventID = -1;
	/*change this if you want to add more events*/
	int maxEventID = 4;
	/*Add other game variables here, this could include a currency, special event triggers, how far down a specific event chain they are, ect.*/


	/*EXAMPLE extra variable*/
	int event1Seq = 0;
	/*set random seed*/
	srand(time(NULL));
	/*Add the introduction to the game here, explain the rules to user */



	do
	{
		/*setting input to 'a' resets the input*/
		input = 'a';
		/*switch on the event, in each have something desribe what the options are (y/n)*/
		switch(eventID)
		{
			case -1:
				printf("You wake up on a beach. The last thing you remember is a plane crash.\n You stand up. Suddenly, you feel a sharp pain and notice a gash in your left leg. (Press 1 to continue) \n");
				break;
			case 0:
				printf("You see a beach and the ocean on your left and a pool of water on your right. Do you want to go go to the pool (1) pr the beach(2)?\n");
				break;
			case 1:
				printf("You gaze into the water. It looks clear. Do you want to wash your cut out? (1 is yes, 2 is no)\n");
				break;
			case 2:
			printf("You gaze into the water. It looks clear. Do you want to wash your cut out? (1 is yes, 2 is no)\n");
				break;
			case 3:

				break;
			case 4:

				break;
		}


		/*accept a character as input q quits everyting else should be n or y if none keep checking*/
		while(input != '1' && input != '2'&& input != 'q')
		{
			printf("\nEnter '1' for option one or '2' for option two ('q' to quit):\n");
			/*scanf goes here*/
			scanf(" %c", &input);

		}
		/*switch on the event change outcome based on input*/
		switch(eventID)
		{
			case -1:
				if(input == '1')
				{
					printf("\n");
					eventID = 0;
				}
				else if(input == '2')
				{
					printf("Rebel! I told you to press 1!\n");
					eventID = 0;
				}
				break;
			case 0:
				/*Add what happens in each answer down here, they can adjust variables*/
				if(input == '1')
				{
					printf("You go to the pool.\n");
					eventID = 2;
				}
				else if(input == '2')
				{
					printf("You choose the beach. \n");
					eventID = 1;
				}
				break;
			case 1:
				if(input == '1')
				{
					printf("You wash your cut out. Now, your cut is clean, and it has magically stopped bleeding.\n", );
					cleancut = 1;
					eventID = 6;
				}
				else if(input == '2')
				{
					printf("You decide not to wash your cut out.\n", );
					cleancut = 0;
					eventID = 5;
				}
				break;

			case 2:
				cleancut = 0;
				if(input == '1')
				{
					printf("Oh no! There was a parasite in the water and now you have an infection.\n", );
				}
				else if(input == '2')
				{
					printf("You decide not to wash your cut out.\n", );

				}
				break;

			case 3:
				if(input == '1')
				{

				}
				else if(input == '2')
				{

				}
				break;

			case 4:
				if(input == '1')
				{

				}
				else if(input == '2')
				{

				}
				break;
		}

		/*reset event id with rand*/
		/* eventID = rand() % (maxEventID + 1); */
		getchar();
		getchar();

	}while(input != 'q');


	return 0;
}
