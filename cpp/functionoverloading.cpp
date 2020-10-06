#include<iostream.h>
#include<conio.h>
void area(int,int);
void area(float);
void area(int);
void area(float,float);
void main()
{   clrscr();
    int ch=0,s,b,l;
    float h,ba,r;
    do
    {
	cout<<"Enter your choice\n";
	cout<<"1.Rectangle  \n2.Circle  \n3.Square   \n4.Triangle";
	cin>>ch;
	switch(ch)
	{
	    case 1:
	    cout<<"\nEnter Length and Breadth of Rectangle "<<endl;
	    cin>>l>>b;
	    area(l,b);
	    break;
	    case 2:
	    cout<<"\nEnter Radius of Circle "<<endl;
	    cin>>r;
	    area(r);
	    break;
	    case 3:
	    cout<<"\nEnter Side of Square "<<endl;
	    cin>>s;
	    area(s);
	    break;
	    case 4:
	    cout<<"\nEnter Base and Hieght of Triangle  "<<endl;
	    cin>>ba>>h;
	    area(ba,h);
	    break;
	    default:cout<<"\nWrong choice";
	}
    }while(ch>0&&ch<5);
getch();
}



void area(int l,int b)
{int a;
 a=l*b;
 cout<<"\nArea of Rectangle =>"<<a<<endl;
}
void area(float r)
{float a;
a=3.14*r*r;
cout<<"\nArea of Circle =>"<<a<<endl;
}

void area(int s)
{int a;
 a=s*s;
 cout<<"\nArea of Square =>"<<a<<endl;
}

void area(float b,float h)
{float a;
 a=(b*h)/2;
 cout<<"\nArea of Triangle =>"<<a<<endl;
}
