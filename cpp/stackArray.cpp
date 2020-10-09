# include<iostream>
using namespace std;
class Stack{
    public:
    int *arr;
    int top;
    int array_size;

};

int isEmpty(Stack *S){
    if(S->top == -1){ 
        return 1;
    }
    else{
        return 0;
    }

}

int isFull(Stack *S){
    if(S->top>=S->array_size-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(Stack*S){
    int val;
     if(!isFull(S)){
    cout<<"Enter the value : ";
    cin>>val;
       S->arr[++S->top] = val;
       cout<<val<<" is pushed in the stack";
    }
    else{
        cout<<"Overflow!";

    }
}

void pop(Stack*S){
    int val;
     if(!isEmpty(S)){
       val = S->arr[S->top--];
       cout<<val<<" is popped from the stack";
    }
    else{
        cout<<"Underflow!";

    }
}

void peek(Stack*S){
    if(!isEmpty(S)){
        cout<<S->arr[S->top]<<" is the topmost element of the stack";
    }
    else{
        cout<<"Stack is empty";
    }
}

main(){
    int n;
     Stack *S=NULL;
    S = new Stack();
    cout<<"Enter the size of the Stack array: ";
    cin>>S->array_size;
    S->arr = new int(S->array_size);
    S->top = -1;
    l:
    cout<<"\nEnter 1 for push.";
    cout<<"\nEnter 2 for pop.";
    cout<<"\nEnter 3 for peek.\n";
    cin>>n;
    switch (n)
    {
    case 1:
        push(S);
        break;
    case 2:
        pop(S);
        break;
    case 3:
        peek(S);
        break;
    
    default:
    cout<<"Wrong Choice";
        break;
    } 
    cout<<"\nDo you want to perform more operations Y/N \n";
    char ch;
    cin>>ch;
    if(ch=='y'){
   goto l;
  }
    if(ch=='n'){
   cout<<"\nProgram is ended";
  }
    
}
