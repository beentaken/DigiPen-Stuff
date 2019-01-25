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
int CheckGrid();
/*print out the board for the players*/
void printBoard();
/*what the ai does on its turn.*/
int AITurn();

/* board checkers */
int AIScan();
int Horizontal();
int Vertical();
int DiagonalRight(); /* (\) */
int DiagonalLeft(); /* (/) */
int pinputReset();
/* The game board. -1 is not occupied, 0 is O, 1 is X */
int board[3][3] = {{-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}};
/* Possible input array for AI */
int pinput[3][3];

/*
SCORING:
AI has 2 in a row      | + 1000 to blank
Player has ""          | + 10 to blank
AI has 1 with 2 blanks | + 3 to blanks
Player has ""          | + 2 to blanks
AI has not played yet  | + 1 to all 3 in a row blanks
*/

/* board pointer */
int *brdptr = &board[0][0];
int i = 0, j = 0;
int main(void)
{
	/* Keeps track of who's turn it is. 0 means it's not the player's turn (AI's turn). 1 Means it is the player's turn (not the AI's turn).*/
	int playerTurn = 1;
	/* The player/AI input */
	int input;
	/* Wether somone has won yet. (-1 = no win yet, 0 = AI won, 1 = Player won, 2 = Tie) */
	int gamestate = -1;
	char playerName[NAMEMAXLENGTH] = {'P', 'l', 'a', 'y', 'e', 'r'};
	printf("Welcome to TicTacToe AI edition.\nPlease enter a player name with less than %i characters: ", NAMEMAXLENGTH);
	scanf("%s", playerName);
	/* */
	printBoard();
	while (gamestate == -1)
	{
		if (playerTurn == 1)
			printf("Your turn, %s: ", playerName);
		else
			input = AITurn();
		scanf("%i", &input);
		if (input > 0 && input <= 9 && board[input / 3][input % 3] == -1)
		{
			/*legal input found*/
			board[input / 3][input % 3] = playerTurn;
			break;
		}
		while (getchar() != '\n')

			printf("Invalid Input\n");
		playerTurn = !playerTurn;
		gamestate = CheckGrid();
	}
	/* Who's the winner? */
	switch (gamestate)
	{
	case 0:
		printf("AI Wins!!!\n");
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
int CheckGrid()
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
void printBoard()
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

int pinputReset()
{
	int* p = &pinput[0][0];
	for(i = 0; i < 9; i++, p++)
		*p = 0;
	return 0;
}

int AIScan()
{
	Horizontal();
	Vertical();
	DiagonalRight();
	DiagonalLeft();
	return 0;
}
/*what the ai does on its turn.*/
int AITurn()
{
	/* Current biggest num's location in the array and the compairison's location */
	int *biggest = &pinput[0][0], *comp = &pinput[0][0];
	/* Reset pinput */
	pinputReset();
	/* check all possible plays */
	AIScan();
	/* Search pinput for the highest score */
	for (i = 0; i < 8; i++, comp++)
		if(*biggest < *comp)
			biggest = comp;
	return (biggest - &pinput[0][0]);
}

/* Checks what it says for 2 in a rows */
int Horizontal()
{
	/*horizontal loop through all on one row*/
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			/* Check for 2 plays in a row */
			if (((board[i][(j + 1) % 3] == 1 && /**/ (board[i][(j + 1) % 3] == /**/ board[i][(j + 2) % 3])) && /**/ board[i][(j + 3) % 3] == -1) /****/)
				pinput[i][(j + 3) % 3] += 1000;
			/* same check, but for player's moves */
			if (((board[i][(j + 1) % 3] == 0 && /**/ (board[i][(j + 1) % 3] == /**/ board[i][(j + 2) % 3])) && /**/ board[i][(j + 3) % 3] == -1) /****/)
				pinput[i][(j + 3) % 3] += 100;

			/* Check for a move with 2 blanks around it */
			if ((((board[i][(j + 1) % 3] == -1 && /**/ (board[i][(j + 1) % 3] == /**/ board[i][(j + 2) % 3])) && /**/ board[i][(j + 3) % 3] == 1)))
				pinput[i][(j + 1) % 3] += 3, pinput[i][(j + 2) % 3] += 3;
			/* same check, but for player's moves */
			if ((((board[i][(j + 1) % 3] == -1 && /**/ (board[i][(j + 1) % 3] == /**/ board[i][(j + 2) % 3])) && /**/ board[i][(j + 3) % 3] == 0)))
				pinput[i][(j + 1) % 3] += 2, pinput[i][(j + 2) % 3] += 2;
			
			/*check for 3 in a row blanks*/
			if ((((board[i][(j + 1) % 3] == -1 && /**/ (board[i][(j + 1) % 3] == /**/ board[i][(j + 2) % 3])) && /**/ board[i][(j + 3) % 3] == -1)))
				pinput[i][(j + 1) % 3]++, pinput[i][(j + 2) % 3]++, pinput[i][(j + 3) % 3]++;
		}
	return 0;
}

/* Checks what it says for 2 in a rows */

int Vertical()
{
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			/* Check for 2 plays in a row */
			if (((board[j][(i + 1) % 3] == 1 && /**/ (board[j][(i + 1) % 3] == /**/ board[j][(i + 2) % 3])) && /**/ board[j][(i + 3) % 3] == -1) /****/ )
				pinput[j][(i + 2) % 3] += 1000;
			/* same check, but for player's moves */
			if ((((board[j][(i + 1) % 3] == 0 && /**/ (board[j][(i + 1) % 3] == /**/ board[j][(i + 2) % 3])) && /**/ board[j][(i + 3) % 3] == -1)))
				pinput[j][(i + 1) % 3]++, pinput[j][(i + 2) % 3]++;

			/* Check for 2 plays in a row */
			if (((board[j][(i + 1) % 3] == -1 && /**/ (board[j][(i + 1) % 3] == /**/ board[j][(i + 2) % 3])) && /**/ board[j][(i + 3) % 3] == 1) /****/)
				pinput[j][(i + 1) % 3] += 3, pinput[j][(i + 2) % 3] += 3;
			/* same check, but for player's moves */
			if (((board[j][(i + 1) % 3] == -1 && /**/ (board[j][(i + 1) % 3] == /**/ board[j][(i + 2) % 3])) && /**/ board[j][(i + 3) % 3] == 0) /****/)
				pinput[j][(i + 1) % 3] +=2, pinput[j][(i + 2) % 3] += 2;

			/*check for 3 in a row blanks*/
			if (((board[j][(i + 1) % 3] == -1 && /**/ (board[j][(i + 1) % 3] == /**/ board[j][(i + 2) % 3])) && /**/ board[j][(i + 3) % 3] == -1) /****/)
				pinput[j][(i + 1) % 3]++, pinput[j][(i + 2) % 3]++, pinput[j][(i + 3) % 3]++;
		}
	return 0;
}
/* Checks what it says for 2 in a rows */

