#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "GameLib.h"
#include "FileLib.h"

FILE *FileOpen(int argc, char *argv[], char Mode[3])
{
    FILE *filehandleptr;
    char filename1[50];
    if(argc==2)
    {
        get_command_line_parameter(argv, "FILENAME=", filename1);
        strcpy(filename1,argv[1]);
    }
    else
    {
        printf("Must be run with an input file name\n");
        printf("Enter a file name at the prompt: ");
        scanf("%s",filename1);
        printf("filename1 is %s \n", filename1);
    }
    do
    {
        filehandleptr=fopen(filename1,Mode);
        if(filehandleptr == NULL)
        {
            printf("Could not open file named %s\n",filename1);
            printf("Enter a file name at the prompt: \n");
            scanf("%s",filename1);
        }
    }while (filehandleptr == NULL);
    return filehandleptr;  
}
int FileReader(GuessSong StructArray[MAX_ENTRIES],FILE *filehandleptr)
{
    char tempLine[100];
    int i=0,j=0,RecordsNum=0;
    char *token=NULL;
    int L1,L2,L3=0;
    while(fgets(tempLine,100,filehandleptr)!=NULL) 
    {
        if(strlen(tempLine)<3)
        {
            continue;
        }
        else
        {
            tempLine[strlen(tempLine)-1]='\0';//making the last element \n to \0
            char *tempToken;

            tempToken = strtok(tempLine,"|");
            L1=strlen(tempToken);
            StructArray[j].Artist = malloc(sizeof(char *)*L1);
            strcpy(StructArray[j].Artist,tempToken);

            tempToken = strtok(NULL,"|");
            L2=strlen(tempToken);
            StructArray[j].SongTitle =malloc(sizeof(char *)*L2);
            strcpy(StructArray[j].SongTitle,tempToken);

            strcpy(StructArray[j].ReleaseDate,strtok(NULL,"|"));//check

            tempToken=strtok(NULL,"\0");
            L3=strlen(tempToken);
            StructArray[j].AlbumName=malloc(sizeof(char *)*L3);
            strcpy(StructArray[j].AlbumName,tempToken);
            j++;
            }
        RecordsNum++;
    }
    return RecordsNum;
}     

void WriteNewFile(GuessSong StructArray[MAX_ENTRIES],int index,FILE *filehandleptr)
{
    int i=0;
    fseek(filehandleptr,0,SEEK_SET);//seekset starts from begining of file

    for(i=0;i<MAX_ENTRIES;i++)
    {
        if(i!=index && StructArray[i].Artist!=NULL)
        {
            fprintf(filehandleptr,"%s|%s|%s|%s\n",StructArray[i].Artist,StructArray[i].SongTitle,StructArray[i].ReleaseDate,StructArray[i].AlbumName);
        }
        else if(i==index)
        {
            free(StructArray[index].Artist);
            free(StructArray[index].AlbumName);
            free(StructArray[index].SongTitle);
        }
        
    }
    int start = ftell(filehandleptr);
    fseek(filehandleptr, 0, SEEK_END);
    int end = ftell(filehandleptr);
    fseek(filehandleptr, start, SEEK_SET);
    for(i = 0; i<(end-start); ++i)
    {
        fprintf(filehandleptr, "\n");
    }
    
    fclose(filehandleptr);
}

void get_command_line_parameter(char *argv[], char PName[], char PValue[])
{
    int i= 1;
    while (argv[i] != NULL)
    {
        if (!strncmp(argv[i], PName, strlen(PName)))
        {
            strcpy(PValue, strchr(argv[i], '=') + 1);
        }
        i++;
    }
}
