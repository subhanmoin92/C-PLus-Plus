
/*********************************************************************************************************************************
   PROGRAM:   PROGRAM 7
   AUTHOR:    SYED ABDUL SUBHAN MOIN
   LOGON ID:  Z1788112
   DUE DATE:  THURSDAY, MARCH 24, 2016

   PROGRAM NAME: THE DATE CLASS - PHASE 2
              

   INPUT:     INPUT CAN BE GIVEN FROM A FILE OR STDIN              

   OUTPUT:    OUTPUT IS GIVEN ON A FILE OR STDOUT
                         
             
*********************************************************************************************************************************/






#include"Date.h"                  // this header file includes the class declarartion and friend function prototypes

extern const int DAY=1;               // the constants for the default date are set as 1st Jan 2000
extern const int YEAR=2000;
extern const string MONTH="January";


string integerToString(int);        // this function converts the integer value to string







/***********************************************************************************************************************************

   FUNCTION:   int daysInMonth() const;

   ARGUMENTS:  THIS DOESNT TAKE IN ANY ARGUMENTS

   RETURNS:   THIS FUNCTION RETURNS THE NO.OF DAYS IN SPECIFIED MONTH

   
*********************************************************************************************************************************/

int Date::daysInMonth() const
{
if(month=="January")               // if month is january, 31 days is returned
return 31;
 if(month=="February")         // if february , leap year is to be checked
{
if(isLeapYear()) return 29;      // if it is a leap year, 29 days
else
return 28;                     // if not, 28 days is returned

}
 if(month=="March")         // for march, 31 days are returned
return 31;
 if(month=="April")            // for april, 30 days are rerurned
return 30;
 if(month=="May")            // if its may, return 31 days
return 31;
 if(month=="June")           // if its june, return 30 days
return 30;
 if(month=="July")           // for july return 31 days
return 31;
 if(month=="August")        // august has 31 days
return 31;
 if(month=="September")       // if its september, return 30 days
return 30;
 if(month=="October")         // if its october, return 31 days
return 31;
 if(month=="November")      // for november, return 30 days
return 30;
 if(month=="December")      //  for december return 31 days
return 31;
else return -1;
}







/***************************************************************************************************************************

   FUNCTION:   bool isLeapyear() const;

   ARGUMENTS:  THIS FUNCTION TAKES NO ARGUMENTS

   RETURNS:    IT RETURNS TRUE IF IT IS LEAP YEAR

  
**************************************************************************************************************************/



bool Date:: isLeapYear() const                   // function is declared constant as no values are being changed
{

 if(year%4 == 0)                                 // if year is divisible by 4,100,400, then it is a leap year
    {  
	   if( year%100 == 0) 
        {
                if ( year%400 == 0)
                 return true;                      // if it is leap year, true is returned
                else
                 return false ;          // if any of the above condition fails, return false
        }
        else
         return true;
    }
      else
        return false;
} 







/***********************************************************************************************************

   FUNCTION:   bool isValidMonth() const;

   ARGUMENTS:  NO ARGUMENTS IS PASSED

   RETURNS:    A BOOLEAN VALUE IF RETURNED

  
*********************************************************************************************************/


bool Date:: isValidMonth() const           // since none of the values are changed inside the function, its declared as constant
{
int n;                         // n stores the number of days in each month
n=daysInMonth();              

if(
 (month=="January" && day<=n) ||
(month=="February" && day<=n)||
(month=="March" && day<=n)||(month=="April" && day<=n)||
(month=="May" && day<=n)||
(month=="June" && day<=n)|| (month=="July" && day<=n)||(month=="August" && day<=n)||(month=="September" && day<=n)||(month=="October" && day<=n)||(month=="November" && day<=n)||(month=="December" && day<=n)

)                               // it is checked if the month is valid or not and also if the days returned are in that month
return true;
else
{
 return false;
}
}




/*****************************************************************************************************************

   FUNCTION:  Date(const string& m,const int& d, const int& y); is parameterized constructor

   ARGUMENTS:  MONTH, DAY AND YEAR IS TAKEN AS ARGUMENTS

   RETURNS:    IT DOESNT RETURN ANYTHING


**********************************************************************************************************************/



