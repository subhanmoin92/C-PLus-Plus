
/****************************************************************
   PROGRAM:   PROGRAM 8
   AUTHOR:    SYED ABDUL SUBHAN MOIN
   LOGON ID:  Z1788112
   DUE DATE:  FRIDAY, APRIL 1 2016


   PROGRAM NAME : A CLASS FOR RATIONAL NUMBERS


****************************************************************/

#include"Rational.h" 	// including the header file with all the function prototypes class declarations

using namespace std;




/***************************************************************************************

FUNTION: A PUBLIC CONTRUCTOR 

ARGUMENTS: TWO CONST INT N AND D REPRESENTING NUMBERATOR AND DENOMINATOR

RETURNS: THIS DOESNT RETURN ANYTHING

****************************************************************************************/

Rational::Rational(const int &n,const int &d)
{
	int gcdValue; //integer gcdvalue is declared
	numerator=n;  //numerator is assigned to n
	denominator=d; //denominator is assigned to d 
	
	if (denominator==0)   //if den is 0 then erroe msg is printed
	 cerr << "Error: division by zero"<<endl;
	else if (numerator!=0)  //else if the num is + and den is not 0
	{
		gcdValue=gcd(numerator,denominator);  //gcd of the two is found 
		numerator=numerator/gcdValue;
		denominator=denominator/gcdValue;
	}
	
	if (numerator<0 && denominator<0) //if the values are -
	{
		numerator=numerator*-1;  //num and den are multiplied to -1
		denominator=denominator*-1;
	}
	
}




/***************************************************************************************

FUNCTION: COPY CONSTRUCTOR

ARGUMENT: CONST RATIONAL OBJECT R

RETURNS: THIS DOESNT RETURN ANYTHING

****************************************************************************************/




Rational::Rational(const Rational& r)
{
	
	numerator=r.numerator;  //numerator of r is copied 
	denominator=r.denominator; //denominator of r is copied
	
}




/***************************************************************************************

FUNCTION: PUBLIC ASSIGNMENT OPERATOR

ARGUMENT: A CONSTANT RATIONAL OBJECT R 

RETURNS: THIS RETURNS THE POINTER POINTING TO CURRENT OBJECT
****************************************************************************************/



Rational& Rational::operator=(const Rational& r)
{
	if (this!=&r)  //checking for self assignment
	{	
	numerator=r.numerator;  //num is assigned 
	denominator=r.denominator; //den is assigned
	}
return (*this);  //this is returned
}





/***************************************************************************************

FUNCTION: ostream operator <<(ostream os,const Rational r)

ARGUMENTS: TAKES STREAM AND OBJECT R 

RETURNS : RETURNS VALUE TO STREAM

****************************************************************************************/




ostream& operator<<(ostream& os,const Rational& r)
{
	int num;  //integer numerator
    int den; //integer denominator
    num = r.numerator;  //assigning numerator and denominator of r to num and den
    den = r.denominator;
    if (den==1)  //if den is 1 the numerator is sent
    os << num ;
    else if (num==0)  
    os << num;
    else if (den<0 && num>0)
    os << num*-1 << '/' << den*-1;
    else
    os << num << '/' << den;
	return os;  //os is returned
  
}





/***************************************************************************************

FUNCTION: istream operator(istream is,Rational r)

ARGUMENTS: TAKES STREAM AND OBJECT R 

RETURNS: RETURNS VALUE TO STREAM

****************************************************************************************/


