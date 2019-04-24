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
//Check the move and add it to the board
int move();

/* board checkers */
int Horizontal();
int Vertical();
int DiagonalRight(); /* (\) */
int DiagonalLeft();  /* (/) */

//Counters
int i, j, x, y;
//player input
int input;
//player input row - set by move() and used to process in whoWon()
int row;
//game board
char board[WIDTH][HEIGHT] = {{' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' ', ' ', ' '}};
//To exit or not to exit
//int exit = 0;
//Who's turn is it? 1 = X, 2 = O
int currentPlayerTurn = 1;
char chcurrentPlayerTurn = 'X';
//Game loop
int gameloop()
{
  currentPlayerTurn = !currentPlayerTurn;
  if (currentPlayerTurn == 1)
    chcurrentPlayerTurn = 'O';
  else if (currentPlayerTurn == 2)
    chcurrentPlayerTurn = 'X';
  printBoard();
  playerTurn();
  return whoWon();
}
//                                                  1 2 3 4 5 6 7
//
//
//
//
//
//
//prints the board (duh)
int printBoard()
{
  for (i = 48; i - 48 < WIDTH; putchar(++i), putchar(' '))
    ;
  putchar('\n');
  for (i = 0; i < HEIGHT; ++i, putchar('\n'))
    for (j = 0; j < (WIDTH); ++j)
      putchar(board[j][i]), putchar('|');
  return 0;
}

//Returns an int between 1 and 7 based on what the player's move was. Also checks if it is a valid move
int playerTurn()
{
  puts("Where do you want to play?");
  input = 9999;
  input = getchar() - 48;
  while (getchar() != '\n' && (input + 48 <= '1' && input >= '7'))
    ;
  move();
  return 0;
}

//Check the move and add it to the board
int move()
{
  for (i = 0; i < HEIGHT; ++i)
  {
    //Check if there is a blank beneath this space
    if (board[input][i] == 0)
      board[input][i] = chcurrentPlayerTurn;
    else if (i > HEIGHT)
      return 0;
  }
  return 1;
}

//Reurns 1 for player X (one), 2 for player O (two), 0 for draw, and -1 when nobody has won yet
int whoWon()
{
  for (i = 0; i < 3; i++)
    for (j = 0; j < 3; j++)
    {
      Horizontal();
      Vertical();
      DiagonalRight(); /* (\) */
      DiagonalLeft();  /* (/) */
    }
  return 0;
}

/* Checks what it says for 2 in a rows */
int Horizontal()
{
  /*horizontal loop through all on one row*/
  /* Check for 2 plays in a row */
  if ((board[input][(j + 1) % 3] == currentPlayerTurn) && /**/)

    /* same check, but for player's moves */
    if (((board[i][(j + 1) % 3] == 0 && /**/ (board[i][(j + 1) % 3] == /**/ board[i][(j + 2) % 3])) && /**/ board[i][(j + 3) % 3] == -1) /****/)

      /* Check for a move with 2 blanks around it */
      if ((((board[i][(j + 1) % 3] == -1 && /**/ (board[i][(j + 1) % 3] == /**/ board[i][(j + 2) % 3])) && /**/ board[i][(j + 3) % 3] == 1)))

        /* same check, but for player's moves */
        if ((((board[i][(j + 1) % 3] == -1 && /**/ (board[i][(j + 1) % 3] == /**/ board[i][(j + 2) % 3])) && /**/ board[i][(j + 3) % 3] == 0)))

          /*check for 3 in a row blanks*/
          if ((((board[i][(j + 1) % 3] == -1 && /**/ (board[i][(j + 1) % 3] == /**/ board[i][(j + 2) % 3])) && /**/ board[i][(j + 3) % 3] == -1)))

            return 0;
}

/* Checks what it says for 2 in a rows */
int Vertical()
{
  /* Check for 2 plays in a row */
  if (((board[j][(i + 1) % 3] == 1 && /**/ (board[j][(i + 1) % 3] == /**/ board[j][(i + 2) % 3])) && /**/ board[j][(i + 3) % 3] == -1) /****/)

    /* same check, but for player's moves */
    if ((((board[j][(i + 1) % 3] == 0 && /**/ (board[j][(i + 1) % 3] == /**/ board[j][(i + 2) % 3])) && /**/ board[j][(i + 3) % 3] == -1)))

      /* Check for 2 plays in a row */
      if (((board[j][(i + 1) % 3] == -1 && /**/ (board[j][(i + 1) % 3] == /**/ board[j][(i + 2) % 3])) && /**/ board[j][(i + 3) % 3] == 1) /****/)

        /* same check, but for player's moves */
        if (((board[j][(i + 1) % 3] == -1 && /**/ (board[j][(i + 1) % 3] == /**/ board[j][(i + 2) % 3])) && /**/ board[j][(i + 3) % 3] == 0) /****/)

          /*check for 3 in a row blanks*/
          if (((board[j][(i + 1) % 3] == -1 && /**/ (board[j][(i + 1) % 3] == /**/ board[j][(i + 2) % 3])) && /**/ board[j][(i + 3) % 3] == -1) /****/)
}
/* Checks what it says for 2 in a rows */
int DiagonalRight()
{
  /* Check for 2 plays in a row */
  if (((board[(i + 1) % 3][(j + 1) % 3] == 1 && /**/ (board[(i + 1) % 3][(j + 1) % 3] == /**/ board[(i + 2) % 3][(j + 3) % 3])) && /**/ board[(i + 3) % 3][(j + 2) % 3] == -1) /****/)

    /* same check, but for player's moves */
    if (((board[(i + 1) % 3][(j + 1) % 3] == 0 && /**/ (board[(i + 1) % 3][(j + 1) % 3] == /**/ board[(i + 2) % 3][(j + 3) % 3])) && /**/ board[(i + 3) % 3][(j + 2) % 3] == -1) /****/)

      /* Check for a move with 2 blanks around it */
      if ((((board[(i + 1) % 3][(j + 1) % 3] == -1 && /**/ (board[(i + 1) % 3][(j + 1) % 3] == /**/ board[(i + 2) % 3][(j + 3) % 3])) && /**/ board[(i + 3) % 3][(j + 2) % 3] == 1)))

        /* same check, but for player's moves */
        if ((((board[(i + 1) % 3][(j + 1) % 3] == -1 && /**/ (board[(i + 1) % 3][(j + 1) % 3] == /**/ board[(i + 2) % 3][(j + 3) % 3])) && /**/ board[(i + 3) % 3][(j + 2) % 3] == 0)))

          /*check for 3 in a row blanks*/
          if ((((board[(i + 1) % 3][(j + 1) % 3] == -1 && /**/ (board[(i + 1) % 3][(j + 1) % 3] == /**/ board[(i + 2) % 3][(j + 3) % 3])) && /**/ board[(i + 3) % 3][(j + 2) % 3] == -1)))

            return 0;
}

/* Checks what it says for 2 in a rows */
int DiagonalLeft()
{
  /* Check for 2 plays in a row */
  if (((board[(i + 3) % 3][(j + 1) % 3] == 1) && /**/ (board[(i + 3) % 3][(j + 1) % 3] == /**/ board[(i + 2) % 3][(j + 3) % 3])) /**/ && board[(i + 1) % 3][(j + 3) % 3] == -1)

    /* same check, but for player's moves */
    if (((board[(i + 3) % 3][(j + 1) % 3] == 0) && /**/ (board[(i + 3) % 3][(j + 1) % 3] == /**/ board[(i + 2) % 3][(j + 3) % 3])) /**/ && board[(i + 1) % 3][(j + 3) % 3] == -1)

      /* Check for a move with 2 blanks around it */
      if (((board[(i + 3) % 3][(j + 1) % 3] == -1) && /**/ (board[(i + 3) % 3][(j + 1) % 3] == /**/ board[(i + 2) % 3][(j + 3) % 3])) /**/ && board[(i + 1) % 3][(j + 3) % 3] == 1)

        /* same check, but for player's moves */
        if (((board[(i + 3) % 3][(j + 1) % 3] == -1) && /**/ (board[(i + 3) % 3][(j + 1) % 3] == /**/ board[(i + 2) % 3][(j + 3) % 3])) /**/ && board[(i + 1) % 3][(j + 3) % 3] == 0)

          /*check for 3 in a row blanks*/
          if (((board[(i + 3) % 3][(j + 1) % 3] == -1) && /**/ (board[(i + 3) % 3][(j + 1) % 3] == /**/ board[(i + 2) % 3][(j + 3) % 3])) /**/ && board[(i + 1) % 3][(j + 3) % 3] == -1)

            return 0;
}

int main(void)
{
  puts("Welcome to Connect 4!\nPress enter to start");
  while (getchar() != '\n')
    ;
  putchar('\n');
  //keep going until there is a winner
  while (gameloop() == -1)
    ;
  return 0;
}