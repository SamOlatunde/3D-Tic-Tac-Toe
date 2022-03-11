// Samuel Olatunde 
// November 16, 2021
// This program is traditional tic-tac-toe game, with the added twist that players can play on top of otherpieces. 
#include <iostream>
#include <cctype>

// can this program have a kill switch, like like a way of pausing in between like the way real games are
#include "stack.h"

using namespace std;

// declaring the constants for this program
const int SIZE = 3;
const char x = 'X', o = 'O';

// function prototypes
bool dia(Stack gameboard[SIZE][SIZE],char);
bool checkWin(Stack gameboard[SIZE][SIZE], char op);
void printBoard (Stack gameboard[SIZE][SIZE]);
bool isFull(Stack gameboard[SIZE][SIZE]);
void playx(Stack gameboard[SIZE][SIZE]);
void playo(Stack gameboard[SIZE][SIZE]);


int main() 
{
  //variable declaration
  char cont;
  
  // loop to allow the players to keep on playing without having to run the program again
  do 
  { 
    // 2D array of the stack that serves as the gameboard
    Stack gameboard[SIZE][SIZE];
  
    // initializing the gameboard with blank spaces 
    for(int r = 0; r < 3; r++)
    {
      for(int c = 0; c < 3; c++)
        gameboard[r][c].push(' ');
    }

  
    playx(gameboard);

    // user prompt
    cout << "\nPress 'y' to play again or any other key to stop the game ";
    cin >> cont;
    cont = tolower(cont);
  }while (cont == 'y');
  
 
 return 0;
} 

 
//Name: checkWin
//Input: takes in a 2D array of structs, and a char variable
//Process: checks if any player has won after every move
//Output: returns true or false 
bool checkWin(Stack gameboard[SIZE][SIZE], char op)
{
  // declaration and initialization of flags for the different win instances (vertical, horizontal, or diagonal)
  bool flagRow = false, flagCol = false, flagDiag = false, checkWinner = false;

  // checking horizontally 
  for (int r = 0; r < SIZE; r++)
  {
    // if every character on a row matches
    if (gameboard[r][0].peek()==op && gameboard[r][1].peek()== op && gameboard[r][2].peek() == op)
    {
      flagRow = true;
    }
  }

  // checking vertically
  for (int c = 0; c < SIZE; c++)
  {

    // if every character on a column matches
    if (gameboard[0][c].peek()== op && gameboard[1][c].peek()== op && gameboard[2][c].peek() == op)
    {
      flagCol = true;
      
    }
  }

  // checking diagonally+
  if ((gameboard[0][0].peek()== op && gameboard[1][1].peek()== op && gameboard[2][2].peek() == op) || (gameboard[0][2].peek()== op && gameboard[1][1].peek()== op && gameboard[2][0].peek() == op))
  {
    
    flagDiag = true;
    
  }
   

  if (flagRow == true || flagCol ==true || flagDiag == true)
  {
    checkWinner = true;
  }

  return checkWinner;
}


//Name: printBoard
//Input: takes in a 2D array of structs, and a char variable 
//Process: prints the elements 
//Output: 
// methods that prints the game in a relative and not absolute way
void printBoard (Stack gameboard[SIZE][SIZE])
{
   cout << "Board:" << endl << endl;
  cout << " " << gameboard[0][0].peek() << " | " << gameboard[0][1].peek() << " | " << gameboard[0][2].peek() << endl;
  cout << "---+---+---" << endl;
  cout << " " << gameboard[1][0].peek() << " | " << gameboard[1][1].peek() << " | " << gameboard[1][2].peek() << endl;
  cout << "---+---+---" << endl;
  cout << " " << gameboard[2][0].peek() << " | " << gameboard[2][1].peek() << " | " << gameboard[2][2].peek() << endl;
  cout << endl;
} 


//Name: checkWin
//Input: takes 
//Process:
//Output: 
// method to check if the board is fool
bool isFull(Stack gameboard[SIZE][SIZE])
{
  int count = 0;
  for (int r = 0; r < SIZE; r++)
  {
    for (int c = 0; c < SIZE; c++)
    {
      if (gameboard[r][c].Size() == 4)
      {
        count ++;
      }
    }
  }
  
  return (count == 9);
}


//Name: checkWin
//Input: takes 
//Process:
//Output: 
//the next two methods would use indirect recursion play the game
void playx(Stack gameboard[SIZE][SIZE])
{
  int row = 0, col = 0;
  cout << "Row: ";
  cin >> row;
  cout << "Col: ";
  cin >> col;
  // plays x at the specified location
  gameboard[row][col].push(x);

  // prints the board
  printBoard(gameboard);
  
  if (checkWin(gameboard,x))
  {
    cout << "X has won, congratulations!! " << endl;
  }
  else if (isFull(gameboard))
  {
    cout << "The board is full and nobody has won, it's a draw!" << endl;

  }
  else 
  {
    playo(gameboard);
  }

  
}

//Name: checkWin
//Input: takes 
//Process:
//Output: 
void playo(Stack gameboard[SIZE][SIZE])
{
   int row = 0, col = 0;
  cout << "Row: ";
  cin >> row;
  cout << "Col: ";
  cin >> col;

  // plays o at specified location
  gameboard[row][col].push(o);

  // prints the board
  printBoard(gameboard);
  
  if (checkWin(gameboard,o))
  {
    cout << "O has won, congratulations!! " << endl;
  }
  else if (isFull(gameboard))
  {
    cout << "The board is full and nobody has won, it's a draw!" << endl;

  }
  else 
  {
    playx(gameboard);
  }
}