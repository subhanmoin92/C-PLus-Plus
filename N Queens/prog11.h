/**************************************************************


   PROGRAM : N QUEENS PUZZLE

   AUTHOR:   SYED ABDUL SUBHAN MOIN

   DUE DATE:  Monday, 2nd May, 2016

   FUNCTION:  Display the solution of n queens problem if it exists

   
****************************************************************/

#ifndef queen
#define queen

#include<iostream>	//different system libraries required for the program
#include<string>
#include<iomanip>
#include<cmath>
#include<fstream>
#include<sstream>
#include<vector>

using namespace std;
  
        
void solveNQueens ( const unsigned& n );       // This function prototype takes n value and computes for result

bool solveNqueensUtil ( vector < vector < bool > >& board, const unsigned& col );   // This is a recursive function where every row value is checked for every column so that to place a queen

bool isSafe ( const vector < vector < bool > >& board, const int& row, const int& col );  // this function is used to see if a queen is safe to be  placed at the position or not 

void initBoard(vector<vector<bool>> & board, unsigned n  );    //it initializes random values and set them to false

void printBoard(const vector<vector<bool>> & board,const unsigned  n); //this function prints the output


#endif
