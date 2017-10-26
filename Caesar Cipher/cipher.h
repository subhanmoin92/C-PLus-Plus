/****************************************************************
   PROGRAM:   CAESAR CIPHER
   AUTHOR:    SYED ABDUL SUBHAN MOIN
   LOGON ID:  Z1788112
   DUE DATE:  Wednesday, February 10, 2016

   FUNCTION:  THE PROGRAM TAKES TEXT FROM A DATA FILE AND ENCRYPTS IT USING
              A SPECIFIED KEY

   INPUT:     THE TEXT TO BE ENCRYPTED IS IN prog3.d2. SHIFT VALUES CAN BE
              GIVEN FROM KEYBOARD OR prog3.d1

   OUTPUT:    THE OUTPUT CAN BE DISPLAYED ON THE SCREEN OR AN OUTPUT FILE
              DEPENDING ON THE WAY IT IS EXECUTED



****************************************************************/


#ifndef cipherhr
#define cipherhr

#include <iostream>
#include <string>
#include<iomanip>
#include<cmath>
#include<fstream>
#include<cctype>
#include<istream>

#include<stdlib.h>
using namespace std;
extern const string DATAPATH;   
extern const int ALPH;  
void process_infile(int shift); 
string encodeCaesarCipher(string str,int shift); 
int new_position(char c, int shift); 
void error(const string& msg);
#endif
