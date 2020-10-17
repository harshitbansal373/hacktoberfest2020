#include<iostream>
using namespace std;

//class template 
template <class T1,class T2>
class test
{
  private:
    T1 a;
    T2 b; 
  public:
    test(T1 x,T2 y){
      a=x;
      b=y;
    }
  void show(){
    cout<<a<<" "<<b<<"\n";
  }

};
 int main(){
   test <float,int> ob1(10.50,20);
   test <int,char> ob2(10,'A');
    ob1.show();
    ob2.show();
  return 0;
 }
