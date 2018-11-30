/****************************
Filename: Maze.c
Name: Blakely North
Date Last Edited:11-26-18
Brief Description: Demonstrates some pointer stuff and multidimensional arrays. A maze Game.
gcc -Wall -Wextra -O -ansi -pedantic -o Maze Maze.c
****************************/
/*printf, scanf*/
#include <stdio.h>
/*rand, srand*/
#include <stdlib.h>
/*time*/
#include <time.h>

/* define the size of the map with these definitions */
#define MAPHEIGHT 28
#define MAPWIDTH 28
/* game value definitions */
#define ENEMYSIZE 2
/* set what characters are used to represent different things */
#define PLAYER '@'
#define ENEMY_ 'E'
#define FLOOR_ ' '
#define WALL__ 'X'
#define EXIT__ 'O'
#define ACHVMT '?'
#define STAIRS 'S'
/* have true and false values to be useful */
#define TRUE 1
#define FALSE 0
/* Waits until it sees a newline from the input stream */
void waitForEnter();
/* Prints out the map with all moving pieces shown on it */
void printMap(char map[][MAPHEIGHT][MAPWIDTH], char *player, char *enemies[]);

int main(void)
{
	/* map defining where all static things are, access with map[Y][X] */
	char map[2][MAPHEIGHT][MAPWIDTH] =
		{
			{
				{ WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__,},
				{ WALL__, WALL__, FLOOR_, FLOOR_, PLAYER, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__,},
				{ WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, ACHVMT, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, WALL__,},
				{ WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__,},
				{ WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, WALL__,},
				{ WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, STAIRS, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__,},
				{ WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, WALL__,},
				{ WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__,},
				{ WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__,},
				{ WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, STAIRS, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__,},
				{ WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, WALL__,},
				{ WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, WALL__,},
				{ WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, WALL__,},
				{ WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__,},
				{ WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__,},
				{ WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, WALL__,},
				{ WALL__, WALL__, STAIRS, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__,},
				{ WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__,},
				{ WALL__, WALL__, EXIT__, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, STAIRS, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__,},
				{ WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__,}
			},
			{
				{ WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__,},
				{ WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__,},
				{ WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, WALL__,},
				{ WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__,},
				{ WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__,},
				{ WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, STAIRS, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__,},
				{ WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, ACHVMT, FLOOR_, WALL__,},
				{ WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__,},
				{ WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__,},
				{ WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, STAIRS, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__,},
				{ WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, WALL__,},
				{ WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, WALL__,},
				{ WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__,},
				{ WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__,},
				{ WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, FLOOR_,},
				{ WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__,},
				{ WALL__, WALL__, STAIRS, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__,},
				{ WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__,},
				{ WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, STAIRS, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, STAIRS, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__,},
				{ WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__,}
			}
		};
	/* this variable determines how the player moves using pointer arithmetic */
	/* player is represented by a pointer pointing to where in the map it is currently */
	int playerMovement;
	/* formula for this location is *(map + Y) + X */
	char *player = *(map + 2) + 1;
	/* Alternative formula map[Y] + X */
	/* set this to TRUE if the player chooses to quit or the win condition or lose condition is reached */
	int exitGame = FALSE;
	/* store a character of input */
	char input = '-';
	/* this array stores the location of all our basic enemies */
	char *enemies[ENEMYSIZE];
	/* set all enemy locations after the initialization of the arrays */
	enemies[0] = *(map + 6) + 5;
	enemies[1] = *(map + 6) + 16;
	/* The current floor that we are on*/
	int currentfloor = 1;
	/* put game introduction here where it will run one time */
	printf("Welcome to the maze game! You are the %c, move through the game and try to reach the %c while avoiding the %c\n", PLAYER, EXIT__, ENEMY_);

	/* wait for player to hit enter */
	waitForEnter();

	/* this is our main game loop and it runs until some exit condition is reached */
	do
	{
		int playerMovement = NULL;
		/* show maze in its current layout */
		printMap(map, player, enemies);

		printf("Use WASD to move around the map.\nUse q to quit\n");
		/* Accept user input here */
		do
		{
			input = getchar();
		} while (input != 'w' && input != 'W' && input != 'a' && input != 'A' && input != 's' && input != 'S' && input != 'd' && input != 'D' && input != 'q' && input != 'Q');

		waitForEnter();

		/* determine what to do with the input */
		switch (input)
		{
		/* quit the game if q */
		case 'q':
		case 'Q':
			exitGame = TRUE;
			break;
		case 'w':
		case 'W':
			/* set playerMovement to move the character up a line, this means adjusting by a whole array */
			playerMovement -= MAPWIDTH;
			break;
		case 's':
		case 'S':
			/* set playerMovement to move the player down a line */
			playerMovement += MAPWIDTH;
			break;
		case 'a':
		case 'A':
			/* set playerMovement to go left one character */
			playerMovement = *player - 1;
			break;
		case 'd':
		case 'D':
			/* set playerMovement to go right one character */
			playerMovement = *player + 1;
			break;
		}

		/* Make sure where the player wants to move is legal */

		if (playerMovement != WALL__)
		{
			*player = playerMovement;
		}

		/* If it is legal move the player (player += playerMovement) */

		/* if the player moves to the exit they win */

		/* move all enemies in a loop here */

		/* if enemy moves to the player the player loses */

	} while (!exitGame);

	printf("Thanks for playing!\n");

	return 0;
}
/* Waits until it senses a newline from the user input stream*/
void waitForEnter()
{
	char input = '-';
	while (input != '\n')
	{
		input = getchar();
	}
	/* shorter version might not be as easy to read but may be more efficient barely */
	/* while(getchar() != '\n'); */
}
/* Prints out the map with all moving pieces shown on it */
void printMap(char map[][MAPHEIGHT][MAPWIDTH], char *player, char *enemies[])
{
	/* counter variables */
	int x, y, e;
	/* flag for finding an enemy at the location */
	int enemyFound = FALSE;
	/* loop through each array in the map */
	for (y = 0; y < MAPHEIGHT; y++)
	{
		/* loop through all characters in the array  */
		for (x = 0; x < MAPWIDTH; x++)
		{
			for (e = 0; e < ENEMYSIZE; e++)
			{
				/* check if the enemy is at the current location */
				if (enemies[e] == *(map + y) + x)
				{
					putchar(ENEMY_);
					enemyFound = TRUE;
					break;
				}
			}
			if (enemyFound == TRUE)
			{
				enemyFound = FALSE;
			}
			/* check if the player is at this location */
			else if (player == *(map + y) + x)
			{
				putchar(PLAYER);
			}
			/* if neither there print map tile */
			else
			{
				putchar(map[y][x]);
			}
		}
		/* each new map line add a newline */
		putchar('\n');
	}
}
