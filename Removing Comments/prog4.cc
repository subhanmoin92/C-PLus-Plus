
/****************************************************************
   PROGRAM:   REMOVING COMMENTS IN A FILE
   AUTHOR:    SYED ABDUL SUBHAN MOIN 
   LOGON ID:  Z1788112
   DUE DATE:  Thursday, February 18, 2016

   FUNCTION:  THE PROGRAM ELIMINATES THE COMMENTS FROM THE SOURCE FILE.
              

   INPUT:     A SOURCE FILE IS GIVEN AS THE INPUT.
              

   OUTPUT:    THE SOURCE FILE WITHOUT THE COMMENTS IS THE OUTPUT.
              
                          

   NOTES:    THE STATEMENTS IN STRINGS, COMMENTS AND CHARACTER CONSTANTS ARE PRESERVED.           
****************************************************************/

#include "prog4.h"      /* the header file includes all the prototypes and constants required for the program*/ 


int main()
{
ifstream infile;         
ofstream outfile;     
open_files(infile,outfile);  /*this is used to open and store the output of the file*/ 
cout<<"The files have opened successfully"<<endl;  
process_data(infile,outfile); /* This calls the function to process the file where it removes all the comments from it*/
cout<<"The files have been processed succesfully"<<endl;
close_files(infile, outfile); /* this function closes the files after they have been read and modified*/
cout<<"The files have been closed successfulyy"<<endl;
}




/****************************************************************
    FUNCTION: void error(string msg)

    OUTPUT:  AN ERROR MESSAGE IS DISPLAYED AS OUTPUT



****************************************************************/

void error(const string &msg)  
{
cerr<<msg<<endl;
exit(EXIT_FAILURE);
}




/****************************************************************

   FUNCTION:   THIS FUNCTION OPENS TWO FILES WHICH IS THE INPUT AND THE OTHER ONE IS OUTPUT

   ARGUMENTS:  THE FILE STREAMS FOR READING AND WRITING ARE PASSED AS ARGUMENTS

   RETURNS:    THIS DOESNT RETURN ANYTHING

****************************************************************/


void open_files(ifstream & is, ofstream& os) 
{
is.open(INPUT_FILE);     /* ifstream opens prog4-in.cc which is the source file*/
if(is.fail())   
error("ERROR : SOURCE FILE CANNOT BE OPENED");
os.open(OUTPUT_FILE);       /* ofstream opens prog4-out.cc where the output is stored*/
if(os.fail())        
error("ERROR : OUTPUT FILE CANNOT BE OPENED");
}

/****************************************************************

   FUNCTION:   void proces_data(ifstream &, ofstream&);

   ARGUMENTS:  STREAM VARIABLES ARE PASSED AS ARGUMENTS

   RETURNS:    THIS FUNCTION DOESNT RETURN ANYTHING

   
****************************************************************/


void process_data(ifstream& is, ofstream& os)
{
int char1, char2;      /*char1 stores the first character and char2 stores the next character*/
bool CommentFlag,SingleComment,StringFlag; /* CommentFlag is used to indicate multiple line comments, SingleComment is used for single line comment, StringFlag is used for comment symbols within strings*/
StringFlag=false;  /* all the flags are initially assigned to false*/
CommentFlag = false;
SingleComment=false;
while ((char1 = is.get()) != EOF) 
{  
if(SingleComment)
{                          /*if the single line comment is true, make it false at the end of the line*/
if(char1=='\n') 
SingleComment=false;
if(CommentFlag)
{ 
CommentFlag=false;   /* if there is  a multiple line comment within single line comment,make it false as it has no significance*/
SingleComment=true;
}    
} 
if (CommentFlag )
{      /* if the  multiple line comment is true, make it false when comment symbols appears*/

if (char1 == '*' ) 
{ 
char2 = is.get();    
if (char2 == '/') 
{
CommentFlag = false;  /* if the end of multiple comment characters appear, it is turned false*/
} 
else
{             
is.unget();
}
}
} 

else 
{             /* if the comment flags are false still, it looks for both comment characters*/
if(char1=='"'){       
os.put(char1);              /*display all the characters that appear within double quotes as strings*/
while((char2=is.get()) !='"')
os.put(char2);
}

if (char1 == '/')
{       /* if the character is /, look for next character as * to assign true value to multiple comment flag*/
char2 = is.get();
if (char2 == '*') 
{
CommentFlag = true;
}
if(char2=='/') 
SingleComment=true;  /*check if the first character is /,if it is then look for next character as / to make the SingleComment as true*/
else
{
is.unget();         
}
}

if (((!CommentFlag && !SingleComment))&&!StringFlag) os.put(char1);  /*finally write on the output file if none of the flags are true*/
}
}
}

/****************************************************************

   FUNCTION:   void close_files(ifstream&,ofstream&);

   ARGUMENTS:  FILE STREAMS ARE PASSED AS ARGUMENTS

   RETURNS:   THIS DOESNT RETURN ANYTHING

****************************************************************/
void close_files(ifstream& is, ofstream& os)
{
is.close();
os.close();
}

