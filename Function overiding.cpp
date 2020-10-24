#include <iostream>
using namespace std;

class BaseClass 
{
public:
   void display()
   {
      cout<<"Function of Parent Class \n";
   }
};

class DerivedClass: public BaseClass
{
public:
   void display() 
   {
      cout<<"Function of Child Class \n";
   }
};

int main() 
{
   DerivedClass obj ;
   obj.display();
   cout<<"\n Method 2 \n\n";
   DerivedClass d1,d2;
   d1.display();
   d2.BaseClass::display();
    cout<<"\n\n Method 3 : Using pointer \n\n";
    BaseClass *ptr=new DerivedClass();
    ptr->display();
    
   return 0;
}