istream& operator>>(istream& is,Rational& r)
{
	
	int eFlag=1,eFlag1=0,eFlag2=0,Flag2=0; 			 //flags are declared to check valid inputs       
	int t_index=0,s_index=0,start=0,hash_index=0;		// variables are used as flags to check positions
	string input; 					//string input is declared
  	string top="",bottom="";			 //to get  num and den 
        getline(is,input); 			//to get the input from is and saved in input

    
    for (unsigned int i=0;i<input.size();i++)
    {
    	if(input[i]=='/'||input[i]==' '||isdigit(input[i])) //checking if the input contains '/' of space or is a digit
    	
    	eFlag=0;  //eFlag is assigned 0
    	
    	if(input[i]!='/'||input[i]==' '||isdigit(input[i]))
    	{
		}
		else
		{
			Flag2=1;  //otherwise flag2 is assigned to 1 
		}
	}
	
	if (eFlag==1)  //checking if the input is invalied 
	cerr << "Error: line \""<<input<<"\" contains invalid number"<<endl;  //error message is printed out
	else
	{
	
	
		for ( unsigned int i=0;i<input.size();i++) //using the loop till the input size
	    {
			if (isdigit(input[i])||input[i]=='-') //if the input contains digits or - then :
	    	{
	    		start=i;// To trim the empty spaces on the left side of the given input.
	    		break;
	    	}
		}
	
	
    
    for (unsigned int i=start;i<input.size();i++)//loop from starting index to the end
    {
    	if (t_index!=1) //proceeding if t_index is not equal to 1
    	{
    		
	    	if (input[i]==' ')
	    	{
	    		s_index=1; //if the input contains a space then s_index is asigned to 1 
			}
	    	else if(isdigit(input[i])||input[i]=='-')  //or else if it contains digit or -
	    	{
	    		if (s_index==1)  //checking spaces between the input
	    		{
	    		eFlag1=1;
	    		break;
	    		}
	    		
	    		top=top+input[i];  //top part that is the numerator is found and stored in string top
	    		s_index=0;   //assuming no spaces present now
	    		
			}
	   		else if(input[i]=='/') //if the / sign is reached meaning the numerator part is done 
	   		{
			   
	   		t_index=1;  //t_index is assigned to 1 and the main if conditions fails which concludes the numerator part
		   	hash_index=i;
			}		
	    }
	    
	}
	
	
	
	
	
	if (eFlag1==1) //checking again for invalid input
	cerr << "Error: line \""<<input<<"\" contains invalid number"<<endl; //if there is invalid input an error message is printed out 
    else
    {
		if (Flag2==1)  //proceeding if flag2 =1 
    	{
		    for ( unsigned int i=hash_index;i<input.size();i++)  //proceeding from hash index to end of the input
		    {
				if (isdigit(input[i]))  //if there is digit 
		    	{
		    		start=i;
		    		break;
		    	}
			}
		    s_index=0; //assuming no spaces in the denominator part
		 
		    for ( unsigned int i=start;i<input.size();i++) //runnig the for loop for the denominator section of the input
		    {
		    		
		    	if (input[i]==' ')  //if there is a space the s_index is assigned to 1 
		    	{
		    		s_index=1;
				}
		    	else if(isdigit(input[i])||input[i]=='-') //if the denominator part contains a digit or - then condition is true
		    	{
		    		if (s_index==1)  //checking spaces
		    		{
		    		eFlag2=1; //if it contains then eFlag2=1
		    		break;
		    		}
		    		
		    		bottom=bottom+input[i]; //getting the final bottom that is denominator part after eliminatiing the space
		    		s_index=0;  //then no spaces 
		    		
				}
		   		else
		   		{
				   eFlag=1;  //else eflag =1
		   		
				}		
			    
			    
			}
		}
    
	}

    if (eFlag2==1)  //again if the input is invalid then the error msg is printed out 
	cerr << "Error: line \""<<input<<"\" contains invalid number"<<endl;
    
    else
    {
	
	if (Flag2!=1)  //if the input contains only the numerator part that is example: 5
    {
	Rational r2(atoi(top.c_str()),1); //denominator is assigned to 1 and top string is converted to integer for rational object r2
    r=r2;
	}
	else //if the input is the normal form that is it contains both numerator and denominator
	{
	
    Rational r2(atoi(top.c_str()),atoi(bottom.c_str()));  //then the top and bottom is converted from string to integer and stored in rational object r2
    r=r2;
    }

  }
    return is; //returning the stream 
}
return is;    	
}




/***************************************************************************************

FUNCTION: Rational operator+(const Rational r1,const Rational r2)

ARGUMENT: TWO RATIONAL OBJECTS r1 and r2

RETURNS: RETURNS THE RESULT AFTER ADDITION OF TWO RATIONALS


****************************************************************************************/



