

/****************************************************************
   PROGRAM:   N QUEENS PUZZLE
   
   AUTHOR:    SYED ABDUL SUBHAN MOIN
   
   DUE DATE:  Monday, 2nd May, 2016

   FUNCTION:  Display the solution of n queens problem if it exists

             
****************************************************************/
#include"prog11.h" //including the header file

using namespace std;

bool flag=false;



int main() 		//start of main routine
{
unsigned n;                // n stores the size of the chessboard for which n queens solution is to be computed


for(n=1;n<9;n++)//for the board size from 1 to 8
          
{
cout<<"Board Size = "<<n<<endl;
solveNQueens(n);         // This is function call to solve the problem. the size of the chessboard is given as an argument
cout<<endl<<endl;
}

return 0;
} //end of main routine





/****************************************************************

   FUNCTION:   void initBoard(vector<vector<bool>> & board, unsigned n  );

   ARGUMENTS:  A vector board and n, the size of the bosrd

   RETURNS:    Nothing

  ****************************************************************/
void initBoard(vector<vector<bool>> & board, unsigned n  )
{
unsigned i,j;  //using usigned integers for loop
for( i=0;i<n;i++)
{
for( j=0;j<n;j++)             
{
board[i][j]=false;  //making all the positions false
}
}
srand(time(NULL));   // srand is assigned to time(NULL) to get different values for the board
}







/****************************************************************

   FUNCTION:   void printBoard(const vector<vector<bool>> & board,const unsigned n);
   ARGUMENTS:  A vector board and size of the board

   RETURNS:    Nothing

   NOTES:     Displays the solution on screen
****************************************************************/

void printBoard(const vector<vector<bool>> & board,const unsigned n)
{

unsigned size=n;  //storing the size of the board


int rowSize=0;     //rowSize and columnSize are declared for the board
int columnSize=0;

 for(unsigned l=1;l<=size;l++)
        {

        cout<<" ";
        for(unsigned i=1;i<=5*size+(size-1);i++)   // this prints out the board pattern
        {
                cout<<"-";  //prints ---------
        }
       cout<<"\n";

        for (int unsigned k=1;k<=3;k++)
        {
      
        for(unsigned j=0;j<=5*size+size;j++)
        {
           

            if((k==2) && ((j+3)%6==0)) // checking possible locations of mines
                {

                 if(board[rowSize][columnSize]) //finding the location for Q
		{
			cout<< "Q"; //prints the Q else not 
		}
		else
		{
			cout<<" ";
		}                                           
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
  cout<<" ";   //prints out the board pattern
        for(unsigned i=1;i<=5*size+(size-1);i++)
        {
                cout<<"-";
        }
}




/****************************************************************

   FUNCTION:   void solveNQueens ( const unsigned& n );

   ARGUMENTS:  The size n is sent as argument

   RETURNS:    Nothing

 ****************************************************************/

void solveNQueens ( const unsigned& n )
{
	vector <vector<bool>> board(n,vector <bool>(n));  // vector for the chess board is first created. it is n*n vector
	initBoard(board,n);           // initial assignments to the vector are made by calling this function
	  if (!solveNqueensUtil(board, 0))    // solveNqueensutil starts from the first col. if no solution exists, display the following
    {
       cout<<"Solution does not exist"<<endl;
       return;                     // return here is used to come out of the function
    }
   	printBoard(board,n);        // if  a solution exists, the entire board is displayed
    
}




/****************************************************************

   FUNCTION:   bool solveNqueensUtil(vector<vector<bool>> & board, const unsigned& col);

   ARGUMENTS:  board and column number

   RETURNS:    returns a boolean value

****************************************************************/


bool solveNqueensUtil(vector<vector<bool>> & board, const unsigned& col)
{
int row=rand()%board.size();
if (col >= board.size()) {               // if the col exceeds, size of the board, all columns have been checked, hence return true
        return true;}
else{                                                   
    for (unsigned i = row; i < board.size(); i++)          // Check from random row generated till the end of the board
    {
        if ( isSafe(board, i, col) )                          // if the place is safe to place the queen
        {
            board[i][col] = true;                       // place the queen on the board       
            if (solveNqueensUtil(board, col + 1) ){     // go to the next column   
                return true;}                                
            board[i][col] = false;                      // or remove the queen from the place
        }
    }


  for (int i = 0; i < row; i++)                   // this loop checks from start of the row till the random number generated
    {
        if ( isSafe(board, i, col) )              // if the position is safe, place the queen
        {
            board[i][col] = true;                                
            if (solveNqueensUtil(board, col + 1) ){   // go to the next column
                return true;}
            board[i][col] = false;             // or remove the queen
        }
    }
}
   
	return false;                        // return false if no such positions are found

}





/****************************************************************

   FUNCTION:   bool isSafe(const vector<vector<bool>>& board, const int & row, const int& col)

   ARGUMENTS:  vextor, row and column values

   RETURNS:    boolean result which specifies if a queen can be placed at that position

****************************************************************/

bool isSafe(const vector<vector<bool>>& board, const int & row, const int& col)
{
	
int i, j, size=board.size(); 
    for (i = 0; i < col; i++)         // this loop checks if a queen is present in any of the rows 
    {
        if (board[row][i])
            return false;              // if a queen is present, return false
    }

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)     // this loop is used to check the lower diagonal 
    {
        if (board[i][j])             // if a queen is present, return false
            return false;
    }

    for (i = row, j = col; j >= 0 && i < size; i++, j--)        // this loop checks the other diagonal
    {
        if (board[i][j])                      // if queen is present, return false
            return false;
    }
 
    return true;                     // or it is safe to place the queen in the position row and columnn

}
	
		
		
	
