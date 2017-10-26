/****************************************************************
   PROGRAM:   A SIMPLE CALCULATOR
   AUTHOR:    SYED ABDUL SUBHAN MOIN

   LOGON ID:  Z1788112  

   DUE DATE:  TUESDAY ,APRIL 12 2016

   PROGRAM:   A SIMPLE CALCULATOR
              
              
****************************************************************/



#include"prog9.h" //including all the function prototypes and library routines from the header file

using namespace std;




int main()
{
stack <double> S;      // stack S is declared
string token;              // string token is declared for input
while ( cin >> token ) 
{
process_token(token,S);     // call to the function process_token 
}
}







/****************************************************************

   FUNCTION:  void process_token(const string& token, stack<double> &S);  

   ARGUMENTS:  string token and stack S

   RETURNS:   IT DOESNT RETURN ANYTHING

  ****************************************************************/


void process_token( const string& token, stack<double> &S)  
{
bool floatPointFlag=true;      // checking if its a floating point or not
for(unsigned i=0;i<token.length();i++) // checking for individual characters in the token
{
char c=token[i];      //character c is declared and the first character is stored 
bool b1 = unarySign(c,token,i);  // checking if it has a unary sign or a decimal point



bool b2 = floatPoint(c,token,i); //checking for a decimal point


if(isdigit(c)||b1||b2 && !isValidOperator(c) && c!='=' && c!='!')  //proceeding if its a valid input
{
bool flag1=false, flag2=false; // first flag is used to look for unary - and second flag for unary +
if(b1 && c=='-')
{
 i++;
c=token[i];   // converting the number into negative value
 flag1= true; //assigning true to flag1 
b1=false;
}
if(b1 && c=='+')
{
i++;
c=token[i];
flag2=true;   // converting it to positive value
b1=false;
}

string s;
while(isdigit(c) || b2 && !isValidOperator(c)) 
{
s+=c;
i++;     // this loop is used to build the starting number
c = token [ i ];
              
if(c=='.' && !isValidOperator(c)) 
{   // the condition for floating points is considered to add them to the string
b2=false;
s+=c;
i++;
c=token[i];
}
		
}
i--;
c = token [ i ];


double num=getNumber(c,s,i,floatPointFlag); // getting the number in double form 
	
if(flag1) num=num*(-1);    // if there is unary - value, converting it to a negative number
else num=num*1;
	
S.push(num);     // adding the number into the stack
}
else if(isValidOperator(c))  // checking if the character is a valid operator.
{

	double n1=popStack(S); //if the character is valid then getting the values and performing the computation
	double n2= popStack(S);
        if(n1!=0.00 && n2!=0.00)
{ 
	double res=operation(c, n1,n2);
	S.push(res);

}
}
else if(c=='=')       //if the character is =
{
printResult(S); //printing the result
}
else if(c=='c') //if the value is 'c'
{                                    
emptyStack(S); //empty the stack
}
else 
{
cerr<<"error: character "<<"'"<<c<<"'"<<" is invalid"<<endl;   // error message is displayed if none of these if conditions are encountered

}

}
}







/****************************************************************

   FUNCTION: bool unarySign ( const char& c, const string& token, const unsigned& i );

   ARGUMENTS: currect character c, string token and position i

   RETURNS:  A BOOLEAN VALUE IS RETURNED

  ****************************************************************/

bool unarySign ( const char& c, const string& token, const unsigned& i )
{
unsigned pos=token.length()-1;  // checking if the number is unary number or not

if(c=='-' || c=='+') //checking for - or +
{
if(i!=pos && (isdigit(token[i+1]) || token[i+1]=='.')) // if the sign apprears before a digit or after decimal point
return true;
else return false;
}
else return false;
}






/****************************************************************

   FUNCTION:  bool floatPoint ( const char& c, const string& token, const unsigned& i );

   ARGUMENTS: currect character c, string token and position i

   RETURNS:  BOOLEAN VALUE IS RETURNED

  ****************************************************************/



 bool floatPoint ( const char& c, const string& token, const unsigned& i )
{
unsigned pos=token.length()-1;  // pos is assigned the length
bool flag=false;
for(unsigned i=0;i<token.length();i++) //checking for the loop 
{
if(token[i]=='.')  //checking for decimal points
{
if(i!=pos && isdigit(token[i+1]))   // decimal should be succeeded by a digit
flag= true;
}

}
return flag;
}







