#ifndef _GAMELIB_H
#define _GAMELIB_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "GameLib.h"
#define MAX_INPUT 81
#define STRIKES 3
#define MAX_ENTRIES 10 

typedef struct  
{
    char *Artist;
    char *SongTitle;
    char *AlbumName;
    char ReleaseDate[5];
}GuessSong;

int StartGame(char ChosenPhrase[MAX_INPUT], FILE *filehandleptr,GuessSong StructArray[MAX_ENTRIES]);
int GuessALetter(char Phrase[],char PhraseCopy[],char UpperPhrase[]);
void DashIt(char *Phrase, char DashPhrase[]);
void CheckPhrase(char *Phrase);

#endif
