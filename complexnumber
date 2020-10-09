//Program to get 2 complex numbers from the user and perform addition
#include<iostream.h>
#include<conio.h>
class complex
{ float x,y;
  public:
  void getdata()
  {cout<<"\nEnter the value of Real part";
   cin>>x;
   cout<<"\nEnter the value of Imaginery part";
   cin>>y;
  }
  void showdata()
  {cout<<"\n"<<x<<"+ i"<<y;
  }
  friend complex sum(complex,complex);
  friend complex dif(complex,complex);
};
complex sum(complex c1,complex c2)
{ complex c;
  c.x=c1.x+c2.x;
  c.y=c1.y+c2.y;
  return c;
}
void main()
{
clrscr();
complex c1,c2,c;
 cout<<"\nFor First value";
 c1.getdata();
 cout<<"\nFor Second value";
 c2.getdata();
 cout<<"\nFirst value";
 c1.showdata();


 cout<<"\nSecond value";
 c2.showdata();
 c=sum(c1,c2);
cout<<"\nComplex number addition ->";
 c.showdata();
 
getch();
}

