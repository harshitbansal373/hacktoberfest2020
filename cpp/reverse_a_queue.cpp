/*  Reversing a queue is easy.
    - Dequeue all elements from queue and push 
      them onto stack.
    - Now pop all elements from stack and 
      enqueue them in a queue.
*/

#include<bits/stdc++.h>
using namespace std;

// Auxiliary function to print elements in queue
void print (queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

// Function to reverse the queue
void reverseItr (queue<int> &q) {
    stack<int> s;
    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}

void reverseRec (queue<int> &q) {
    if (q.empty())  return;
    int data = q.front();
    q.pop();
    reverseRec(q);
    q.push(data);
}

/* --------------- MAIN DRIVER CODE ------------ */
int main() 
{ 
    queue<int> Queue; 
    Queue.push(56); 
    Queue.push(27); 
    Queue.push(30); 
    Queue.push(45); 
    Queue.push(85); 
    Queue.push(92); 
    Queue.push(58); 
    Queue.push(80); 
    Queue.push(90); 
    Queue.push(100); 

    reverseRec(Queue); 
    print(Queue);

    reverseItr(Queue);
    print(Queue);

    return 0;
} 