Rational operator +(const Rational& r1, const Rational& r2)
{
	Rational temp1;  //rational object temp1,temp 2 and resutl are declared

    Rational temp2;
    Rational result;
    if (r1.denominator == r2.denominator)//checking if denominator is same

    {

        result.numerator = r1.numerator + r2.numerator;  //only num is added 

        result.denominator = r1.denominator;

    }
    else   //if denominators are different 
    {

        temp1.numerator = r1.numerator * r2.denominator;   //r1 num is multiplied to r2 den

        temp1.denominator = r1.denominator * r2.denominator; //den are multiplied

        temp2.numerator = r2.numerator * r1.denominator;  //the same happens for the other rational number

        temp2.denominator = r2.denominator * r1.denominator;

        result.numerator = temp1.numerator + temp2.numerator; //resultant numerators are added

      result.denominator = temp1.denominator;  //resultant denominator is assigned

    }
	return result;  //result is returned
	
	
	
}





/***************************************************************************************

FUNCTION: Rational operator -(const Rational r1,const Rational r2)

ARGUMENT: TWO OBJECTS OF RATIONAL r1 and r2

RETURNS: RESULT AFTER SUBTRACTION OF TWO RATIONALS

****************************************************************************************/


Rational operator -(const Rational&r1 , const Rational& r2)
{
	
	Rational temp1;  //rational objects temp1,temp2 and result are declared
	Rational temp2;
    Rational result;

    if (r1.denominator == r2.denominator) //checking if the denominators are same

    {

        if (r1.numerator > r2.numerator) //we have to check the greator numerator number in case of subtraction

        {

            result.numerator = r1.numerator - r2.numerator;  //in this case r1 num is greator

            result.denominator = r1.denominator;

        }

        else  //if r2 num is greator then

        {

            result.numerator = r2.numerator - r1.numerator;  //r1 num is subtracted from r2 num

            result.denominator = r1.denominator;

        }

    }

    else  //if the denominators are different the least commom divisor is found

    {

        temp1.numerator = r1.numerator * r2.denominator;  //for object temp 1 , numerator is calculated by multipying r1 num with r2 den

        temp1.denominator = r1.denominator * r2.denominator; //denominators are multiplied for temp1 

        temp2.numerator = r2.numerator * r1.denominator; //same process for temp2 

        temp2.denominator = r2.denominator * r1.denominator;

            if (temp1.numerator > temp2.numerator)  //chceking again the greator numerator

            {

                result.numerator = temp1.numerator - temp2.numerator;  //in this case temp1 numerator is greator 

                result.denominator = temp1.denominator;

            }

            else  //otherwise the temp2 num is greator 

            {

                result.numerator = temp2.numerator - temp1.numerator;//in this case temp2 

                result.denominator = temp1.denominator;

            }

    }

    return result; //object temp is returned after subtraction

		
}







/***************************************************************************************

FUNCTION: Rational operator*(Rational r1,Rational r2)

ARGUMENTS: TWO RATIONAL OBJECTS r1 and r2

RETURNS : THE RESULT AFTER MULTIPLICATION OF TWO OBJECTS

****************************************************************************************/


Rational operator *(const Rational& r1, const Rational& r2)
{
	Rational temp;//rational object temp is declared
    temp.numerator = r1.numerator * r2.numerator;  //r1 num is multiplied to r2 num

    temp.denominator = r1.denominator * r2.denominator;  //r1 den is multiplied to r2 den


    return temp;//object temp is returned after multiplication


}



/***************************************************************************************

FUNCTION: Rational operator/(Rational r1,Rational r2)

ARGUMENTS: TWO RATIONAL OBJECTS r1 and r2

RETURNS : THE RESULT AFTER DIVISION OF TWO OBJECTS


****************************************************************************************/



Rational operator /(const Rational& r1, const Rational& r2)
{
	Rational temp;  					//rational object temp is declared
    temp.numerator = r1.numerator * r2.denominator; 	//r1 num is multiplied to r2 den
    temp.denominator = r1.denominator * r2.numerator; 	//r1 den is multiplied to r2 num and assigned to denominator
    return temp; 					//object temp is returned after division

	
}






/***************************************************************************************

FUNCTION: bool operator==(Rational r1,Rational r2)

ARGUMENTS: TWO RATIONAL OBJECTS r1 and r2

RETURNS : THE BOOLEAN VALUE IS RETURNED 

****************************************************************************************/


