#include<iostream>
using namespace std;

class dll
{
struct node
{
 int data;
 node *next;
 node *prev;

}*p;
public: dll()
{
    p=NULL;
}
void create(int num)
{
    node *temp,*r;
    if(p==NULL)
    {
        temp = new node;
        temp->prev = NULL;
        temp->next = NULL;
        temp->data = num;
        p = temp;
    }
    else
    {
        r = new node;
        r->prev = temp;
        r->next = NULL;
        r->data = num;
        temp->next = r;
        temp = temp->next;
    }
}
    void display()
    {
        node *temp=p;
        while(p!=NULL)
        {
            cout<<temp->data<<endl;
            temp = temp->next;
        }
    }
};
int main()
{
    dll o;
    o.create(10);
    o.create(20);
    o.create(30);
    o.display();
    return 0;
}