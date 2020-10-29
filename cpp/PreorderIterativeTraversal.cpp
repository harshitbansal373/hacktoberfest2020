#include <bits/stdc++.h>
                            //Iterative Preorder Traversal in C++
using namespace std;

//A binary tree node
struct node {
	int data;
	struct node* left;
	struct node* right;
};


struct node* newNode(int data)
{
	struct node* node = new struct node;
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

// An iterative process to print preorder traversal of Binary tree
void iterativePreorder(node* root)
{
	// Base Case
	if (root == NULL)
		return;

	// Creating an empty stack and pushing root to it
	stack<node*> nodeStack;
	nodeStack.push(root);


	while (nodeStack.empty() == false) {
		// Pop the top item from stack and print it
		struct node* node = nodeStack.top();
		printf("%d ", node->data);
		nodeStack.pop();

		// Push right and left children of the popped node to stack
		if (node->right)
			nodeStack.push(node->right);
		if (node->left)
			nodeStack.push(node->left);
	}
}

// Driver Code
int main()
{
	/* Constructed binary tree is
			15
		    / \
		   8   2
	       / \ /
	      13 5 6
*/
	struct node* root = newNode(15);
	root->left = newNode(8);
	root->right = newNode(2);
	root->left->left = newNode(13);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	iterativePreorder(root);
	return 0;
}
