#include<bits/stdc++.h>
using namespace std;
bool check(int matrix[9][9],int row,int col)
{
   for(int i=0;i<9;i++)
   {
     if(i!=col&&matrix[row][i]==matrix[row][col])return false;
     if(i!=row&&matrix[i][col]==matrix[row][col])return false;
   }
   int box_row=row/3;
   int box_col=col/3;
   for(int i=0;i<3;i++)
   {
     for(int j=0;j<3;j++)
     {
       if((3*box_row+i!=row||3*box_col+j!=col)&&matrix[3*box_row+i][3*box_col+j]==matrix[row][col])return false;
     }
   }
   return true;


}
bool solve(int matrix[9][9])
{
  int row=-1,col=-1;

  for(int i=0;i<9;i++)
  {
    for(int j=0;j<9;j++)
    {
      if(matrix[i][j]==0)
      {
        row=i;
        col=j;
      }
    }
  }
  if(row==-1&&col==-1)
  {
    return true;
  }
  else
  {
    for(int i=1;i<=9;i++)
    {
      matrix[row][col]=i;
      if(check(matrix,row,col)&&solve(matrix))
      return true;


    }
    matrix[row][col]=0;
    return false;
  }

}
void print(int matrix[9][9])
{
  for(int i=0;i<9;i++)
  {
    for(int j=0;j<9;j++)
    {
      cout<<matrix[i][j]<<" ";
    }
    cout<<endl;
  }
}
int main()
{
  int matrix[9][9]={ {3, 0, 6, 5, 0, 8, 4, 0, 0},
         {5, 2, 0, 0, 0, 0, 0, 0, 0},
         {0, 8, 7, 0, 0, 0, 0, 3, 1},
         {0, 0, 3, 0, 1, 0, 0, 8, 0},
         {9, 0, 0, 8, 6, 3, 0, 0, 5},
         {0, 5, 0, 0, 9, 0, 6, 0, 0},
         {1, 3, 0, 0, 0, 0, 2, 5, 0},
         {0, 0, 0, 0, 0, 0, 0, 7, 4},
         {0, 0, 5, 2, 0, 6, 3, 0, 0} };
         cout<<"Given Soduku to solve\n\n";
         print(matrix);
         cout<<endl<<endl;
  solve(matrix);
  cout<<"Solution to Soduku \n\n";
  print(matrix);
}
