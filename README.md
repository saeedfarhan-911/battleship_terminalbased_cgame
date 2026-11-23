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

Test Cases

Test Case 1: Valid Ship Placement   

<img width="1626" height="945" alt="image" src="https://github.com/user-attachments/assets/2f409b43-6995-4597-b27d-729e9b5e96a1" />




Test Case 2: Ship Placement Outside the Board  

<img width="1866" height="570" alt="image" src="https://github.com/user-attachments/assets/4e5c50a8-dbe4-48e2-bd8d-bc63d71165e1" />


Test Case 3: Overlapping Ships  

<img width="2643" height="1596" alt="image" src="https://github.com/user-attachments/assets/0c45637b-62d8-48ef-8e0c-5e3674e87ecc" />


Test Case 4: Invalid Coordinates 

<img width="1230" height="360" alt="image" src="https://github.com/user-attachments/assets/0774d816-8e56-4a05-afdb-14034e990dd6" />


Test Case 5: Successful Hit 



<img width="2262" height="1539" alt="image" src="https://github.com/user-attachments/assets/a8fb695a-1a13-4c14-b569-86074a8d708f" />




Test Case 6: Missed Attack  
<img width="1995" height="1590" alt="image" src="https://github.com/user-attachments/assets/c11d0c15-f5c8-4623-a6a6-9fcaa58ed48e" />






Test Case 7: Ship  Sunk 

<img width="2067" height="1461" alt="image" src="https://github.com/user-attachments/assets/193a8630-88ad-48e2-9c96-30956c155273" />




Test Case 8: Repeated Attack 


<img width="1491" height="447" alt="image" src="https://github.com/user-attachments/assets/9406bf25-da05-4bf5-bca1-71e9ec7d4a27" />

Test case 9 : 


<img width="1971" height="1605" alt="image" src="https://github.com/user-attachments/assets/49e93770-59de-4c42-8782-12c6f3b6f1cf" />



Test Case 10: Match History  


<img width="2493" height="387" alt="image" src="https://github.com/user-attachments/assets/f6bf9f77-3139-490f-a61a-3f3d36c1bdcd" /> 


<img width="1884" height="573" alt="image" src="https://github.com/user-attachments/assets/eaad887f-bd54-4cf6-9fd5-e7daa29a72b6" /> 


Author : 

Syed Muhammad Saeed (26K-0586)
