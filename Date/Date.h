
/****************************************************************
   PROGRAM:  PROGRAM 7
   AUTHOR:    SYED ABDUL SUBHAN MOIN
   LOGON ID:  Z1788112
   DUE DATE:  THURSDAY, MARCH 24 2016
  
              
   PROGRAM NAME : THE DATE CLASS - PHASE 2
                            
              
****************************************************************/


#ifndef _date_h
#define _date_h
#include<iostream>
#include<iomanip>
#include<cctype>
#include<stdlib.h>
#include<sstream>
#include<fstream>
#include"Date.h"
//#include<vector>

using namespace std;



extern const int DAY;         // constant for default day
extern const int YEAR;       // constant for default year
extern const string MONTH;   // constant for default month




class Date                // class declaration starts here
{
private:                 // this is the private section 

string month;
int day;
int year;
friend istream& operator>>(istream& , Date& );            // friend function is declared fo overload >> operator 
friend  bool printDate(const Date&);                 // this function is used to print valid date
friend ostream& operator<<(ostream&, const  Date&);       // << operator is overloaded
int daysInMonth ()const;                              //this function prototypes get the value of days in month
bool isLeapYear ()const;                      // checks if its a leap year
bool isValidMonth()const;             // checks if its a valid month



public :                     // this is the public section of the class 

Date(const string m="January",const int d=1 ,const int y=2000 );   // parameterized constructor
Date(const Date& d);		//copy constructor
void setMonth(const string&);               //this function is used to modify the value of month
void setDay(const int&);                // this function is used to modify the value of day
void setYear(const int&);               // this function is used to modify the value of year
Date& addDay(const int&); 	//this function adds no of days  
Date& addMonth(const int&); 	//this function adds no of months
Date& addYear(const int&); 	//this function adds no of years
Date& operator=(const Date&);	//this is assignment operator
friend unsigned dateDiff(const Date& , const Date& ); //this is friend function used to find difference betweent he dates
string getMonth()const;                // this function is used to get the value of month
int getYear()const;               // this function is used to get the value of year
int monthIndex() const;    //this function determines the index of the month
int dayIndex() const;	//this function determines the index of day
int getDay()const;                   // this function is used to get the value of day
void Month();                      // changes the case of month
bool isValidDate()const;                 // checks if a given date is valid
std::string toString() const ;             // this converts the date to string

};



std::istream& operator>>(std::istream&,Date&); // this overloads >> operator
std::ostream& operator<<(std::ostream&,const Date&); //this overloads << operator
bool printDate(const Date&);               // this function is used to print the date


#endif 