Date::Date(const string m,const int d, const int y)
{


month=m;                      // store m in month
day=d;                         // store d in day
year=y;                         // store y in year
Month();          // Month() is called to convert first letter in upper case

}







/********************************************************************************************************************

   FUNCTION:  void setMonth(const string& m);

   ARGUMENTS:  IT TAKES IN MONTH AS PARAMETER

   RETURNS:    IT DOESNT RETURN ANYTHING


******************************************************************************************************************/

void Date::setMonth(const string& m){


month=m;                         // set month value to new value
Month();                            // convert the value of first leter to upper case letter
}






/*******************************************************************************************************************

   FUNCTION:  void setDay(const int &d);

   ARGUMENTS:  IT TAKES IN DAY AS PARAMETER

   RETURNS:    IT DOESNT RETURN ANYTHING


**************************************************************************************************************/

void Date::setDay(const int& d)
{
day=d;                 // set date to new date
}







/*********************************************************************************************************************

   FUNCTION:  void setYear(const int y);

   ARGUMENTS:  IT TAKES IN YEAR AS PARAMETER

   RETURNS:    IT DOESNT RETURN ANYTHING


*********************************************************************************************************************/


void Date::setYear(const int& y)
{
year=y;                 // set year to new year
}




/****************************************************************

   FUNCTION:  string getMonth()const ;

   ARGUMENTS:  IT TAKES NO ARGUMENTS

   RETURNS:    IT RETURNS THE MONTH VALUE


****************************************************************/


string Date::getMonth() const{
return month;              // month value is returned
}




/****************************************************************

   FUNCTION:  int getDay()const ;

   ARGUMENTS:  NO ARGUMENTS

   RETURNS:    RETURNS DATE VALUE


****************************************************************/


int Date::getDay() const {
return day;           // day is returned
}





/****************************************************************

   FUNCTION:  int getYear()const ;

   ARGUMENTS:  NO ARGUMENTS

   RETURNS:    RETURNS YEAR VALUE


****************************************************************/



int Date:: getYear() const{
return year;             // year is returned
}






/****************************************************************

   FUNCTION:  void Month() ;

   ARGUMENTS:  NO ARGUMENTS

   RETURNS:    DOESNT RETURN ANYTHING


****************************************************************/

void Date::Month()
{

month.c_str();                // convert it to c style string

month[0]=toupper(month[0]);          // convert first letter to upper case letters

for(unsigned i=1;i<month.length();i++)    
{ 
month[i]=tolower(month[i]);          // for the rest of the characters, make it lower case
}

}

/****************************************************************

   FUNCTION:  bool isValidDate()const ;

   ARGUMENTS:  NO ARGUMENTS

   RETURNS:	RETURNS TRUE IF DATE IS VALID

****************************************************************/


bool Date::isValidDate() const{
if(year==0) return false;            // year should be greater than 0
return isValidMonth();         // check if the month is valid
}






/****************************************************************

   FUNCTION:  istream & operator>>(istream &is, Date &d);

   ARGUMENTS:  TAKES STREAM AND DATE 

   RETURNS:    RETURNS VALUE TO STREAM


****************************************************************/
istream & operator>>(istream &is, Date &d)
{
char ch;
is>>d.month;      //  store first argument in month
is>>d.day;          // second in day
is>>ch;              // for the third, check if its a digit or not
if(isdigit(ch))
is.unget();           // if yes, unget
is>>d.year;           // store year
d.Month();
return is;           // return stream
}





/****************************************************************

   FUNCTION:  ostream& operator<<(ostream & os,const Date & d);

   ARGUMENTS:  TAKES STREAM AND DATE

   RETURNS:    RETURNS VALUE TO STREAM


****************************************************************/


ostream& operator<<(ostream & os,const Date & d) {

return os<<d.month<<" "<<d.day<<", "<<d.year;            // returns month, day and year to output stream

}






/****************************************************************

   FUNCTION: string toString()const;

   ARGUMENTS:  TAKES STREAM AND DATE

   RETURNS:    RETURNS STRING


****************************************************************/



string Date::toString()const {


return integerToString(day)+ "-" + month.substr(0,3) + "-" + integerToString(year);   // the date is returned in the string format.
}






