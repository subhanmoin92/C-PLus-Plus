/****************************************************************
   PROGRAM:   PROGRAM 8
   AUTHOR:    SYED ABDUL SUBHAN MOIN
   LOGON ID:  Z1788112
   DUE DATE:  FRIDAY, APRIL 1, 2016


   PROGRAM NAME : A CLASS FOR RATIONAL NUMBERS


****************************************************************/


#ifndef rational
#define rational
#include<iostream>  //required libraries
#include<iomanip>
#include<cctype>
#include<stdlib.h>
#include<sstream>
#include<fstream>
#include"Rational.h"


using namespace std;



class Rational    				//a class Rational                 
{

private:			//this is private section of the class
	int numerator;		//integer numerator is declared
	int denominator;	 //integer denominator is declared
	int gcd(int , int);  	// prototype for the function gcd 



public :    			//this is the public section of the class

Rational(const int &n=0,const int &d=1); 	 //this is public constructor

Rational(const Rational&); 			 //the public copy constructor

Rational& operator=(const Rational&);  		//assignment operator

Rational& operator+=(const Rational&); 		//member function which overloads +=
Rational& operator-=(const Rational&); 		//member function which overloads -=
Rational& operator*=(const Rational&); 		//member function which overloads *=
Rational& operator/=(const Rational&); 		//member function which overloads /=

Rational& operator++();		 	 //member function for pre increment
Rational& operator--(); 		//member function for pre decrement

Rational operator++(int ); 		//member function for post increment
Rational operator--(int ); 		//member function for post decrement

friend Rational operator +(const Rational& , const Rational& ); 	//member function which overloads +
friend Rational operator -(const Rational& , const Rational& ); 	//member function which overloads -
friend Rational operator *(const Rational& , const Rational& ); 	//member function which overloads *
friend Rational operator /(const Rational& , const Rational& ); 	//member function which overloads /


friend bool operator ==(const Rational& , const Rational& );	//friend function which overloads ==
friend bool operator !=(const Rational& , const Rational& );	//friend function which overloads !=
friend bool operator <(const Rational& , const Rational& );	//friend function which overloads <
friend bool operator <=(const Rational& , const Rational& );	//friend function which overloads <=
friend bool operator >(const Rational& , const Rational& );	//friend function to overload >
friend bool operator >=(const Rational& , const Rational& );	//friend function to overload >=

friend istream& operator>>(istream&,Rational&); 		//friend function to overload stream extraction operator
friend ostream& operator<<(ostream&,const Rational&); 		//friend function to overload the stream insertion operator



};  //end of class




#endif 


