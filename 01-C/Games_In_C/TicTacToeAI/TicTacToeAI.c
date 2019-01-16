/****************************
Filename: TicTacToeAI.c
Name: Blakely North
Date Last Edited: 1-15-2019
Brief Description: TicTacToe with AI for the second AP Project practice.
gcc -Wall -Wextra -O -ansi -pedantic -o TicTacToeAI TicTacToeAI.c
****************************/
/*printf, scanf*/
#include <stdio.h>
/*rand, srand*/
#include <stdlib.h>
/*time*/
#include <time.h>

#define TRUE 1
#define FALSE 0
/* Max length of the player's name*/
#define NAMEMAXLENGTH 10

/*function will need to look at the board and determine if there is a winner or if it is a tie*/
int CheckGrid(int board[][3]);
/*print out the board for the players*/
void printBoard(int board[][3]);

int main(void)
{
	/* Keeps track of who's turn it is. 0 means it's not the player's turn (AI's turn). 1 Means it is the player's turn (not the AI's turn).*/
	int playerTurn = 1;
	/* The player/AI input */
	int input;
	/* The game board. -1 is not occupied, 0 is O, 1 is X */
	int board[3][3] = {{-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}};
	/* Wether somone has won yet. (-1 = no win yet, 0 = AI won, 1 = Player won, 2 = Tie) */
	int gamestate = -1;
	char playerName[NAMEMAXLENGTH] = {'P','l','a','y','e','r'};
	printf("Welcome to TicTacToe AI edition.\nPlease enter a player name with less than %i characters: ", NAMEMAXLENGTH);
	scanf("%s", playerName);
		/* */
	while (gamestate == -1)
	{
		if (playerTurn == 1)
			printf("Your turn, %s", playerName);
		else
			AITurn(board[3][3]);
		do
		{
			scanf("%i", &input);
			if (input > 0 && input <= 9 && board[input / 3][input % 3] == -1)
			{
				/*legal input found*/
				board[input / 3][input % 3] = playerTurn;
				break;
			}
			printf("Invalid Input\n");
			while (getchar() != '\n');
		}while(0 != 0);
		playerTurn = !playerTurn;
		gamestate = CheckGrid(board);
	}
	printBoard(board);
	/* Who's the winner? */
	switch (gamestate)
	{
	case 0:
		printf("AI Wins.\n");
		break;
	case 1:
		printf("%s Wins!\n", playerName);
		break;
	case 2:
		printf("Tie!\n");
		break;
	}
	return 0;
}

/*function will need to look at the board and determine if there is a winner or if it is a tie*/
int CheckGrid(int board[3][3])
{
	int i, j;

	/*horizontal loop through all on one row*/
	for (i = 0; i < 3; i++)
		if (board[i][0] != -1 && board[i][0] == board[i][1] && board[i][1] == board[i][2])
			return board[i][0];

	/*verticle loop through all on one column*/
	for (j = 0; j < 3; j++)
		if (board[0][j] != -1 && board[0][j] == board[1][j] && board[1][j] == board[2][j])
			return board[0][j];
	/*diagonals check all at once*/

	if (board[0][0] != -1 && board[0][0] == board[1][1] && board[1][1] == board[2][2])
		return board[1][1];

	/*other diagonal*/
	if (board[0][2] != -1 && board[0][2] == board[1][1] && board[1][1] == board[2][0])
		return board[1][1];

	/*make sure not tie*/
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			/* -1 means the game isn't done */
			if (board[i][j] == -1)
				return -1;

	/*it is a tie if it gets here*/
	return 2;
}

/*print out the board for the players*/
void printBoard(int board[][3])
{
	int i, j;
	for (i = 0; i < 3; i++)
	{
		printf("|");
		for (j = 0; j < 3; j++)
		{
			switch (board[i][j])
			{
			case -1:
				printf(" %i |", i * 3 + j);
				break;
			case 0:
				printf(" O |");
				break;
			case 1:
				printf(" X |");
				break;
			}
		}
		printf("\n\n");
	}
	return;
}
