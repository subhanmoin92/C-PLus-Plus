
/********************************************************************************************

PROGRAM : GAME OF MINESWEEPER

AUTHOR:   SYED ABDUL SUBHAN MOIN

LOGON ID: Z1788112

DUE DATE: FRIDAY, FEBRUARY 26, 2016

FUNCTION: THIS PROGRAM DEVELOPS A GAME OF MINESWEEPER

INPUT:   A PAIR OF SIZE AND MINEPROBABILITY 

OUTPUT:  A GENERATED MINESWEEPER GAME



********************************************************************************************/




#include "prog5.h" // this header file contains other header functions and function prototypes for this program

using namespace std;



int main()
{

	int size;  			   // integer size is declared to store the size of matrix
	double mineProb; 		// double mineProb is declared to store the probability of the mines 
	while(cin>>size>>mineProb) 	// using a while loop for stdin for the size and mineprob
	{cout<<endl;
//	cout<<"Enter the size "<<endl; 

//	cout<<"Enter the Mine Probability "<<endl;

	
	vector<bool> s1(size, false);  	//creating a vector of boolean datatype initializing the value of size as false  
	vector< vector<bool> > mines(size,s1); // creating a two dimensional vector  
	
	vector<unsigned> s2(size, 0);  //creating a vecotr of boolean datatype initializing the value of size as 0
	vector< vector<unsigned> > counts(size,s2); //creating a two dimensional vector of boolean datatype 
	
	buildMineField(mines,mineProb); //calling the function buildMineField with mines and mineProb as the arguments 
	fixCounts(mines,counts);   	// calling the function fixCounts with mines and counts as the arguments
	cout<<"Mine Locations: size = "<<mines.size()<<" * "<<mines.size()<<", prob of mine = "<<mineProb<<endl;
	displayMineLocations(mines);  	//calling the function displayMineLocations with mines as the argument
	cout<<"\n\n";
	cout<<"Mine Counts:"<<endl;  
	displayMineCounts(counts); 	//calling the function displayMineCounts with counts as the argument

	
}}







/****************************************************************

   FUNCTION:   THIS FUNCTION DISPLAYS THE MINE FIELD 

   ARGUMENTS:  A CONSTANT VECTOR IS PASSED AS THE ARGUMENT 

   RETURNS:    THIS FUNCTION DISPLAYS THE TABLE FOR MINE FIELD

****************************************************************/


void displayMineLocations(const vector<vector<bool> >&mines)
{
	int size=mines.size(); 		//creating an integer size to store the size of the mine
	
	int rowSize=0; 			//declaring integer rowSize as 0
	int columnSize=0;		//declaring integer columnsize as 0
	
	
	for(int l=1;l<=size;l++)
	{
	
	cout<<" ";
	for(int i=1;i<=5*size+(size-1);i++) //this prints out the matrix pattern
	{
		cout<<"-";
	}
	cout<<"\n";
	
	for (int unsigned k=1;k<=3;k++)
	{
	
	for(int j=0;j<=5*size+size;j++)
	{
		if((k==2)&&((j+3)%6==0)) //checking the possible location of the mine
		{
		 if (mines[rowSize][columnSize]==1) //condition to check the mine location
		cout<<"X";     //this displays X for every mine location in the vector mines
		else
		cout<<" ";     //this displays no mine
		columnSize++;
		}
		else
		{
		
		if((j==0)||(j%6==0))  //this prints out the pattern for the matrix
		cout<<"|";
		else
		cout<<" ";
		}
	}
	cout<<"\n";
	}
	rowSize++;
	columnSize=0;
	}
	cout<<" ";
	for(int i=1;i<=5*size+(size-1);i++) // this prints out the matrix pattern
	{
		cout<<"-";
	}
	
	
}








/****************************************************************

   FUNCTION: THIS FUNCTION DISPLAYS THE TABLE FOR MINE COUNTS   

   ARGUMENTS:  CONST TWO DIMENSIONAL VECTOR COUNTS

   RETURNS:    THIS RETURNS THE TABLE FOR MINE COUNTS ON STDOUT

****************************************************************/



