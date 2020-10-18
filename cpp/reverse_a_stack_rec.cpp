// Video Link: https://www.youtube.com/watch?v=dQsZP8UvHVk
// Time Complexity: O(n^2) and Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

// Auxiliary Function to print a stack
void printStack (stack<int> s) {
    if (s.empty())
        return;
    int x = s.top();
    s.pop();
    printStack(s);
    cout << x << " ";
    s.push(x);
}

// Utility function for our main logic
/* NOTE: Here passing stack by reference is important.
   Work-out with sample problem to understand why. */
void insertAtBottom (stack<int> &s, int element) {
    if (s.empty()) {
        s.push(element);
        return;
    }
    int x = s.top();
    s.pop();
    insertAtBottom(s, element);
    s.push(x);
}

// Main Logic of Code
void reverse (stack<int> &s) {
    if (s.empty())  return;
    int temp = s.top();
    s.pop();
    reverse(s);
    insertAtBottom(s, temp);
}

/* ------------------ MAIN DRIVER CODE ----------------- */
int main() {
    stack<int> st;
    
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout << "Original Stack:\n";
    printStack(st);
    cout << endl;

    reverse(st);

    cout << "Reversed Stack:\n";
    printStack(st);
    cout << endl;

    return 0;
}