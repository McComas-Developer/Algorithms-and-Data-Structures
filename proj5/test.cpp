#include<iostream>
#include<conio.h>
using namespace std;
int main()
{int a[3][3],i,j;
 float determinant=0;
 //clrscr();
 cout<<"Find Inverse Of Matrix by-Tarun Rawat\n";
 cout<<"Enter elements of 3x3 matrix:\n";
 for(i=0;i<3;i++)
 {
  for(j=0;j<3;j++)
  {
   cin>>a[i][j];
  }
 }
 cout<<"\nThe entered matrix is:\n";
 for(i=0;i<3;i++)
 {
  for(j=0;j<3;j++)
  {
   cout<<a[i][j]<<"  ";
  }
  cout<<"\n";
 }
 for(i=0;i<3;i++)
 {
  determinant = determinant + (a[0][i]*(a[1][(i+1)%3]*
  a[2][(i+2)%3] - a[1][(i+2)%3]*a[2][(i+1)%3]));
 }
 if(determinant==0)
 {
  cout<<"Inverse does not exist (Determinant=0).\n";
 }
 else
 {
  cout<<"\nInverse of matrix is: \n";
 }
 for(i=0;i<3;i++)
 {
  for(j=0;j<3;j++)
  {
   cout<<((a[(i+1)%3][(j+1)%3] *a[(i+2)%3][(j+2)%3]) - (a[(i+1)%3][(j+2)%3]*a[(i+2)%3][(j+1)%3]))/ determinant<<"\t";
  }
  cout<<"\n";
  }
return 0;
 //getch();
}