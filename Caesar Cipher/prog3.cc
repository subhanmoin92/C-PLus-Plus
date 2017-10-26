/****************************************************************
   PROGRAM:   CAESAR CIPHER
   AUTHOR:    SYED ABDUL SUBHAN MOIN	
   LOGON ID:  Z1788112
   DUE DATE:  Wednesday, February 10, 2016

   FUNCTION:  THE PROGRAM TAKES TEXT FROM A DATA FILE AND ENCRYPTS IT USING
              A KEY

   INPUT:     THE TEXT TO BE ENCRYPTED IS IN prog3.d2. AND THE SHIFT VALUES CAN BE
              GIVEN FROM KEYBOARD OR prog3.d1

   OUTPUT:    THE ENCRYPTED DATA IS GIVEN
              
****************************************************************/


#include "prog3.h"              /* The header file consists of function prototypes, all libraries required and constants declaration*/
using namespace std;
extern const string DATAPATH="/home/cs689/progs/16s/p3/prog3.d2";   /* the DATAPATH variable stores the DATAPATH of the string whose data is to be encrypted.*/
extern const int ALPH=26;
int main()                               
{
string str;
int shift;                 /* integer shift is declared which is used to stores the value entered from keyboard*/
while ( cin >> shift ) 
{   
process_infile(shift);      
cout<<"\t"<<shift;     
}
return 0;
}


void process_infile(int shift)     
{
ifstream infile1;   		/*used for reading the file*/
string s1,s2;       		/*two strings s1 and s2 are declared which is used for getline and to store the encrypted returned text.*/
infile1.open(DATAPATH); 		/*the file is opened using the DATAPATH.*/
if(infile1.fail()) error("Error : file cannot be opened");  /*Error message is displayed*/
cout<<endl<<shift<<endl; 
while(!infile1.fail()) 		 /*the loop is executed untill the end of file is reached.*/
{
getline(infile1,s1); 		/*string value is s1*/
s2=encodeCaesarCipher(s1,shift); /* cipher function is called to encrypt the data and is stored in s2*/
cout<<" "<<s2;   
}
infile1.close(); 
}



string encodeCaesarCipher(string str, int shift)
{
if((shift>ALPH) || (shift<-ALPH))   /*to check if the shift value is in between 26 and -26*/
shift%=ALPH;
unsigned i=0;               
while(i<str.length())                 
{
int pos=new_position(str[i],shift);  /*integer pos is declared to store the new position after using caesar cipher*/
str[i]=(char)pos;   			/*the ascii value is changed to character*/
i++;              
}
return str;           /*the encrypted string is returned*/
}


int new_position(char c, int shift)
{
int num;
if(c==' ') return 32;            /*new position of the character is stored*/
if(c>='a' && c<='z')    
{
if((c+shift)>'z')       /* if the new value is greater than z, then subtract 26 */
num=c-ALPH+shift;
else if(c+shift<'a')  /* if the value is less than a, add 26 */
num=c+shift+ALPH;
else 
num=c+shift;   
}		
if(c>='A' && c<='Z')   
{
if((c+shift)>'Z')
num=c-ALPH+shift;
else if(c+shift<'A')
num=c+shift+ALPH;
else
num=c+shift;
}		
return num;     
}


void error(const string& msg)   // The message written in cerr is stored in msg
{
cerr<<msg<<endl;
exit(EXIT_FAILURE);
}

