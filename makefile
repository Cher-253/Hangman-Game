SRC1 = Code7_1001759133.c
SRC2 = GameLib.c
SRC3 = FileLib.c
OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)
OBJ3 = $(SRC3:.c=.o)

EXE = $(SRC1:.c=.e)
HFILE1 = GameLib.h
HFILE2 = FileLib.h

CFLAGS = -g

all : $(EXE)

$(EXE): $(OBJ1) $(OBJ2) $(OBJ3) 
	gcc $(CFLAGS) $(OBJ1) $(OBJ2) $(OBJ3) -o $(EXE)

$(OBJ1): $(SRC1) $(HFILE1) $(HFILE2)  
	gcc -c $(CFLAGS) $(SRC1) -o $(OBJ1)

$(OBJ2): $(SRC2) $(HFILE1) $(HFILE2) 
	gcc -c $(CFLAGS) $(SRC2) -o $(OBJ2)

$(OBJ3): $(SRC3) $(HFILE1) $(HFILE2)  
	gcc -c $(CFLAGS) $(SRC3) -o $(OBJ3)
