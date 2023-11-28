#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "GameLib.h"
#include "FileLib.h"
#include <ctype.h>

int StartGame(char ChosenPhrase[MAX_INPUT], FILE *filehandleptr,GuessSong StructArray[MAX_ENTRIES])
{
    int Recordnum=FileReader(StructArray,filehandleptr);
    if(Recordnum==0)
    {
        printf("All of the games have been played-please reload file");
        exit(0);
    }
    int numOfPhrases=0;
    int i=0;
    printf("Welcome to %d STRIKES - YOU'RE OUT - the CSE version\n\n",STRIKES);
    printf("Please pick a movie from the following menu\n");
    for(i=0;i<Recordnum;i++)
    {
        printf("%d. %s's movie that was released in %s directed by %s\n ",i+1,StructArray[i].Artist,StructArray[i].ReleaseDate,StructArray[i].AlbumName);
    }
    int choicePhrase =0;
    printf("\nEnter choice : ");
    scanf("%d",&choicePhrase);
    while(choicePhrase<0 || choicePhrase>Recordnum)
    {
        printf("\nYou entered an invalid choice.\n Please reenter ");
        scanf("%d",&choicePhrase);
    }
    return choicePhrase-1;
}

void CheckPhrase(char *Phrase)
{
    char *FirstOccur;
    FirstOccur = strchr(Phrase,'-');
    if(FirstOccur != NULL)
    {
        printf("%s contains a dash in position %ld",Phrase,FirstOccur - Phrase + 1);
        exit(0);
    }
}

void DashIt(char *Phrase,char DashPhrase[])
{
    int i;
    for(i=0;i<MAX_INPUT;i++)
    {
        DashPhrase[i] = toupper(Phrase[i]);
    }
    char alphas[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    char *AlphaOccur = strpbrk(DashPhrase,alphas);
    while(AlphaOccur)
    {
        i = 0;
        while(DashPhrase[i] != '\0')
        {
            if(*AlphaOccur == DashPhrase[i])
            {
                DashPhrase[i] = '-';
            }
            i++;
        }
        AlphaOccur = strpbrk(DashPhrase,alphas);   
    }
}

int GuessALetter(char Phrase[MAX_INPUT],char DashedPhrase[MAX_INPUT],char UpperPhrase[MAX_INPUT])
{
    char Guess;
    char *FindGuess = NULL;
    char UpperPhraseCopy[MAX_INPUT];
    int FoundALetter =0;
    int distance =0;
    strcpy(UpperPhraseCopy,UpperPhrase);
    printf("\n\n%s", DashedPhrase); 
    printf("\n\nGuess a letter : ");
    scanf(" %c",&Guess);
    Guess = toupper(Guess);    
    //Use strchr()to find Guess in UpperPhraseCopy and store the pointer in FindGuess.
    FindGuess = strchr(UpperPhraseCopy,Guess);//storing pointer in FINDGUESS
    while(FindGuess!=NULL)
    {
        FoundALetter=1;
        //Use pointer arithmetic to find the distance between FindGuess and UpperPhraseCopy
        distance =labs(FindGuess - UpperPhraseCopy);
        //Use that distance to  set the element in DashedPhrase to that same element from Phrase. 
        DashedPhrase[distance] = Phrase[distance];
        UpperPhraseCopy[distance] = '-';
        FindGuess = strchr(UpperPhraseCopy,Guess);
    }
    return FoundALetter;
}
