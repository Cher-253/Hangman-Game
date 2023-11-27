#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "GameLib.h"
#include <ctype.h>

//check phrase function
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
    //copy phrase to dashphrase and uppercase it
    int i;
    for(i=0;i<MAX_INPUT;i++)
    {
        DashPhrase[i] = toupper(Phrase[i]);
    }
    char alphas[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    char *AlphaOccur = strpbrk(DashPhrase,alphas);
    //Replacing with dashes
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

void StartGame(char ChosenPhrase[MAX_INPUT])
{
    #include "PhraseBank.txt"
    int numOfPhrases=0;
    printf("Welcome to %d STRIKES - YOU'RE OUT - the CSE version\n\n",STRIKES);
    printf("Please pick a phrase from the following menu\n");
    int i =0;
    while(PhraseBank[i]!="")
    {
        char DashPhrase[MAX_INPUT];
        CheckPhrase(PhraseBank[i]);
        DashIt(PhraseBank[i],DashPhrase);
        i++;
        printf("%d.\t%s\n", i, DashPhrase);

    }
    numOfPhrases=i;
    //taking choice of phrase 
    int choicePhrase =0;
    printf("\nEnter choice : ");
    scanf("%d",&choicePhrase);
    while(choicePhrase<0 || choicePhrase>i)
    {
        printf("\nWrong choice. Please enter again");
        printf("\nEnter choice : ");
        scanf("%d",&choicePhrase);
    }
    //verifying if user entered menu choice is valid and within the range of your menu
    i=0;
    strcpy(ChosenPhrase,PhraseBank[choicePhrase-1]);
}

//function GuessALetter
int GuessALetter(char Phrase[MAX_INPUT],char DashedPhrase[MAX_INPUT],char UpperPhrase[MAX_INPUT])
{
    char Guess;
    char *FindGuess = NULL;
    char UpperPhraseCopy[MAX_INPUT];
    int FoundALetter =0;
    int distance =0;
    //Use strcpy()to copy UpperPhrase into GuessALetterCopy.
    strcpy(UpperPhraseCopy,UpperPhrase);//destination,argument to be copied
    //print dashed Phrase
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
        distance =abs(FindGuess - UpperPhraseCopy);
        //Use that distance to  set the element in DashedPhrase to that same element from Phrase. 
        DashedPhrase[distance] = Phrase[distance];
        UpperPhraseCopy[distance] = '-';
        FindGuess = strchr(UpperPhraseCopy,Guess);
    }

    return FoundALetter;
}