/****************************************************************

   FUNCTION:  string integerToString(int n);

   ARGUMENTS:  TAKES INTEGER VALUE

   RETURNS:	RETURNS THE VALUE IN STRING.


****************************************************************/


string integerToString(int n) {
 ostringstream stream;           // string stream is used
 stream << n;
 return stream.str();        // str function is used to convert it to string
}




/**************************************************************************
  
  FUNCTION: Date() is copy constructor	
  
  ARGUMENTS: Date object d is passed 

  RETURNS: It doesnt return anything



***********************************************************************/

Date::Date(const Date& d)
{
month=d.month;  //month value is assigned
day=d.day;	//day value is assigned
year=d.year;	//year value is assigned
}






/***************************************************************
  
  FUNCTION: addDay() 

  ARGUMENTS: Constant integer n representing no of days

  RETURNS: returns the days after being added

******************************************************************/



Date& Date::addDay(const int& n)
{
	int daysInMonth=0,daysPresent=0,daysRemaining=0;   //integer daysInMonth daysPresent, daysRemaining are declared 
	
	int n2=n;    //integer n2 is declared and value of n is stored 
	while(n2>0)  //considering n is positive 
	{
		daysInMonth=this->daysInMonth();   
		daysPresent=this->getDay();
		daysRemaining=daysInMonth-daysPresent;
		if (daysRemaining==0)
		 this->setDay(1);
		
		if (n2>daysRemaining) //checks whether the days add up a new month
		{
			n2=n2-daysRemaining;
			this->setDay(1);  //setting the new date
			n2=n2-1;
			this->addMonth(1); //adding the month
			
		}
		else
		{
		
		this->setDay(this->getDay()+n2);  //adding the no of days in the same month
		n2=0;
		}
	}
	
	
	while(n2<0)
	{
		daysPresent=this->getDay();   //getting the present date
		
		if (daysPresent+n2>0)  //checking days subtracted in same month
		{
			this->setDay(daysPresent+n2);
			n2=0;
		}
		else if(daysPresent+n2<0)
		{
			this->addMonth(-1);  //getting the previous month
			this->setDay(this->daysInMonth()); //setting the last date
			n2=n2+daysPresent;
		}
		else   //if subtracting gives exactly one month
		{
			this->addMonth(-1);  //setting the previous month
			this->setDay(this->daysInMonth()); //setting the last date
			n2=0;
		}
		
		
	}


 
    
return *this;

}



/************************************************************************

  FUNCTION: addMonth()

  ARGUMENTS: a constant integer n representing 
		no of months 

************************************************************************/



Date& Date::addMonth(const int& n)
{

string month,month_new;  //strings month ,month_new is declared
month=this->getMonth();  //getting the current month 
int month_number;	//month_number is declared as integer

       if (month=="January" )         //checking the months and from January to december and assigning the values
        month_number=1;
        else if (month=="February")
                month_number=2;
        else if (month=="March")
                month_number=3;
        else if (month=="April")
                month_number=4;
        else if (month=="May")
                month_number=5;
        else if (month=="June")
                month_number=6;
        else if (month=="July")
                month_number=7;
        else if (month=="August")
                month_number=8;
        else if (month=="September")
                month_number=9;
        else if (month=="October")
                month_number=10;
        else if (month=="November")
 				month_number=11;
        else if (month=="December")
                month_number=12;
       
       
int year_added=0;   //integer year_added is declared 
int month_added;//,month1; //new integers month_added and month1 are declared

month_added = month_number+n;   // adding the no of months 

if (month_added>12)   //if the no of months are greater than 12
{
year_added=month_added/12;  // dividing by 12 gives the year to add
month_added=month_added%12; // %12 gives the months to be added
}


if (month_added<=0)  //if there are negative values 
{

	month_added=month_added*-1;  //for no of negative months to add
	year_added=month_added/12;
	year_added=year_added*-1; //for no of negative years to add
	month_added=month_added*-1;
	year_added=year_added-1;
	month_added=12+month_added;
	
}

        if (month_added==1 )     //checking the months added to know the new resulting month
        month_new="January";
        else if (month_added==2)
                month_new="February";
        else if (month_added==3)
                month_new="March";
        else if (month_added==4)
                month_new="April";
        else if (month_added==5)
                month_new="May";
        else if (month_added==6)
                month_new="June";
        else if (month_added==7)
                month_new="July";
        else if (month_added==8)
                month_new="August";
        else if (month_added==9)
                month_new="September";
        else if (month_added==10)
                month_new="October";
        else if (month_added==11)
                month_new="November";
        else if (month_added==12)
                month_new="December";



if (n%12==0)   //n%12 gives exactly 1,2,3......years to be added
{
	this->addYear(n/12);
}
else
{

this->setMonth(month_new);   //setting the new month
this->addYear(year_added);   //adding the year
}

if (this->getDay()>this->daysInMonth()&&n>0)  //if invalid addition like november 31 which is invalid...it is set to first day of the following month
{
                this->setDay(1);
                this->addMonth(1);
}
else if (this->getDay()>this->daysInMonth()&&n<0)
{
	this->setDay(1);  //not adding the month in negative case
} 

        return *this;

}