/****************************************************************

   FUNCTION: double getNumber ( const char& c, const string& token, unsigned& i, const bool& floatPointFlag)
;
   ARGUMENTS: character c, string token,  position i and floatPointFlag

   RETURNS:  DOUBLE NUM IS RETURNED

 ****************************************************************/


double getNumber ( const char& c, const string& token, unsigned& i, const bool& floatPointFlag)
{

char buff[100];
int count=0;
              // the number of decimal points are checked.
for(unsigned j=0,i=0;j<token.length();j++,i++)
{
if((isdigit(token[j]))||(token[j]=='.'))
buff[i]=token[j];


if(token[j]=='.') count++;                                  // if there are more, displa y error

}
buff[token.length()]='\0';
if(count>1) {
cerr<<"error: number"<<" '";
for(unsigned k=0;k<token.length();k++)
if((token[k]>='0' && token[k]<='9')||token[k]=='.')
cerr<<token[k];
cerr<<"' is invalid"<<endl;
exit(1);
}


double num=stringToDouble(token);                                 // or convert it to double number and return it
return num;
}






/****************************************************************

   FUNCTION:bool isValidOperator ( const char& c );

   ARGUMENTS: character c

   RETURNS: A BOOLEAN VALUE IS RETURNED

  ****************************************************************/


bool isValidOperator ( const char& c )                   // check if it s a valid operator
{
if(c=='+'||c=='-'||c=='*'||c=='/') //checking if its a +,-,* or /
return true; //if yes then returning true else false
else return false;
}






/****************************************************************

   FUNCTION: double operation ( const char& c, const double& x, const double& y );
   ARGUMENTS: character c, double x, y

   RETURNS:  RESULT OF OPERATION

****************************************************************/



double operation ( const char& c, const double& x, const double& y )
{
switch(c)
{
case '+': return x+y; break;  //performing the operation addition
case '-': return y-x; break;  // performing the operation subtraction
case '*': return x*y; break;  //performing the operation multiplication
case '/': return y/x; break; //performing the operation division
default:

return 0;
}
}




/****************************************************************

   FUNCTION:double popStack ( stack < double >& S );

   ARGUMENTS: Stack S

   RETURNS: TOP ELEMENT OF STACK IS RETURNED

****************************************************************/


double popStack ( stack < double >& S )
{
if( S.empty())  //checking if the stack is empty or not
{
cerr<<"error: stack is empty"<<endl; //error message is displayed if the stack is empty
return 0;
}                                                         
else
{
double n= S.top();   // declaring n and top element of S is assigned to it 
S.pop(); //and element is removed
return n; //returning n 
}
}





/*****************************************************************************

   FUNCTION:void printResult ( const stack < double >& S );
 
   ARGUMENTS: Stack S

   RETURNS: RESULT IS RETURNED

******************************************************************************/

void printResult ( const stack < double >& S )
{
double res;  //double res for result is declared
if(S.empty()) cerr<<"Stack is empty ";  //error message is displayed if stack is empty 

     
else  //else the result is displayed which is stored in stack
{
res= S.top();

cout<<fixed<<setprecision(2)<<showpoint<<"Result is "<<res<<endl;

}
}







/****************************************************************

   FUNCTION:void emptyStack ( stack < double >& S );

   ARGUMENTS: Stack S

   RETURNS: TOP ELEMENT IS POPPED UNTIL THE STACK IS EMPTY

  ****************************************************************/

void emptyStack ( stack < double >& S )
{
while(!S.empty())        // this function empties the stack
{
popStack(S);//double num=popStack(S);
}
}






/*********************************************************************************

   FUNCTION:voidtringToDouble(string s);

   ARGUMENTS: STRING IS PASSED AS ARGUMENT

   RETURNS: DOUBLE D IS RETURNED

********************************************************************************/


double stringToDouble(string s)
 {
double d;
stringstream ss(s); //turn the string into a stream 
ss >> d; //this takes the string stream and converts the string into double
return d;
}


