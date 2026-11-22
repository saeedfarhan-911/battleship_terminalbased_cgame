# pflab_firstsemester_project
 Terminal based battle ship game 
 Battleship Game

A console-based Battleship game written in C.

Description

This project is a Battleship game where the player plays against the computer on a 10×10 board.

The player places their ships on the board by entering coordinates and directions. The computer places its ships randomly. Players then take turns attacking the opponent's board until all of one player's ships have been sunk.

Features

10×10 game board
Player-controlled ship placement
Random computer ship placement
Player attacks using coordinates
Computer randomly chooses attack coordinates
Hit and miss detection
Ship sinking detection
Displays the winner
Saves game results to a match history file
Ships

The game contains four ships:

Aircraft Carrier — length 5
Cruiser — length 4
Destroyer — length 3
Frigate — length 2
How to Play

When prompted, enter a row using a letter from A to J and a column using a number from 1 to 10.

For example:

Row: B Column: 4

When placing a ship, enter a direction:

0 = Right 1 = Down 2 = Left 3 = Up

The game continues until all ships belonging to one side have been destroyed.

Game Results

After a game is completed, the result is saved to:

match history.txt

This file records whether the player or the computer won.

Requirement

This program is designed to run on Windows because it uses Windows-specific console functionality such as windows.h and Sleep().

A C compiler is required to compile the program.

Compilation

Compile the file using the following format :

gcc filename.c -o battleship.exe

The program can then be run using:

.\battleship

Author

Abdul Moiz 26k1012
