#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
}; 

class Linkedlist
{
    public:
        Node *head;
        Linkedlist()
        {
            this->head = NULL;
        }
};
Node* create(int data)
{
    Node* node = new Node;
    node->data = data;
    node->next = NULL;
    return(node); 
}
Node* insertatend(Node* head, int data)
{
    Node *temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    Node* node = create(data);
    temp->next = node;
    return(head);
}

void printlist(Node* head)
{
    Node *temp = head;
    while(temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}
void freelist(Node* node) 
    {
    while (node) {
        Node* temp = node;
        node = node->next;
        free(temp);
    }
}
int main()
{
    int n,i,data;
    Linkedlist* llist = new Linkedlist();
    cin >> n;
    for(i = 0;i < n;i++)
    {
        cin >> data;
        Node *listhead = insertatend(llist->head, data);
        llist->head = listhead;
    }
    printlist(llist->head);
    freelist(llist->head);
    return(0);
}