bool operator ==(const Rational& r1, const Rational& r2)
{
	
	bool temp; //boolean variable temp is declared
    if ((r1.numerator * r2.denominator) == (r1.denominator * r2.numerator)) //checking if the both are equal of not
    {
        temp = true;  //if they are then it is true 

    }
    else
    {
        temp = false;  //otherwise it is false
    }
    return temp;//final temp value is returned

}






/***************************************************************************************

FUNCTION: bool operator!=(Rational r1,Rational r2)

ARGUMENTS: TWO RATIONAL OBJECTS r1 and r2

RETURNS : THE BOOLEAN VALUE IS RETURNED


****************************************************************************************/


bool operator !=(const Rational& r1, const Rational& r2)
{
	bool temp; //boolean variable temp is declared
    if ((r1.numerator * r2.denominator) == (r1.denominator * r2.numerator))  //checking if both are equal
    {
        temp = false;  //if they are equal then the value is false

    }
    else
    {
        temp = true; //otherwise it is false
    }
    return temp;  //value temp is returned
	
}







/***************************************************************************************

FUNCTION: bool operator<(Rational r1,Rational r2)

ARGUMENTS: TWO RATIONAL OBJECTS r1 and r2

RETURNS : THE BOOLEAN VALUE IS RETURNED


****************************************************************************************/

bool operator <(const Rational& r1, const Rational& r2)
{
	bool temp;  //boolean variable is declared

    if ((r1.numerator * r2.denominator) < (r1.denominator * r2.numerator))  //checking if the first rational is less or not

    {

        temp = true ;//if it is then it is true

    }

    else

    {

        temp = false;  //otherwise it is false

    }

    return temp; //final value is returned

	
}







/***************************************************************************************

FUNCTION: bool operator<=(Rational r1,Rational r2)

ARGUMENTS: TWO RATIONAL OBJECTS r1 and r2

RETURNS : THE BOOLEAN VALUE IS RETURNED

****************************************************************************************/



bool operator <=(const Rational& r1, const Rational& r2)
{
	 bool temp;//boolean variable temp is declared 

    if ((r1.numerator * r2.denominator) <= (r1.denominator * r2.numerator))  //checking if the value is less than or equalto or not

    {

        temp = true;  //if it is then it is true

    }

    else

    {

        temp = false;  //else it is false

    }

    return temp;  //final boolean value is returned

	
}

/***************************************************************************************

FUNCTION: bool operator>(Rational r1,Rational r2)

ARGUMENTS: TWO RATIONAL OBJECTS r1 and r2

RETURNS : THE BOOLEAN VALUE IS RETURNED

****************************************************************************************/




bool operator >(const Rational& r1, const Rational& r2)
{
	bool temp;  //boolean variable temp is declared

    if ((r1.numerator * r2.denominator) > (r1.denominator * r2.numerator))  //checking if the rational is greator or not 

    {

        temp = true; //true if the value is greator

    }

    else

    {

        temp = false; //else the value if false

    }

    return temp; //temp is returned

	
}



/***************************************************************************************

FUNCTION: bool operator>=(Rational r1,Rational r2)

ARGUMENTS: TWO RATIONAL OBJECTS r1 and r2

RETURNS : THE BOOLEAN VALUE IS RETURNED

****************************************************************************************/


bool operator >=(const Rational& r1, const Rational& r2)
{
	bool temp;   	//boolean variable temp is declared
        if ((r1.numerator * r2.denominator) >= (r1.denominator * r2.numerator)) //checking after they have the same denominators
        {

            temp = true;  //returning true

        }
        else

        {

            temp = false;  //else false

        }

    return temp; //result temp is returned

}






/***************************************************************************************

FUNCTION: bool operator+=(Rational r1,Rational r2)

ARGUMENTS: TWO RATIONAL OBJECTS r1 and r2

RETURNS : THE BOOLEAN VALUE IS RETURNED

****************************************************************************************/



