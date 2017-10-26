
/********************************************************************************************

PROGRAM : GAME OF MINESWEEPER

AUTHOR:   SYED ABDUL SUBHAN MOIN

LOGON ID: Z1788112

DUE DATE: FRIDAY, FEBRUARY 26, 2016

FUNCTION: THIS PROGRAM DEVELOPS A GAME OF MINESWEEPER

********************************************************************************************/


#ifndef minesweeper
#define minesweeper

#include<iostream> 		// includes the header file iostream
#include<fstream>		// include fstream header file
#include <vector>		//includes the vector header file
#include <stdlib.h>
using namespace std;


//the function prototypes are declared which are used in the source file 


void displayMineLocations(const vector< vector<bool> >&mines);   		
void displayMineCounts(const vector< vector<unsigned> >&counts);
void buildMineField(vector< vector<bool> >&mines,const double& mineProb);
void fixCounts(const vector< vector<bool> >&mines,vector< vector<unsigned> >&counts);
#endif