int DiagonalRight()
{
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			{
				/* Check for 2 plays in a row */
				if (((board[(i + 1) % 3][(j + 1) % 3] == 1 && /**/ (board[(i + 1) % 3][(j + 1) % 3] == /**/ board[(i + 2) % 3][(j + 3) % 3])) && /**/ board[(i + 3) % 3][(j + 2) % 3] == -1) /****/ )
					pinput[(i + 3) % 3][(j + 2) % 3] += 1000;
				/*player*/
				if (((board[(i + 1) % 3][(j + 1) % 3] == 0 && /**/ (board[(i + 1) % 3][(j + 1) % 3] == /**/ board[(i + 2) % 3][(j + 3) % 3])) && /**/ board[(i + 3) % 3][(j + 2) % 3] == -1) /****/)
					pinput[(i + 3) % 3][(j + 2) % 3] += 10;

				/* Check for a move with 2 blanks around it */
				if ((((board[(i + 1) % 3][(j + 1) % 3] == -1 && /**/ (board[(i + 1) % 3][(j + 1) % 3] == /**/ board[(i + 2) % 3][(j + 3) % 3])) && /**/ board[(i + 3) % 3][(j + 2) % 3] == 1)))
					pinput[(i + 1) % 3][(j + 1) % 3] += 3, pinput[(i + 2) % 3][(j + 3) % 3] += 3;
				/*player*/
				if ((((board[(i + 1) % 3][(j + 1) % 3] == -1 && /**/ (board[(i + 1) % 3][(j + 1) % 3] == /**/ board[(i + 2) % 3][(j + 3) % 3])) && /**/ board[(i + 3) % 3][(j + 2) % 3] == 0)))
					pinput[(i + 1) % 3][(j + 1) % 3] += 2, pinput[(i + 2) % 3][(j + 3) % 3] += 2;

				/*check for 3 in a row blanks*/
				if ((((board[(i + 1) % 3][(j + 1) % 3] == -1 && /**/ (board[(i + 1) % 3][(j + 1) % 3] == /**/ board[(i + 2) % 3][(j + 3) % 3])) && /**/ board[(i + 3) % 3][(j + 2) % 3] == -1)))
					pinput[(i + 1) % 3][(j + 1) % 3]++, pinput[(i + 2) % 3][(j + 3) % 3]++, pinput[(i + 3) % 3][(j + 2) % 3]++;
			}

	return 0;
}

