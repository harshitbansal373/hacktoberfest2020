// Source - https://gist.github.com/mycodeschool
/* Binary Tree Traversal - Preorder, Inorder, Postorder */
#include<stdio.h>
#include<stdlib.h>

struct Node {
	char data;
	struct Node *left;
	struct Node *right;
};

//Function to visit nodes in Preorder
void Preorder(struct Node *root) {
	// base condition for recursion
	// if tree/sub-tree is empty, return and exit
	if(root == NULL) return;

	printf("%c ",root->data); // Print data
	Preorder(root->left);     // Visit left subtree
	Preorder(root->right);    // Visit right subtree
}

//Function to visit nodes in Inorder
void Inorder(struct Node *root) {
	if(root == NULL) return;

	Inorder(root->left);       //Visit left subtree
	printf("%c ",root->data);  //Print data
	Inorder(root->right);      // Visit right subtree
}

//Function to visit nodes in Postorder
void Postorder(struct Node *root) {
	if(root == NULL) return;

	Postorder(root->left);    // Visit left subtree
	Postorder(root->right);   // Visit right subtree
	printf("%c ",root->data); // Print data
}

// Function to Insert Node in a Binary Search Tree
struct Node* Insert(struct Node *root,char data) {
	if(root == NULL) {
		root = (struct Node*)malloc(sizeof(struct Node));
		root->data = data;
		root->left = root->right = NULL;
	}
	else if(data <= root->data)
		root->left = Insert(root->left,data);
	else 
		root->right = Insert(root->right,data);
	return root;
}
 
int main() {
	/*Code To Test the logic
	  Creating an example tree
	            M
			   / \
			  B   Q
			 / \   \
			A   C   Z
    */
	struct Node* root = NULL;
	root = Insert(root,'M'); 
	root = Insert(root,'B');
	root = Insert(root,'Q'); 
	root = Insert(root,'Z'); 
	root = Insert(root,'A'); 
	root = Insert(root,'C');
	//Print Nodes in Preorder. 
	printf("Preorder: ");
	Preorder(root);
	printf("\n");
	//Print Nodes in Inorder
	printf("Inorder: ");
	Inorder(root);
	printf("\n");
	//Print Nodes in Postorder
	printf("Postorder: ");
	Postorder(root);
	printf("\n");
}