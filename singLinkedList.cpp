#include<iostream>
using namespace std;

class sll
{
    struct node
    {
        int data;
        node *next;
    }*p;
    public: sll()
    {
        p = NULL;
    }
    void create(int num)
    {
        node *temp,*r;
        if(p==NULL)
        {
            temp = new node;
            temp->data = num;
            temp->next = NULL;
            p = temp;
        }
        else
        {
            r = new node;
            r->data = num;
            r->next = NULL;
            temp->next = r;
            temp=temp->next;
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
    sll o;
    o.create(10);
    o.create(20);
    o.create(30);
    o.display();
    return 0;
}