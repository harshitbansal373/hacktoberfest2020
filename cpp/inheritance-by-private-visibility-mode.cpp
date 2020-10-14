#include<iostream>
using namespace std;

class B
{
    int a;
public:
    int b;
    void get_ab()
    {
        cout<<"Enter values of a and b : ";
        cin>>a>>b;
    }
    int get_a()
    {
        return a;
    }
    void show_a()
    {
        cout<<"a = "<<a<<"\n";
    }
};

class D : private B
{
    int c;
public:
    void mul()
    {
        get_ab();
        c = b * get_a();
    }
    void display()
    {
        show_a();
        cout<<"b = "<<b<<"\n"
            <<"c = "<<c<<"\n";
    }
};

int main()
{
    D d;
    d.mul();
    d.display();
    d.mul();
    d.display();
    return 0;
}
