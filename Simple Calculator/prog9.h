/****************************************************************
   PROGRAM:   A SIMPLE CALCULATOR
   AUTHOR:    SYED ABDUL SUBHAN MOIN

   LOGON ID:  Z1788112

   DUE DATE:  TUESDAY ,APRIL 12 2016

   PROGRAM:   A SIMPLE CALCULATOR


****************************************************************/


#ifndef calc
#define calc

#include <iostream> //including the different library routines
#include <string> 
#include<iomanip>
#include<cmath>
#include<fstream>
#include<sstream>
#include<stack>

using namespace std;

void process_token ( const string& token, stack< double >& S ); //this routine is used to inspect each character in the token is sequence and takes proper action

bool unarySign ( const char& c, const string& token, const unsigned& i ); //predicate function to determing the unarysign

bool floatPoint ( const char& c, const string& token, const unsigned& i ); //predicate function to check the floating point 

double getNumber ( const char& c, const string& token, unsigned& i, const bool& floatPointFlag );//routine to get all the characters of token

bool isValidOperator ( const char& c ); //routing to check if it is + - * /

double operation ( const char& c, const double& x, const double& y ); //this performs the required function

double popStack ( stack< double >& S ); //this removes the top number of the stack

void printResult ( const stack< double >& S );//this prints out the top number of S

void emptyStack ( stack<double>& S ); //this empties the stack

double stringToDouble( string );//this converts the string to double value

#endif
