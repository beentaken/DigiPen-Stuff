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
int playerTurn(player);
//Reurns 1 for player X (one), 2 for player O (two), 0 for draw, and -1 when nobody has won
int whoWon();
//game loop
int gameloop();

//Counters
int i, j, x, y;
//player input
int input;
//game board
int board[WIDTH][HEIGHT];

int main(void)
{
  int turn = 0;
  while
  printBoard();
  playerTurn();
  turn = !turn;
  return 0;
}
