#ifndef _GAMELIB_H
#define _GAMELIB_H
#include <stdio.h>
#define MAX_INPUT 81
#define STRIKES 3
void StartGame(char ChosenPhrase[]);
int GuessALetter(char Phrase[],char PhraseCopy[],char UpperPhrase[]);
void DashIt(char *Phrase, char DashPhrase[]);
void CheckPhrase(char *Phrase);
#endif

