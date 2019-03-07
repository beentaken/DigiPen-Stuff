/******************************
 * Filename: StringParser.c
 * Name: Blakely North
 * Date Last Edited: 1-22-2019
 * Brief Description: A sample and standard new file
   gcc -Wall -Wextra -O -ansi -o StringParser StringParser.c
 ******************************/
#include <ctype.h> /* tolower */
#include <stdio.h> /* fgets */
/* Definitions are here to set array sizes */
#define INBUFF 256
#define COMMANDNUM 7
#define OBJNUM 3
#define ROOMNUM 3
/* These area  list of all commands and objects in an enum to easily convert to an ID number*/
enum COMMANDS
{
    QUIT,
    NORTH,
    EAST,
    SOUTH,
    WEST,
    TAKE,
    USE
};
enum OBJS
{
    CAKE,
    CORGI,
    CAN
};
enum ROOMS
{
    BEACH,
    BOARDWALK,
    ARCADE
};

/*This function will look through "input" to try to find the first instance of any string in the "phraselist". Priority is given to the earlier phrases.  pnum is how many phrases are in phrase list, and i is the starting index in input.  i is updated to just after the phrase was found to allow it to be run multiple times on one line.*/
int findPhrase(const char *phraselist[], int pnum, const char input[], int *i);

int main(void)
{
    int i = 0;
    /* these 2 arrays are to store the strings to check input for */
    const char *commandList[COMMANDNUM] = {"quit", "north", "east", "south", "west", "take", "use"};
    const char *objList[OBJNUM] = {"cake", "corgi", "can"};

    char input[INBUFF];

    int map[3][1] = {{ARCADE},
                     {BOARDWALK},
                     {BEACH}};

    int commandID = -1;
    int objID = -1;
    /* loop until quit is found */
    do
    {
        /*reset variable area*/
        i = 0;
        /* ask and accept input from the user */
        puts("Please input your commands!");

        fgets(input, INBUFF, stdin);

        /* parsing area */
        commandID = findPhrase(commandList, COMMANDNUM, input, &i);

        objID = findPhrase(objList, OBJNUM, input, &i);
        /* gamelogic area */
        if (commandID != -1)
        {
            printf("Command is '%s' id is '%i'\n", commandList[commandID], commandID);
            if (objID != -1)
            {
                printf("Object is '%s' id is '%i'\n", objList[objID], objID);
            }
            else
            {
                puts("No legal object found.");
            }
        }
        else
        {
#define ROOMNUM 3
            puts("No legal command found.");
        }

    } while (commandID != QUIT);

    return 0;
}
/*function that tells where to move if north is chosen.  Returns same place if you cannot move!*/
}

/*This function will look through "input" to try to find the first instance of any string in the "phraselist". Priority is given to the earlier phrases.  pnum is how many phrases are in phrase list, and i is the starting index in input.  i is updated to just after the phrase was found to allow it to be run multiple times on one line.*/
int findPhrase(const char *phraselist[], int pnum, const char input[], int *i)
{
    /*saves starting point*/
    int startingIndex = *i;
    /* phrase index we change in the loop */
    int p = 0;
    /*letter index in the phrase*/
    int l = 0;

    /*loop through each phrase checking for each*/
    while (p < pnum)
    {
        /*solve for if current phrase is present, and it is either at the start or has a space in front of it*/
        while (phraselist[p][l] && input[*i])
        {

            /* check first letter of inpuit word to see if a match with current phrase */
            if (input[*i] == phraselist[p][l])
            {
                /* move to the next letter of the phrase currently checked*/
                l++;

                /*possibly found a command*/
                if (phraselist[p][l] == '\0')
                {
                    /* Make sure we are done with the word in input */
                    if (input[*i + 1] == ' ' || input[*i + 1] == '\n' || input[*i + 1] == '\0')
                    {
                        return p;
                    }
                }
            }
            /* if first letter of word does not match find next word start if it exists*/
            else
            {
                /*reset letter index*/
                l = 0;
                /*cycle to next word*/
                while (input[*i] != ' ' && input[*i] != '\0' && input[*i] != '\n')
                {
                    (*i)++;
                }
                if (*i == '\0')
                {
                    break;
                }
            }
            /* move to next input character*/
            (*i)++;
        }
        /*go to next phrase*/
        p++;
        /*reset area*/
        l = 0;
        *i = startingIndex;
    }

    /* return value that means nothing was found */
    return -1;
}