/***********************************************************************

  FUNCTION: addYear()

  ARGUMENTS: constant integer n representing no of years to be added 

  RETURNS: returns the added years 

**********************************************************************/

Date& Date::addYear(const int& n)
{
	int previous_year;   //integer previous year is declared
        if(this->getMonth()=="February"&&this->isLeapYear()&&this->getDay()==29&&n%4!=0)  //checking if the month is february and the date is 29 making it a leap year
        {
                this->setDay(1);         //setting the 1st date of the March
                this->setMonth("March");

        }
	previous_year=this->getYear();  //getting the previous year
   this->setYear(this->getYear()+n);   //setting the current year after adding 
	
	if (previous_year>0 && this->getYear()<=0) 
	this->setYear(this->getYear()-1);
	else if (previous_year<0 && this->getYear()>=0)
	this->setYear(this->getYear()+1);
	
	
        return *this;
}




/**********************************************************************

  FUNCTION: monthIndex()
 
   ARGUMENTS: no arguments are passed

  RETURNS: this returns the month index

*************************************************************************/




int Date::monthIndex() const
{
        int month_number=0;   //declaring and initializing the month number as 0
        string month; 		//declaring a string month
        month=this->getMonth();		//getting the current month

        if (month=="January" ) 			//if the month is january the month number is assigned as 0 and so on for each other months the values are 1,2,3...till 11
        month_number=0;
        else if (month=="February")
                month_number=1;
        else if (month=="March")
                month_number=2;
        else if (month=="April")
                month_number=3;
        else if (month=="May")
                month_number=4;
        else if (month=="June")
                month_number=5;
        else if (month=="July")
                month_number=6;
        else if (month=="August")
                month_number=7;
        else if (month=="September")
                month_number=8;
        else if (month=="October")
                month_number=9;
        else if (month=="November")
                month_number=10;
        else if (month=="December")
                month_number=11;

        return month_number;    //returning the month number

}






/********************************************************************

  FUNCTION:  dayIndex()

  ARGUMENTS: no arguments are passed

  RETURNS: returns the index value 

********************************************************************/


