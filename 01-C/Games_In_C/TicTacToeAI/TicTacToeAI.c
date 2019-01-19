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
int board[3][3] = {{-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}};

/*function will need to look at the board and determine if there is a winner or if it is a tie*/
int CheckGrid(int board[][3]);
/*print out the board for the players*/
void printBoard(int board[][3]);
/*what the ai does on its turn.*/
int AITurn(void);

/* board checkers */
int Horizontal(int o1, board[][3]);
int Vertical(int o1, board[][3]);
int DiagonalRight(int o1, board[][3]);
int DiagonalLeft(int o1, board[][3]);
int board[3][3] = {{-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}};

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
	char playerName[NAMEMAXLENGTH] = {'P', 'l', 'a', 'y', 'e', 'r'};
	printf("Welcome to TicTacToe AI edition.\nPlease enter a player name with less than %i characters: ", NAMEMAXLENGTH);
	scanf("%s", playerName);
	/* */
	while (gamestate == -1)
	{
		if (playerTurn == 1)
			printf("Your turn, %s", playerName);
		else
			input = AITurn();
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
			while (getchar() != '\n')
				;
		} while (0 != 0);
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

/*what the ai does on its turn.*/
int AITurn()
{
	int o1 = 1;
	/* c means x o means o, h means horizimtal, v means verticle, dl/dr means diagonal left (/) or diagonal right (\) */
	int x_h_count, o_h_count;
	int x_v_count, o_v_count;
	int x_dl_count, o_dl_count;
	int x_dr_count, o_dr_count;

	int pinput[3][3]; /* possible input, 0 means horizontal, 1 means vertical, 2 means (\) 3 means (/) */
	int input;
	int i, j;

	for (pinput)
	{
		/*See if there are 2 in a row*/
		/*horizontal loop through all on one row*/
		if (o1)
		{
			for (i = 0; i < 3; i++)
				o_h_count = Horizontal(o1, i, board[3][3]);
		}
		else
			for (i = 0; i < 3; i++)
				x_h_count = Horizontal(o1, i, board[3][3]);

		/*verticle loop through all on one column*/
		if (o1)
		{
			for (j = 0; j < 3; j++)
				if (board[0][j] != -1 && board[0][j] == board[1][j] && board[1][j] == board[2][j])
					Vertical(o1, i, board[3][3]);
		}
		else
		{
			for (j = 0; j < 3; j++)
				if (board[0][j] != -1 && board[0][j] == board[1][j] && board[1][j] == board[2][j])
					Vertical(o1, i, board[3][3]);
		}
		/*diagonal check (\)*/
		if (o1)
			o_dr_count = DiagonalRight(o1, board[3][3]);
		else
			x_dr_count = DiagonalRight(o1, board[3][3]);

		/*other diagonal (/)*/
		if (o1)
			o_dl_count = DiagonalLeft(o1, board[3][3]);
		else
			x_dl_count = DiagonalLeft(o1, board[3][3]);
		/*processing the results*/
		o1 = 2, i = 0;

		if (x_h_count == 2)
		{
			for (i = 0; i < 3; i++)
				if (Horizontal(o1, i, board[][3]) = 
					pinput[i][j]++;
		}
		if (x_h_count == 2)
			i = 0;

		if (x_h_count)
			i = 0;

		if (x_v_count == 2)
			i = 0;

		else if (o_v_count == 2)
			i = 0;

		if (x_dr_count)
			i = 0;

		if (x_dl_count)
			i = 0;
	}
	return input;
}

/* Checks what it says */
int Horizontal(int o1, i, board[][3])
{
	int x_h_count = 0,
		o_h_count = 0;
	/*horizontal loop through all on one row*/
	if (board[i][0] != -1 && board[i][0] == board[i][1] && board[i][1] == board[i][2])
	{
		if (board[i][0] != 1 && board[i][0] == board[i][1] && board[i][1] == board[i][2] && o1 == 0)
		{
			return x_h_count++;
		}
		else if (board[i][0] != 0 && board[i][0] == board[i][1] && board[i][1] == board[i][2] && o1 == 1)
		{
			return o_h_count++;
		}
	}
}

/* Checks what it says */

int Vertical(int o1, i, board[][3])
{
	int x_v_count = 0,
		o_v_count = 0;
	for (j = 0; j < 3; j++)
		if (board[0][j] != -1 && board[0][j] == board[1][j] && board[1][j] == board[2][j])
		{
			if (board[0][j] != 1 && board[0][j] == board[1][j] && board[1][j] == board[2][j] && o1 == 0)
			{
				return x_v_count++;
			}
			else if (board[0][j] != 0 && board[0][j] == board[1][j] && board[1][j] == board[2][j] && o1 == 1)

			{
				return o_v_count++;
			}
		}
}

/* Checks what it says */

int DiagonalRight(int o1, board[][3])
{
	int x_dr_count = 0,
		o_dr_count = 0;
	if (board[0][0] != -1 && board[0][0] == board[1][1] && board[1][1] == board[2][2])
	{
		if (board[0][j] != 1 && board[0][j] == board[1][j] && board[1][j] == board[2][j] && o1 == 0)
		{
			return x_dr_count++;
		}
		else if (board[0][j] != 0 && board[0][j] == board[1][j] && board[1][j] == board[2][j] && o1 == 1)

		{
			return o_dr_count++;
		}
	}
}

/* Checks what it says */

int DiagonalLeft(int o1, board[][3])
{
	int x_dl_count = 0,
		o_dl_count = 0;
	if (board[0][2] != -1 && board[0][2] == board[1][1] && board[1][1] == board[2][0])
	{
		if (board[0][j] != 1 && board[0][j] == board[1][j] && board[1][j] == board[2][j] && o1 == 0)
		{
			return x_dl_count++;
		}
		else if (board[0][j] != 0 && board[0][j] == board[1][j] && board[1][j] == board[2][j] && o1 == 1)

		{
			return o_dl_count++;
		}
	}
}
