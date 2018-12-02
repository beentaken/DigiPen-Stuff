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
#define MAPHEIGHT 20
#define MAPWIDTH 55
/* game value definitions */
#define ENEMYSIZE 2
/* set what characters are used to represent different things */
#define PLAYER '@'
#define ENEMY_ 'E'
#define FLOOR_ ' '
#define WALL__ 'X'
#define EXIT__ 'O'
#define ACHVMT '?'
/* spairs = special stairs */
#define SPAIRS '\'
#define STAIRS '/'
#define HOLE_L '['
#define HOLE_R ']'
#define MAPSIZE 1100
/* have true and false values to be useful */
#define TRUE 1
#define FALSE 0
/* Waits until it sees a newline from the input stream */
void waitForEnter();
/* Prints out the map with all moving pieces shown on it */
void printMap(char map[][MAPHEIGHT][MAPWIDTH], char *player, char *enemies[], int currentfloor);

int main(void)
{
	/* map defining where all static things are, access with map[Y][X] */
	char map[2][MAPHEIGHT][MAPWIDTH] =
		{
			{
				{	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__},
				{	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__},
				{	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	ACHVMT,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__},
				{	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__},
				{	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__},
				{	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	STAIRS,	STAIRS,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__},
				{	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__},
				{	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__},
				{	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__},
				{	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	STAIRS,	STAIRS,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__},
				{	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__},
				{	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__},
				{	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__},
				{	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__},
				{	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__},
				{	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__},
				{	WALL__,	WALL__,	STAIRS,	STAIRS,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__},
				{	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__},
				{	WALL__,	WALL__,	EXIT__,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	STAIRS,	STAIRS,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__},
				{	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__}
			},
			{
				{	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__},
				{	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__},
				{	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__},
				{	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__},
				{	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__},
				{	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	STAIRS,	STAIRS,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__},
				{	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	ACHVMT,	FLOOR_,	WALL__},
				{	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__},
				{	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__},
				{	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	STAIRS,	STAIRS,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__},
				{	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__},
				{	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__},
				{	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__},
				{	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__},
				{	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_},
				{	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__},
				{	WALL__,	WALL__,	STAIRS,	STAIRS,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__},
				{	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__},
				{	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	HOLE_L,	HOLE_R,	FLOOR_,	FLOOR_,	FLOOR_,	FLOOR_,	STAIRS,	STAIRS,	FLOOR_,	FLOOR_,	WALL__,	WALL__,	FLOOR_,	FLOOR_,	WALL__},
				{	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__,	WALL__}
			}
		};
	/* this variable determines how the player moves using pointer arithmetic */
	/* player is represented by a pointer pointing to where in the map it is currently */
	int playerMovement;
	/* formula for this location is *(map + Y) + X */
	char *player = *(*(map + 0) + 1) + 4;
	/* Alternative formula map[Y] + X */
	/* set this to TRUE if the player chooses to quit or the win condition or lose condition is reached */
	int exitGame = FALSE;
	/* store a character of input */
	char input = '-';
	/* this array stores the location of all our basic enemies */
	char *enemies[ENEMYSIZE];
	int timer;
	/* prevent instantly going back a floor */
	int previously_stairs = FALSE;
	/* The current floor that we are on*/
	int currentfloor = 0;
	int moves = 0;
	int enemymovement = 2, amntofenemies = 2, enemypos = 1, enemydir = 1;
	int i;
	/* set all enemy locations after the initialization of the arrays */
	enemies[0] = *(*(map + 0) + 11) + 10;
	enemies[1] = *(*(map + 1) + 11) + 17;
	/* put game introduction here where it will run one time */
	printf("Welcome to the maze game! You are the %c, move through the game and try to reach the %c while avoiding the %c\n", PLAYER, EXIT__, ENEMY_);

	/* wait for player to hit enter */
	waitForEnter();
	timer = time(NULL);
	/* this is our main game loop and it runs until some exit condition is reached */
	do
	{
		int playerMovement = 0;
		/* show maze in its current layout */
		printMap(map, player, enemies, currentfloor);

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
			moves++;
			/* set playerMovement to move the character up a line, this means adjusting by a whole array */
			playerMovement -= MAPWIDTH;
			break;
		case 's':
		case 'S':
			moves++;
			/* set playerMovement to move the player down a line */
			playerMovement += MAPWIDTH;
			break;
		case 'a':
		case 'A':
			moves++;
			/* set playerMovement to go left one character */
			playerMovement = -2;
			break;
		case 'd':
		case 'D':
			moves++;
			/* set playerMovement to go right one character */
			playerMovement =  2;
			break;
		}

		/* Make sure where the player wants to move is legal */

		if (*(player + playerMovement) != WALL__)
		{
			player += playerMovement;
		}

		/* if they hit stairs*/
		if ((*player == STAIRS || *player == HOLE_L) && (previously_stairs == FALSE))
		{
			
			if (currentfloor == 0)
			{
				currentfloor = 1;
				player += MAPSIZE;
			}
			else if (currentfloor == 1) 
			{
				currentfloor = 0;
				player -= MAPSIZE;
			}
		}

		/* if you get the key */

		/* If it is legal move the player (player += playerMovement) */

		/* if the player moves to the exit they win */
		
		if (*player == EXIT__) {
			printf("Congradulations! You win!\nTime: %i\nMoves: %i", timer, moves);
		}
		
		/* move all enemies in a loop here */

		for (i = 0; i < amntofenemies; i++)
		{
			if (enemydir == 1 && enemypos == 4)
			enemydir = -1;
			
			else if (enemydir == -1 && enemypos == -4)
			enemydir = +1;

			if (enemydir == 1)
			enemymovement +=2;

			if (enemymovement == 2 || -2)
			enemies[i] = *(*(map + currentfloor) + 0) + 2;
		}
		
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

int randomnum(int low, int high)
{
	int RNDNum;
	RNDNum = rand() % ((high + 1) - low) + low;
	return RNDNum;
}

/* Prints out the map with all moving pieces shown on it */
void printMap(char map[][MAPHEIGHT][MAPWIDTH], char *player, char *enemies[], int currentfloor)
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
				if (enemies[e] == *(*(map + currentfloor) + y) + x)
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
			else if (player == *(*(map + currentfloor) + y) + x)
			{
				putchar(PLAYER);
			}	
			/* if neither there print map tile */
			else
			{
				putchar(map[currentfloor][y][x]);
			}
		}
		/* each new map line add a newline */
		putchar('\n');
	}
}
