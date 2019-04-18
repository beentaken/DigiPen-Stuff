/******************************
 * Filename: GPACalc.c
 * Author: Blakely North
 * Date Last Edited: 1-22-2019
 * Brief Description: A sample and standard new file
   gcc -Wall -Wextra -O -ansi -pedantic -o GPACalc GPACalc.c
 ******************************/
//printf, scanf
#include <stdio.h>
//rand, srand
#include <stdlib.h>
//time
#include <time.h>
//strcat, strcpy etc.
#include <string.h>
//Board width
#define WIDTH 7
//Board height
#define HEIGHT 6

//prints the board (duh)
int printBoard();
//Returns an int between 1 and 7 based on what the player's move was. Also checks if it is a valid move
int playerTurn();
//Reurns 1 for player X (one), 2 for player O (two), 0 for draw, and -1 when nobody has won yet
int whoWon();
//Game loop
int gameloop();

//Counters
int i, j, x, y;
//player input
int input;
//game board
char board[WIDTH][HEIGHT];
//To exit or not to exit
int exit = 0;
//Who's turn is it? 1 = X, 2 = O
int currentPlayerTurn = 1;

//Game loop
int gameloop()
{
  printBoard();
  playerTurn();
  return whoWon();
}


//prints the board (duh)
int printBoard()
{
  for (i = 0; i < (WIDTH + WIDTH); i++, putchar('i + 1'))
   for (i = 0; i < HEIGHT; ++i, putchar('\n'))
     for (j = 0; j < (WIDTH + WIDTH); ++j, putchar(board[j][i]), putchar(' '))
       ;
  return 0;
}

//Returns an int between 1 and 7 based on what the player's move was. Also checks if it is a valid move
int playerTurn()
{
  puts("Where do you ewant to play?")
  return 0;
}

//Reurns 1 for player X (one), 2 for player O (two), 0 for draw, and -1 when nobody has won yet
int whoWon()
{
  return 0;
}

int main(void)
{
  //keep going until there is a winner
  while (gameloop() == -1);
  return 0;
}