Rational& Rational::operator+=(const Rational& r)
{
	int gcdValue;  //integer gcd value is declared
	Rational temp1; //rational object temp1,temp2, and result1 is declared
    Rational temp2;
    Rational result1;
    
    if (this->denominator == r.denominator)   //comparing the denominators

    {

        result1.numerator = this->numerator + r.numerator;  //if denominator are same only numerators are added

        result1.denominator = this->denominator;

    }
    else   //if the denominators are not same
    {

        temp1.numerator = this->numerator * r.denominator;    //current numerator is multiplied to denominator

        temp1.denominator = this->denominator * r.denominator; //current denominator is multiplied to denominator for temp1 

        temp2.numerator = r.numerator * this->denominator; //same goes for object temp2

        temp2.denominator = r.denominator * this->denominator;

        result1.numerator = temp1.numerator + temp2.numerator;  //adding the numerators after the denominators are same

      result1.denominator = temp1.denominator; 

    }
	
	this->numerator=result1.numerator;  //pointing to numerator and denominator after addition
	this->denominator=result1.denominator;
	
	
	if (numerator!=0)  //if the rational is +
	{
		gcdValue=gcd(numerator,denominator); //gcd is found 
		numerator=numerator/gcdValue;
		denominator=denominator/gcdValue;
	}
	
	if (numerator<0 && denominator<0) //if the rational is -
	{
		numerator=numerator*-1;  //num is multiplied by -1
		denominator=denominator*-1; //denominator is multiplied by -1
	}
	
	
	
	return *this;  //current object after addition is returned
	
	
}






/***************************************************************************************


FUNCTION: bool operator-=(Rational r1,Rational r2)

ARGUMENTS: TWO RATIONAL OBJECTS r1 and r2

RETURNS : THE BOOLEAN VALUE IS RETURNED


****************************************************************************************/


Rational& Rational::operator-=(const Rational& r)
{
	
	int gcdValue; //int gcdvalue is declared
	Rational temp1;  //rational objects temp1 and temp2 is declared
	Rational temp2;
    Rational result; //rational result is declared

    if (this->denominator == r.denominator)  //proceeding if denominator are equal

    {

        if (this->numerator > r.numerator)  //if current numerator is greator than rational r numerator

        {

            result.numerator = this->numerator - r.numerator;// simple subtraction is done

            result.denominator = this->denominator;

        }

        else

        {

            result.numerator = r.numerator - this->numerator; //rational r numerator is greator in this case

            result.denominator = this->denominator;

        }

    }

    else  //if denominator are different then subtraction is done in normal basic way

    {

        temp1.numerator = this->numerator * r.denominator;  //numerator is multipled to denominator 

        temp1.denominator = this->denominator * r.denominator;

        temp2.numerator = r.numerator * this->denominator;

        temp2.denominator = r.denominator * this->denominator;

            if (temp1.numerator > temp2.numerator)  //if 1st numerator is greator then 2nd numerator is subtracted from it 

            {

                result.numerator = temp1.numerator - temp2.numerator;

                result.denominator = temp1.denominator;

            }

            else  //otherwise 1st numerator is subtracted from 2nd

            {

                result.numerator = temp1.numerator - temp2.numerator;

                result.denominator = temp1.denominator;

            }

    }

    this->numerator=result.numerator;  //final numerator and denominator is assigned to this pointer
	this->denominator=result.denominator;
	
	
	if (numerator!=0)  //if numerator is +
	{
		gcdValue=gcd(numerator,denominator);  //gcd is found of the two
		numerator=numerator/gcdValue;
		denominator=denominator/gcdValue;
	}
	
	if (numerator<0 && denominator<0) //if its a negetive
	{
		numerator=numerator*-1;  //numerator is multiplied to -1
		denominator=denominator*-1; //denominator is multiplied to -1
	}
	
	
	
	return *this;  //rational after subtraction is returned
	

}







/***************************************************************************************

FUNCTION: bool operator*=(Rational r1,Rational r2)

ARGUMENTS: TWO RATIONAL OBJECTS r1 and r2

RETURNS : THE BOOLEAN VALUE IS RETURNED


****************************************************************************************/