int Date::dayIndex() const
{
	int dayIndex=0,ref_mindex,this_mindex;//,ref_yindex,this_yindex; //declaring the required integers for the index of the dates
	Date ref;
	ref.setDay(1);   //setting the date as 1
	ref.setMonth("January"); //setting the month as January
	ref.setYear(1);		//setting the year as 1	
	
if(this->getYear() > 0)  //considering positive cases
	{
		if(this->getMonth() == ref.getMonth() && this->getYear() == ref.getYear() ) //getting the day index in the same month and same year
		{
			dayIndex=this->getDay()-ref.getDay()+1;
		}
		else if(this->getMonth() != ref.getMonth() && this->getYear() == ref.getYear() )  //getting the day index if the months are different but the year is same
		{
			ref_mindex=ref.monthIndex();
			this_mindex=this->monthIndex();
			
			while(ref_mindex<this_mindex) //if the reference month index is less than current month index
			{

				dayIndex=dayIndex+ref.daysInMonth(); //adding the no of  days in the month
				ref_mindex++; //incrementing the month index
			}
			
		     	dayIndex=dayIndex+this->getDay()-ref.getDay()+1; //adding the no of days left in the month
		}
		
		else  //if the months and years are different
		{

			while(ref.getYear()<this->getYear())
			{
				if (ref.isLeapYear())
				dayIndex=dayIndex+366; //adding 366 if its a leap year
				else
				dayIndex=dayIndex+365; //adding 365 if its not a leap year
				
				ref.addYear(1);
			}
			
			ref_mindex=ref.monthIndex();  //getting the month index
			this_mindex=this->monthIndex(); //getting month index of target date
			
			while(ref_mindex<this_mindex) //running the loop until the reference and target month are same
			{

				dayIndex=dayIndex+ref.daysInMonth(); //adding the day index and reference days in the month
				ref.addMonth(1); //adding the month
				ref_mindex++; //incrementing the month index
			}
			
		     	dayIndex=dayIndex+this->getDay()-ref.getDay()+1;
			
			
		}
	}
	else      //considering the year passed is negative year 
	{
		
		ref.setDay(31);  //setting the date as 31
		ref.setMonth("December"); //setting the month as December
		ref.setYear(-1);  //setting the year as -1
		
		if(this->getMonth() == ref.getMonth() && this->getYear() == ref.getYear() )   //if the months and years are same
		{
			dayIndex=-ref.getDay()+this->getDay()-1; //subtracting 1 as the case is negative years
		}
		
		else if(this->getMonth() != ref.getMonth() && this->getYear() == ref.getYear() )  //if the months are different but the years are same
		{
			
			ref_mindex=ref.monthIndex();
			this_mindex=this->monthIndex();
			while(ref_mindex>this_mindex)
			{
				dayIndex=dayIndex+ref.daysInMonth();  //adding the no of days
				ref.addMonth(-1); 
				ref.setDay(ref.daysInMonth());
				ref_mindex--; //decrementing the month index in case of negative years
			}

		     	dayIndex=-dayIndex-ref.getDay()+this->getDay()-1;
		}
		
		else   //if the months and year are different
		{

			while(ref.getYear()>this->getYear())
			{
				if (ref.isLeapYear())  //checking leap year and subtracting 366 if it is the case
				dayIndex=dayIndex-366;
				else
				dayIndex=dayIndex-365;  //else 365 is subtracted
				
				ref.addYear(-1);
			}
			
			ref_mindex=ref.monthIndex();  //getting the month index of reference month and target month
			this_mindex=this->monthIndex();
			while(ref_mindex>this_mindex)
			{
				dayIndex=dayIndex-ref.daysInMonth();
				ref.addMonth(-1);
				ref.setDay(ref.daysInMonth());
				ref_mindex--;
			}

		     	dayIndex=dayIndex-ref.getDay()+this->getDay()-1;
			
			
		}
		
		
	}
	
	return dayIndex;   //returning the dayIndex 
}






/****************************************************************************

  FUNCTION: unsigned dateDiff()
  
  ARGUMENTS: two arguments are passed which are object dates

  RETURNS: the difference between the date is returned 

*************************************************************************/




unsigned dateDiff(const Date& d1 , const Date& d3)
{
	
	int greater_date=0,lesser_date=0;  //declaring and initializing the dates as 0
	unsigned dayIndex=0;
	
		greater_date=d3.dayIndex(); //getting the dayIndex of input dates
		lesser_date=d1.dayIndex();
		

	if(d1.getYear()<0&&d3.getYear()>0)  //checking if the years are diff for dates
		dayIndex=greater_date-lesser_date-1; 
	else
		dayIndex=greater_date-lesser_date;

	return dayIndex;  //dayIndex is returned

}








/**************************************************************
 
 
  FUNCTION: Assignment operator 

 
  ARGUMENTS: constant Date object d


****************************************************************/



Date& Date::operator=(const Date &d)
{
        this->setDay(d.getDay());    //copying the day
        this->setMonth(d.getMonth()); //copying the month
        this->setYear(d.getYear());  //copying the year

        return *this;   //returning the copied date 
}


