
/****************************************************************
   PROGRAM:   REMOVING COMMENTS IN A SOURCE FILE
   AUTHOR:    SYED ABDUL SUBHAN MOIN
   LOGON ID:  Z1788112
   DUE DATE:  Thursday, February 18, 2016

   FUNCTION:  THE PROGRAM TAKES THE SOURCE FILE AND ELIMINATES THE COMMENTS              
   INPUT:     SOURCE FILE WITH COMMENTS
             
   OUTPUT:    THE FILE WITHOUT COMMENTS
                           
              
****************************************************************/

#ifndef removecomment
#define removecomment
#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
#include<fstream>
#include<cctype>
#include<istream>
#include<stdlib.h>
using namespace std;

const string INPUT_FILE = "/home/cs689/progs/16s/p4/prog4-in.cc";
const string OUTPUT_FILE = "prog4-out.cc";
void open_files(ifstream& is,ofstream& os); 
void process_data(ifstream& is, ofstream&os);
void close_files(ifstream& is, ofstream& os); 
void error(const string& msg);
#endif
