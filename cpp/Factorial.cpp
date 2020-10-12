#include<iostream.h>
#include<conio.h>

void main()
{
int i, no, fact=1;
clrscr();
cout<<"Enter the any no. : ";
cin>>no;
if(no==0)
{
  fact=1; //since factorial of 0 is 1.
}
else
{
for
(i=1;i<=no;i++)
{
fact=fact*i;
}  
}
cout<<"Factorial: "<<fact;
getch();
}
