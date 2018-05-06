CSCI/CMPE 2380
Topics: Dynamic 2D arrays, classes and methods
In this assignment you are to create a connect-4 game. The standard game has 6 rows and 7 columns.
The interface will look like this (with the highlighted numbers being user input).

   0 1 2 3 4 5 6
0 |             |
1 |             |
2 |             |
3 |             |
4 |             |
5 |             |
 - - - - - - - - -
It is X's turn:
Column: 3
   0 1 2 3 4 5 6
0 |             |
1 |             |
2 |             |
3 |             |
4 |             |
5 |      X      |
 - - - - - - - - -
It is O's turn:
Column: 3
   0 1 2 3 4 5 6
0 |             |
1 |             |
2 |             |
3 |             |
4 |      O      |
5 |      X      |
 - - - - - - - - -
It is X's turn:
Column:
The requirements are as follows:
- it must follow the rules (gravity and such)
- must check for winning conditions
- if a user wins, the game ends and the winner is declared
- the program should check for illegal input (columns less than 0 and greater than number
of columns)
- there needs to be a 1 player option with a basic AI that plays the game. There is no
constraint on this, it can play poorly.
- The game and logic should be contained in a Connect4 class with the following methods
- void DrawBoard()
- bool GameOver()
- char Winner()
- bool MakeMove(char piece, int column)
- Connect4() //sets up standard game
- Connect4(int NumRows, int NumColumns) //custom gameboard size
- int GetAIMove()
- The connect 4 class should be in a separate header file.
- The main.cpp file should contain the basic game loop and start up which asks the user
how many players and whether it is the standard game or a custom board.
Bonus (10): Modify the game so that you can have more than 2 players with the custom board.