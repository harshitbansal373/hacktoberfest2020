#include<stdio.h>
#include<conio.h>
#include<math.h>
int board[20],count;
void queen(int row,int n);
void main()
{
 int n,i,j;
 clrscr();
 printf("    N Queens Problem Using Backtracking  ");
 printf("\nEnter the no of Queens:");
 scanf("%d",&n);
 queen(1,n);
 getch();
}
void print(int n)
{
 int i,j;
 printf("\n\nSolution %d:\n\n",++count);
 for(i=1;i<=n;++i)
 {
  printf("\t%d",i);
 }
 for(i=1;i<=n;++i)
 {
  printf("\n\n%d",i);
  for(j=1;j<=n;++j)
  {
   if(board[i]==j)
   {
    printf("\tQ");
   }
   else
   {
    printf("\n-");
   }
  }
 }
}
int place(int row,int column)
{
 int i;
 for(i=1;i<=row-1;++i)
 {
  if(board[i]==column)
  {
   return 0;
  }
  else
  {
   if(abs(board[i]-column)==abs(i-row))
   {
    return 0;
   }
  }
 }
 return 1;
}
void queen(int row,int n)
{
 int column;
 for(column=1;column<=n;++column)
 {
  if(place(row,column))
  {
   board[row]=column;
   if(row==n)
   {
    print(n);
   }
   else
   {
    queen(row+1,n);
   }
  }
 }
}