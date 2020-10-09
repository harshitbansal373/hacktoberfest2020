// Video Link: https://www.youtube.com/watch?v=bD9oYzwfZ1w

/* PROBLEM: Give an algorithm for finding the sum of all elements in a binary tree. */

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node (int data) {
        this->data = data;
        left = right = NULL;
    }
};

// Main Logic
int addRecursive (Node* root) {
    if (root == NULL)
        return 0;
    return (root->data + addRecursive(root->left) + addRecursive(root->right));
}

int addIterative (Node* root) {
    int total = 0;
    if (root == NULL)   return 0;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        total += current->data;
        q.pop();

        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
    return total;
}

/* ---------------- MAIN DRIVER CODE ---------------- */
int main() 
{ 
    struct Node* root = new Node(10); 
    root->left = new Node(11); 
    root->left->left = new Node(7); 
    root->left->right = new Node(12); 
    root->right = new Node(9); 
    root->right->left = new Node(15); 
    root->right->right = new Node(8); 
  
    cout << addRecursive(root) << endl;
    cout << addIterative(root) << endl;
    return 0; 
} 

/* NOTE:
    If we are supposed to count the number of nodes in a given BT,
    instead of adding node->data in total, we would have added '1'.
*/