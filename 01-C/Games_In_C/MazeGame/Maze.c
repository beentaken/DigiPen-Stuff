/**************************
MazeC.c
Base By: Ryan Scheppler
Edited and completed by: 
Brief: This game demonstrates some pointer and miltidimensional array concepts. Move the player through the maze to reach the exit and win!
gcc -Wall -Wextra -ansi -pedantic -O -o maze MazeC.c
**************************/
/* standard input and output */
#include <stdio.h>
/* rand, srand in the standard library */
#include <stdlib.h>
/* time to set the random seed different */
#include <time.h>

/* define the size of the map with these definitions */
#define MAPHEIGHT 10
#define MAPWIDTH 20
/* game value definitions */
#define ENEMYSIZE 2
/* set what characters are used to represent different things */
#define PLAYER 'P'
#define ENEMY_ 'E'
#define FLOOR_ '-'
#define WALL__ '|'
#define EXIT__ 'O'
/* have true and false values to be useful */
#define TRUE 1
#define FALSE 0
/* Waits until it sees a newline from the input stream */
void waitForEnter();
/* Prints out the map with all moving pieces shown on it */
void printMap(char map[][MAPWIDTH], char* player, char* enemies[]);

int main(void)
{
	/* map defining where all static things are, access with map[Y][X] */
	char map[MAPHEIGHT][MAPWIDTH] = {
 {WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__,},
 {WALL__, FLOOR_, PLAYER, WALL__, WALL__, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__,},
 {WALL__, FLOOR_, WALL__, FLOOR_, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, PLAYER, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__,},
 {WALL__, FLOOR_, WALL__, FLOOR_, WALL__, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, PLAYER, WALL__,},
 {WALL__, FLOOR_, WALL__, FLOOR_, WALL__, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, FLOOR_, WALL__,},
 {WALL__, FLOOR_, WALL__, FLOOR_, WALL__, FLOOR_, WALL__, WALL__, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, FLOOR_, WALL__, FLOOR_, PLAYER, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__,},
 {WALL__, FLOOR_, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, FLOOR_, WALL__, WALL__, WALL__, WALL__, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__,},
 {WALL__, FLOOR_, FLOOR_, WALL__, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, WALL__,},
 {WALL__, WALL__, FLOOR_, FLOOR_, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__,},
 {WALL__, WALL__, FLOOR_, FLOOR_, WALL__, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__,},
 {WALL__, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__,},
 {WALL__, FLOOR_, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, FLOOR_, WALL__, WALL__,},
 {WALL__, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, WALL__,},
 {WALL__, FLOOR_, FLOOR_, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, WALL__, WALL__, WALL__, WALL__,},
 {WALL__, WALL__, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, FLOOR_, WALL__, FLOOR_, WALL__, FLOOR_, FLOOR_, FLOOR_, WALL__, FLOOR_, FLOOR_, FLOOR_, WALL__, FLOOR_, FLOOR_, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__,},
 {WALL__, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, WALL__, WALL__, FLOOR_, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, WALL__, WALL__, FLOOR_, WALL__,},
 {WALL__, WALL__, WALL__, WALL__, WALL__, FLOOR_, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, FLOOR_, WALL__, FLOOR_, FLOOR_, WALL__, FLOOR_, FLOOR_, WALL__,},
 {WALL__, WALL__, WALL__, WALL__, WALL__, FLOOR_, WALL__, FLOOR_, WALL__, WALL__, WALL__, WALL__, FLOOR_, WALL__, FLOOR_, FLOOR_, WALL__, FLOOR_, WALL__, WALL__, FLOOR_, WALL__, FLOOR_, FLOOR_, WALL__, FLOOR_, FLOOR_, WALL__,},
 {WALL__, WALL__, WALL__, WALL__, WALL__, FLOOR_, FLOOR_, FLOOR_, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, WALL__, FLOOR_, WALL__, FLOOR_, WALL__, WALL__, PLAYER, WALL__, WALL__, PLAYER, WALL__, WALL__, WALL__, WALL__,},
 {WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__,}

	};
	/* this variable determines how the player moves using pointer arithmetic */
	/* player is represented by a pointer pointing to where in the map it is currently */
	/* formula for this location is *(map + Y) + X */
	char* player = *(map + 2) + 1;
	/* Alternative formula map[Y] + X */
	/* set this to TRUE if the player chooses to quit or the win condition or lose condition is reached */
	int exitGame = FALSE;
	/* store a character of input */
	char input = '-';
	/* this array stores the location of all our basic enemies */
	char* enemies[ENEMYSIZE];
	/* set all enemy locations after the initialization of the arrays */
	enemies[0] = *(map + 6) + 5;
	enemies[1] = *(map + 6) + 16;
	/* put game introduction here where it will run one time */
	printf("Welcome to the maze game! You are the %c, move through the game and try to reach the %c while avoiding the %c\n", PLAYER, EXIT__, ENEMY_);
	
	/* wait for player to hit enter */
	waitForEnter();
	
	/* this is our main game loop and it runs until some exit condition is reached */
	do
	{
		
		/* show maze in its current layout */
		printMap( map, player, enemies);
		
		printf("Enter in w, a, s, or d to move around the map , q to quit\n");
		/* Accept user input here */
		do
		{
			input = getchar();
		}while(input != 'w' && input != 'W' && input != 'a' && input != 'A' && input != 's' && input != 'S' && input != 'd' && input != 'D' && input != 'q' && input != 'Q');
		
		
		waitForEnter();
		
		
		/* determine what to do with the input */
		switch(input)
		{
			/* quit the game if q */
			case 'q':
			case 'Q':
				exitGame = TRUE;
				break;
			case 'w':
			case 'W':
				/* set playerMovement to move the character up a line, this means adjusting by a whole array */
				break;
			case 's':
			case 'S':
				/* set playerMovement to move the player down a line */
				break;
			case 'a':
			case 'A':
				/* set playerMovement to go left one character */
				break;
			case 'd':
			case 'D':
				/* set playerMovement to go right one character */
				break;
		}
		
		/* Make sure where the player wants to move is legal */
		
		/* If it is legal move the player (player += playerMovement) */
		
		/* if the player moves to the exit they win */
		
		/* move all enemies in a loop here */
		
		/* if enemy moves to the player the player loses */
		
	}while(!exitGame);
	
	printf("Thanks for playing!\n");
	
	return 0;
}
/* Waits until it senses a newline from the user input stream*/
void waitForEnter()
{
	char input = '-';
	while(input != '\n')
	{
		input = getchar();
	}
	/* shorter version might not be as easy to read but may be more efficient barely */
	/* while(getchar() != '\n'); */
	
}
/* Prints out the map with all moving pieces shown on it */
void printMap(char map[][MAPWIDTH], char* player, char* enemies[])
{
	/* counter variables */
	int x, y, e;
	/* flag for finding an enemy at the location */
	int enemyFound = FALSE;
	/* loop through each array in the map */
	for(y = 0; y < MAPHEIGHT; y++)
	{
		/* loop through all characters in the array  */
		for(x = 0; x < MAPWIDTH; x++)
		{
			for(e = 0; e < ENEMYSIZE; e++)
			{
				/* check if the enemy is at the current location */
				if(enemies[e] == *(map + y) + x)
				{
					putchar(ENEMY_);
					enemyFound = TRUE;
					break;
				}
			}
			if(enemyFound == TRUE)
			{
				enemyFound = FALSE;
			}
			/* check if the player is at this location */
			else if( player == *(map + y) + x)
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
