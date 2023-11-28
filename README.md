## Hangman Game Project

This project implements a simple Hangman game in C. The program allows users to guess letters in a randomly selected phrase, with a limited number of strikes before losing the game. The code is divided into three main files:

Code5_1.c:
The main program file that orchestrates the Hangman game.
Initializes variables, generates a random phrase, and prompts users for letter guesses.
Tracks strikes and ends the game based on the predefined maximum number of strikes.

GameLib.c:
Contains functions supporting the Hangman game logic.
Functions include checking the validity of the chosen phrase, converting phrases to dashed format, and managing the game's core logic.
Implements the core game loop, allowing users to guess letters and updating the dashed phrase accordingly.

GameLib.h:
Header file providing function prototypes and necessary constants for the Hangman game.
Defines the maximum input size, the maximum number of allowed strikes, and includes function prototypes for the game's functionality.

Key Features:  
--> Randomly selects a phrase for the Hangman game from a predefined phrase bank.  
--> Converts the chosen phrase into a dashed format for display.  
--> Allows users to guess letters and updates the display based on correct guesses.  
--> Implements a strike system with a maximum number of strikes before ending the game.  
--> User-friendly prompts and error handling for menu choices.  

Makefile:
The provided makefile compiles the Code5_1.c and GameLib.c files, creating an executable named Code5_1.e.
Dependencies and compilation steps are organized in the makefile for easy maintenance.

Instructions:  
The game prompts users to choose a phrase from a menu and provides a limited number of strikes to guess the correct letters.
The game ends either when the user correctly guesses the phrase or exceeds the maximum number of allowed strikes.

Testing:
The program should be tested with various inputs to ensure correct phrase generation, letter guessing, and game termination based on strikes.

Note:
Ensure that the necessary phrase bank is available and correctly formatted in "PhraseBank.txt."  