Rational& Rational::operator*=(const Rational& r)
{
	
	int gcdValue;  //integer gcdvalue is declared
	
	Rational temp; //rational object temp 
    temp.numerator = this->numerator * r.numerator;  //multiplying current numerator to numerator of rational r 
    temp.denominator = this->denominator * r.denominator; //multiplying the denominator part

    this->numerator=temp.numerator;  //pointing the current to numerator and denominator after multilpying
	this->denominator=temp.denominator;
	
	
	if (numerator!=0)  //proceeding if the numerator is +
	{
		gcdValue=gcd(numerator,denominator);  //gcd of the rational is found 
		numerator=numerator/gcdValue;
		denominator=denominator/gcdValue;
	}
	
	if (numerator<0 && denominator<0) //if its a negetive
	{
		numerator=numerator*-1;  //multiplying numerator and denominator to -1
		denominator=denominator*-1;
	}
	
	
	
	return *this; //current object after multiplication is returned
	
}






/***************************************************************************************

FUNCTION: bool operator/=(Rational r1,Rational r2)

ARGUMENTS: TWO RATIONAL OBJECTS r1 and r2

RETURNS : THE BOOLEAN VALUE IS RETURNED


****************************************************************************************/




Rational& Rational::operator/=(const Rational& r)
{
	Rational temp;  //object is declared
	int gcdValue;  //integer gcdvalue is declared
    temp.numerator = this->numerator * r.denominator;  //multiplying numerator to denominator of rational r 
    temp.denominator = this->denominator * r.numerator; //multiplying denominator to numerator of rational r 
    this->numerator=temp.numerator;  //assigning to current object
	this->denominator=temp.denominator;
	
	
	if (numerator!=0)  //checking the numerator value
	{
		gcdValue=gcd(numerator,denominator);  //gcd of the number is founc to simplify
		numerator=numerator/gcdValue;
		denominator=denominator/gcdValue;
	}
	
	if (numerator<0 && denominator<0)
	{
		numerator=numerator*-1;
		denominator=denominator*-1;
	}
	
	
	
	return *this;  //returning the current 
	
	
}




/***************************************************************************************

FUNCTION: Rational operator++

ARGUMENTS: NO ARGUMENTS

RETURNS : A POINTER POINTING TO CURRENT OBJECT IS RETURNED 
****************************************************************************************/



Rational& Rational::operator++()
{	
	this->numerator=this->numerator+this->denominator;  //incrementing the rational by 1 		
	return *this;  //returning the value after incrementing
	
}




/***************************************************************************************

FUNCTION: Rational operator--

ARGUMENTS: NO ARGUMENTS

RETURNS : A POINTER POINTING TO CURRENT OBJECT IS RETURNED


****************************************************************************************/


Rational& Rational::operator--()
{	
	this->numerator=this->numerator-this->denominator;  //decrementing the rational		
	return *this; //returning the value after decrementing
	
}





/***************************************************************************************

FUNCTION: Rational operator++

ARGUMENTS: AN UNUSED INTEGER IS USED

RETURNS : A POINTER POINTING TO CURRENT OBJECT IS RETURNED


****************************************************************************************/



Rational Rational::operator++(int unused)
{	
	(void)unused;  //to avoid the compiler warning 
	Rational r=*this;   //pointing to current object r

	this->numerator=this->numerator+this->denominator;  //incrementing the rational by 1 	
	
	return r;  //returning r 
	
}





/***************************************************************************************

FUNCTION: Rational operator--

ARGUMENTS: AN UNUSED INTEGER IS USED

RETURNS : A POINTER POINTING TO CURRENT OBJECT IS RETURNED


****************************************************************************************/


Rational Rational::operator--(int unused)
{	
	(void)unused; //to avoid the compiler warning
	Rational r=*this;  //pointing to current object r 

	this->numerator=this->numerator-this->denominator;  //decrementing the rational number by 1 	
	
	return r;  //returning r
	
}





/***************************************************************************************

FUNCTION: int gcd(int x,int y)

ARGUMENTS: TWO ARGUMENTS INTEGER X AND Y

RETURNS : GCD OF THE NUMBER IS RETURNED


****************************************************************************************/


int Rational::gcd(int x, int y)
{
	if(x<0)  //proceeding only if x<0
	x=x*-1;  //multiplying x to -1
	
	if(y<0)  //in case of y <0
	y=y*-1; //multiplying y to -1
	
	while(x!=y)//implementing euclidean algorith
	{
		if(x>y)
		x=x-y;//subtracting the lesser number
		else
		y=y-x;
		
	}
	
	
	return x;   //x is returned
}	
