#ifndef _FILELIB_H
#define _FILELIB_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "GameLib.h"

FILE *FileOpen(int argc, char *argv[], char Mode[3]);
int FileReader(GuessSong StructArray[MAX_ENTRIES],FILE *filehandleptr);
void WriteNewFile(GuessSong StructArray[MAX_ENTRIES],int index,FILE *filehandleptr);
void get_command_line_parameter(char *argv[], char PName[], char PValue[]);

#endif
