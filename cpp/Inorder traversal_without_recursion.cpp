#include<iostream>
#include<stack>
using namespace std;

class Node
{
    public:
    int data;
    Node(int data)
    {
        this->data=data;
        left=right=NULL;
    }
    Node *right,*left;

};

int  main()
{
    Node *root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);

    stack<Node *>stk;
    Node *curr=root;
    while(curr!=NULL || stk.empty()==false)
    {
        while(curr!=NULL)
        {
        stk.push(curr);
        curr=curr->left;  
        } 
        curr=stk.top();
        stk.pop();
        cout<<curr->data<<" ";
        curr=curr->right;
    }
    return 0;
}
