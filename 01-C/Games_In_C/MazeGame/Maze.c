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
 /* Define map sizes*/
#ifndef MAPHEIGHT
#define MAPHEIGHT 10
 /*#ifndef MAPWIDTH*/
#define MAPWIDTH 20
/*#endif*/
 /* Game Value defs*/
/* *#ifndef ENEMYSIZE/* */
#define ENEMYSIZE 2
/* #endif*/
/* set what characters are used tp represent dofferent things*/
#define PLAYER 'P'
#define ENEMY_ 'E'
#define FLOOR_ ' '
#define WALL__ '|'
#define EXIT__ '0'
 /* True/False values*/
#define TRUE 1
#define FALSE 0
 /* Waits for enter key*/
void waitforenter();
/* Prints map with all moving pieces shown on it.*/
void printMap(char map[][MAPWIDTH], char* player, char* enemies[])
 int main(void)
{
  char map[MAPHEIGHT][MAPWIDTH] = {
    { WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__},
    { WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__},
    { WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__},
    { WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, EXIT__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__},
    { WALL__, FLOOR_, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__},
    { WALL__, FLOOR_, EXIT__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__},
    { WALL__, FLOOR_, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__},
    { WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__},
    { WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__},
    { WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__, FLOOR_, WALL__, EXIT__, WALL__, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, FLOOR_, WALL__},
    { WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__, WALL__}
  };
  /* playert is represented by a pointer*/
  /* form,ula for this location is *(map + y) + x */
  char* player = *(map+2) +1;
  /* alternitive formula is map[y] + x*/
  /* set this to TRUE if the pllayer chooses to quit*/
  int exitGame = FALSE;
  /* store a character of input*/
  char input = '-';
  /* this array stores the locations of the basic enemies*/
  char* enemies[ENEMYSIZE];
  /* set all enemie locations after initializations of the arrays*/
  enemies[0] = *map + 6 + 5;
  enemies[1] = *(map+6) + 16;
   /* put game intro here wherew it till run once*/
  printf("Welcome to the maze game! You are the %c, move through the the game to reach the %c while avoiding the %c's\n", PLAYER, EXIT__, ENEMY_,);
  /* Wait for enter*/
  waitforenter()
   /* this is our main game loop*/
  do {
    /* this var determines how the player moves using pointer atithamtic*/
    int playerMovement = 0;
    /* show maze in its current current layout*/
    printMap(map, player, enemies);
    printf("Use WASD to move.\nPress q to quit.\n");
    /* Accept user input here.*/
    scanf("%c\n", );
    waitforenter();
  } while(!exitGame);
  return 0;
}
 void waitforenter();
{
  char input = '-';
  while (input != 'n') {
    input = getchar();
  }
  while (getchar() != '\n')
}
 void printMap(char map[][MAPWIDTH], char* player, char* enemies[])
{
 }
