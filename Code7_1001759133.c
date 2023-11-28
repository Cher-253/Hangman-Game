#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include "GameLib.h"
#include "FileLib.h"
#include <ctype.h>

int main (int argc, char *argv[])
{
    int ChosenArrayIndex =0;
    char ChosenPhrase[MAX_INPUT];
    char Mode[3] ="r+";
    GuessSong StructArray[MAX_ENTRIES]={};
    FILE *filehandleptr =FileOpen(argc,argv,Mode);
    ChosenArrayIndex = StartGame(&ChosenPhrase[MAX_INPUT],filehandleptr,StructArray);
    int StrikeTracker=1;
    char *Phrase=StructArray[ChosenArrayIndex].SongTitle;
    char DashedPhrase[MAX_INPUT];
    char UpperPhrase[MAX_INPUT];
    DashIt(Phrase,DashedPhrase);
    int i=0;
    int flag=0;
    char *DashFinder ="";
    for(i=0;i<MAX_INPUT;i++)
    {
        UpperPhrase[i] =  toupper(Phrase[i]);
    }
    int LetterThereOrNot=0;
    do
    {
        LetterThereOrNot = GuessALetter(Phrase,DashedPhrase,UpperPhrase);
        if(LetterThereOrNot==0)
        {
            printf("\nStrike %d", StrikeTracker);
            StrikeTracker++;
        }
        DashFinder=strchr(DashedPhrase,'-');//checking for dashes   
    }
    while (DashFinder!=NULL && StrikeTracker<=3);//checking for winner 
    if(StrikeTracker<=3)
    {
        printf("You figured it out!!\n\nThe phrase was\n\n");
        printf("%s\n",Phrase);
        printf("YOU WIN!!!!\n ");
        WriteNewFile(StructArray,ChosenArrayIndex,filehandleptr);
    }
    else
    {
        {
            printf("\n\n3 STRIKES - YOU'RE OUT!!\n\nGame over");
        }
    }
}