/* Checks what it says for 2 in a rows */

int DiagonalLeft()
{
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			/* Check for 2 plays in a row */
			if (((board[(i + 3) % 3][(j + 1) % 3] == 1) && /**/ (board[(i + 3) % 3][(j + 1) % 3] == /**/ board[(i + 2) % 3][(j + 3) % 3])) /**/ && board[(i + 1) % 3][(j + 3) % 3] == -1)
				pinput[(i + 1) % 3][(j + 3) % 3] += 1000;
			/*player*/
			if (((board[(i + 3) % 3][(j + 1) % 3] == 0) && /**/ (board[(i + 3) % 3][(j + 1) % 3] == /**/ board[(i + 2) % 3][(j + 3) % 3])) /**/ && board[(i + 1) % 3][(j + 3) % 3] == -1)
				pinput[(i + 1) % 3][(j + 3) % 3] += 10;

			/* Check for a move with 2 blanks around it */
			if (((board[(i + 3) % 3][(j + 1) % 3] == -1) && /**/ (board[(i + 3) % 3][(j + 1) % 3] == /**/ board[(i + 2) % 3][(j + 3) % 3])) /**/ && board[(i + 1) % 3][(j + 3) % 3] == 1)
				pinput[(i + 3) % 3][(j + 1) % 3] += 3, pinput[(i + 2) % 3][(j + 3) % 3] += 3;
			/*player*/
			if (((board[(i + 3) % 3][(j + 1) % 3] == -1) && /**/ (board[(i + 3) % 3][(j + 1) % 3] == /**/ board[(i + 2) % 3][(j + 3) % 3])) /**/ && board[(i + 1) % 3][(j + 3) % 3] == 0)
				pinput[(i + 3) % 3][(j + 1) % 3] += 2, pinput[(i + 2) % 3][(j + 3) % 3] += 2;

			/*check for 3 in a row blanks*/
			if (((board[(i + 3) % 3][(j + 1) % 3] == -1) && /**/ (board[(i + 3) % 3][(j + 1) % 3] == /**/ board[(i + 2) % 3][(j + 3) % 3])) /**/ && board[(i + 1) % 3][(j + 3) % 3] == -1)
				pinput[(i + 3) % 3][(j + 1) % 3]++, pinput[(i + 2) % 3][(j + 3) % 3]++, pinput[(i + 1) % 3][(j + 3) % 3]++;
		}
	return 0;
}