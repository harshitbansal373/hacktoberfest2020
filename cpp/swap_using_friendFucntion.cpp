#include<iostream.h>
#include<conio.h>
class xyz;
class abc
{int x;
 public:
  void getdata()
   {cout<<"\nEnter the first number =>";
  cin>>x;
 }
 void display()
 {cout<<"\nNumbers =>"<<x;
 }
 friend void swap(abc &o1,xyz &o2);
};
class xyz
    {int y;
        public:
      void getdata()
       {cout<<"\nEnter the numbers =>";
          cin>>y;
       }
   void display()
     {cout<<"\nNumbers =>"<<y;
         }
     friend void swap(abc &o1,xyz &o2);
    };
 void swap(abc &o1,xyz &o2)
  {int temp;
   temp=o1.x;
   o1.x=o2.y;
   o2.y=temp;
    }
void main()
{clrscr();
abc o1;
 xyz o2;
    o1.getdata();
    o2.getdata();
       cout<<"\nNumbers before swap are =>";
    o1.display();
    o2.display();
    swap(o1,o2);
       cout<<"\nNumbers after swap are =>";
    o1.display();
    o2.display();
 getch();
}
