//Problem Description : https://practice.geeksforgeeks.org/problems/solve-the-sudoku/0
#include <iostream>
using namespace std;

#define n 9

int sudoku[n][n];

void printSolution()
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        cout<<sudoku[i][j]<<" ";
}

bool findNextEmpty(int& row,int& column)
{
    for(row=0;row<n;row++)
        for(column=0;column<n;column++)
           if(sudoku[row][column] == 0)
              return true;
    return false;
}

bool canFillWithValue(int row,int column,int value)
{
    //Check if that value is in the same row
    for(int i=0;i<n;i++)
       if(sudoku[row][i] == value)
        return false;
    //Check if that value is in the same column
    for(int i=0;i<n;i++)
        if(sudoku[i][column] == value)
          return false;
    //Check if that value is in 3*3 matrix
    int start_row = row-row%3,start_column=column-column%3;
    for(int i=start_row;i<start_row+3;i++)
        for(int j=start_column;j<start_column+3;j++)
            if(sudoku[i][j] == value)
               return false;
    return true;
}

bool solveSudoku()
{
     int row,column;
     if(!findNextEmpty(row,column))
     {
         printSolution();
         return true;
     }
     for(int i=1;i<=9;i++)
     {
         if(canFillWithValue(row,column,i))
         {
             sudoku[row][column] = i;

             if(solveSudoku())
                return true;

             sudoku[row][column] = 0;
         }
     }
     return false;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>sudoku[i][j];
        solveSudoku();
        cout<<endl;
    }
}