void displayMineCounts(const vector< vector<unsigned> >&counts)
{
	int size=counts.size();   // integer size is declared to store the size of the vector counts
	
	int rowSize=0;   
	int columnSize=0;
	
	
	for(int l=1;l<=size;l++) 
	{
	
	cout<<" ";
	for(int i=1;i<=5*size+(size-1);i++)   // this prints out the matrix pattern
	{
		cout<<"-";  //prints ---------
	}
	cout<<"\n";
	
	for (int unsigned k=1;k<=3;k++)
	{
	
	for(int j=0;j<=5*size+size;j++)
	{
		if((k==2) && ((j+3)%6==0)) // checking possible locations of mines
		{
		 cout<<counts[rowSize][columnSize];
		 columnSize++;  
		}
		else
		{
		
		if((j==0)||(j%6==0))    // printing a pattern for the cell
		cout<<"|";  
		else
		cout<<" ";
		}
	}
	cout<<"\n";
	}
	rowSize++;
	columnSize=0;
	}
	cout<<" ";   //prints out the matrix pattern
	for(int i=1;i<=5*size+(size-1);i++)
	{
		cout<<"-";
	}
	
	
}








/****************************************************************

   FUNCTION:   THIS FUNCTION BUILDS A MINE FIELD
   
   ARGUMENTS:  A TWO DIMENSTIONAL VECTOR MINES AND MINE PROBABILITY 

   RETURNS:    THIS FUNCTION DOESNT RETURN ANYTHING   

****************************************************************/

void buildMineField(vector< vector<bool> >&mines,const double& mineProb)
{
	double rnd;  //creating a double rnd 
	srand(1);    //calling the function srand(seed) with seed value 1


	for(int unsigned i=0;i<mines.size(); i++) {
      for (int unsigned j=0;j<mines[i].size(); j++)
      {
      	rnd=rand()/(double(RAND_MAX)+1);  //this function generates a random value
      	
      	if (rnd<mineProb) 	//condition to check location in vector containing mine
			mines[i][j]=true;      	//if mine is present it is assigned true
	  }

   }
}






/*************************************************************************************************************************

   FUNCTION:   THIS CHECKS THE BOOLEAN VALUE FOR ADJACENT CELLS  

   ARGUMENTS:  TWO ARGUMENTS OF 2D VECTORS MINES AND COUNTS 

   RETURNS:    THIS FUNCTION DOESNT RETURN ANYTHING

*************************************************************************************************************************/


void fixCounts(const vector< vector<bool> >&mines,vector< vector<unsigned> >&counts)
{

	int cellCount;   //integer cellCount is declared
	int mSize=counts.size();  //integer mSize is declared to store the size of the vector counts
	
	for(int i=0;i<mSize; i++) {
		
      for (int j=0;j<mSize; j++)
      {
      	cellCount=0;
      	
      	 if (mines[i][j]==true)  //checking if a mine is present
      	 {
      	 	cellCount++;   //if a mine is present then cellCount is incremented
      	 }
      	
      	
      	if ((i-1>=0)&&(i-1<mSize)&&(j-1>=0)&&(j-1<mSize))  // checking possible mine locations 
      	{
      		if (mines[i-1][j-1]==true)  //if a mine is present
      		cellCount++;
		  }	  
		
		if ((i-1>=0)&&(i-1<mSize))
      	{
      		if (mines[i-1][j]==true)
      		cellCount++;			//incrementing cellCount when a mine is encountered
		  }	  
		  
		  if ((i-1>=0)&&(i-1<mSize)&&(j+1>=0)&&(j+1<mSize))
      	{
      		if (mines[i-1][j+1]==true)
      		cellCount++;
		  }	  
		  
		  if ((j-1>=0)&&(j-1<mSize))
      	{
      		if (mines[i][j-1]==true)
      		cellCount++;
		  }	  

		  if ((j+1>=0)&&(j+1<mSize))
      	{
      		if (mines[i][j+1]==true)
      		{
			  
      		cellCount++;
 
      	}
		  }	  
		 
		  if ((i+1>=0)&&(i+1<mSize)&&(j-1>=0)&&(j-1<mSize))    //checking the adjacent 8 cells for a mine
      	{
      		if (mines[i+1][j-1]==true)
      		cellCount++;
		  }	  
		  
		  if ((i+1>=0)&&(i+1<mSize))
      	{
      		if (mines[i+1][j]==true)
      		cellCount++;
		  }	  
		  
		  if ((i+1>=0)&&(i+1<mSize)&&(j+1>=0)&&(j+1<mSize))
      	{
      		if (mines[i+1][j+1]==true)
      		cellCount++;
		  }	  
		  
		 
		counts[i][j]=cellCount;	
	  }

   }

	
}

