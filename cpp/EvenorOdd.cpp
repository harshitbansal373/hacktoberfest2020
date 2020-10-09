#include<iostream>
using namespace std;
int main()
{
 int number,remainder;
 cout<<"enter a number";
 cin>>number;
 remainder=number%2;
 if(remainder==0)
 {
     cout<<number<<"is an even number:"<<endl;
     
 }
else
{
    cout<<number<<"ia an odd number:"<<endl;
    
}
return 0;
}
