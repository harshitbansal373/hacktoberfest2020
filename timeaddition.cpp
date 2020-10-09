#include<iostream.h>
#include<conio.h>
class time
{int hrs,min,sec;
 public:
 void gettime(int h,int m,int s)
 {
 cout<<"Enter Hour = > ";
 cin>>h;
  cout<<"Enter Minutes = > ";
  cin>>m;
  cout<<"Enter Seconds = > ";
  cin>>s;
  cout<<"\n";

 hrs=h;
  min=m;
  sec=s;
 }
 void showtime()
 {cout<<"\nHours =>"<<hrs;
  cout<<"\nMinutes =>"<<min;
  cout<<"\nSeconds =>"<<sec;
 }
 void sum(time,time);
};
void time::sum(time t1,time t2)
{ int a;
sec=t1.sec+t2.sec;
a=sec;
 if(sec>60)
  {sec=sec%60;
  }
 a=a/60;
 min=t1.min+t2.min+a;
 hrs=min/60;
 min=min%60;
 hrs=hrs+t1.hrs+t2.hrs;
}
void main()
{clrscr();
time t1,t2,t3;
t1.gettime(3,40,45);
t2.gettime(2,45,40);

cout<<"Time after addition";
t3.sum(t1,t2);
t3.showtime();
getch();
}
