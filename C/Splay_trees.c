//Hacktoberfest

#include<stdio.h>
#include<stdlib.h>

struct node{
        int data;
        struct node *left;
        struct node *right;

}*root=NULL;

//Function Prototype
void printGivenLevel(struct node* root, int level); 
int height(struct node* node); 

struct node* newNode(int data) 
{ 
    struct node* node = (struct node*)malloc(sizeof(struct node)); 
    node->data   = data; 
    node->left  = node->right  = NULL; 
    return (node); 
} 

void printLevelOrder(struct node* root) 
{ 
    int h = height(root); 
    int i; 
    for (i=1; i<=h; i++) 
        printGivenLevel(root, i); 
} 
  
void printGivenLevel(struct node* root, int level) 
{ 
    if (root == NULL) 
        return; 
    if (level == 1) 
        printf("%d ", root->data); 
    else if (level > 1) 
    { 
        printGivenLevel(root->left, level-1); 
        printGivenLevel(root->right, level-1); 
    } 
} 
  
int height(struct node* node) 
{ 
    if (node==NULL) 
        return 0; 
    else
    { 
        /* compute the height of each subtree */
        int lheight = height(node->left); 
        int rheight = height(node->right); 
  
        /* use the larger one */
        if (lheight > rheight) 
            return(lheight+1); 
        else return(rheight+1); 
    } 
} 
  
struct node *rightRotate(struct node *x) 
{ 
    struct node *y = x->left; 
    x->left = y->right; 
    y->right = x; 
    return y; 
} 
  
struct node *leftRotate(struct node *x) 
{ 
    struct node *y = x->right; 
    x->right = y->left; 
    y->left = x; 
    return y; 
} 

struct node *splay(struct node *root, int data) 
{ 
    if (root == NULL || root->data == data) 
        return root; 
  
    // data lies in left subtree 
    if (root->data > data) 
    { 
        // data is not in tree, we are done 
        if (root->left == NULL) return root; 
  
        if (root->left->data > data) 
        { 
            // First recursively bring the data as root of left-left 
            root->left->left = splay(root->left->left, data); 
  
            // Do first rotation for root, second rotation is done after else 
            root = rightRotate(root); 
        } 
        else if (root->left->data < data)  
        { 
            root->left->right = splay(root->left->right, data); 
  
            // Do first rotation for root->left 
            if (root->left->right != NULL) 
                root->left = leftRotate(root->left); 
        } 
  
        // Do second rotation for root 
        return (root->left == NULL)? root: rightRotate(root); 
    } 
    else // data lies in right subtree 
    { 
        // data is not in tree, we are done 
        if (root->right == NULL) return root; 
  
        if (root->right->data > data) 
        { 
            // Bring the data as root of right-left 
            root->right->left = splay(root->right->left, data); 
  
            // Do first rotation for root->right 
            if (root->right->left != NULL) 
                root->right = rightRotate(root->right); 
        } 
        else if (root->right->data < data) 
        { 
            // Bring the data as root of right-right and do first rotation 
            root->right->right = splay(root->right->right, data); 
            root = leftRotate(root); 
        } 
  
        // Do second rotation for root 
        return (root->right == NULL)? root: leftRotate(root); 
    } 
} 

struct node *search(struct node *root, int key) 
{ 
    /*If the required node is found it will be made the root of the tree*/
    return splay(root, key); 
} 
  
struct node *insert(struct node *root, int k) 
{ 
    if (root == NULL) return newNode(k); 
  
    // Bring the closest leaf node to root 
    root = splay(root, k); 
  
    // If data is already present, then return 
    if (root->data == k) return root; 
  
    // Otherwise allocate memory for new node 
    struct node *newnode  = newNode(k); 
  
    // If root's data is greater, make root as right child 
    // of newnode and copy the left child of root to newnode 
    if (root->data > k) 
    { 
        newnode->right = root; 
        newnode->left = root->left; 
        root->left = NULL; 
    } 
  
    // If root's data is smaller, make root as left child 
    // of newnode and copy the right child of root to newnode 
    else
    { 
        newnode->left = root; 
        newnode->right = root->right; 
        root->right = NULL; 
    } 
  
    return newnode; // newnode becomes new root 
} 

/* Implemented Search and Insert operations of splay tree.
All operations of splay tree are similar to operations of Binary Search Tree with an additional splay operation.
Here I have performed insertion as first splay the last visited node and then insert and make inserted newnode as root.  
Insertion can be performed in this way also - Insert the element as BST and then perform splaying on the element. */
    
int main()
{
    
    int choice;
    int s, ins;
    
    while(1){
        printf("Input the operation you want to perform: \n1. Search a node from the Splay Tree \n2. Insert a node in Splay Tree \n3. Exit\n");
        scanf("%d", &choice);
        if(choice == 1){
            printf("Enter the element you want to search:\n");
            scanf("%d",&s);
            root = search(root, s); 
            printf("The level order traversal of current tree after searching %d is:\n", s);
            printLevelOrder(root); 
            printf("\n");
        }
        else if (choice == 2){
            printf("Enter the element you want to insert:\n");
            scanf("%d", &ins);
            root = insert(root, ins); 
            printf("The level order traversal of current tree after inserting %d is:\n", ins);
            printLevelOrder(root); 
            printf("\n");
        }
        else if(choice == 3){
            printf("The level order traversal of final tree is:\n");
            printLevelOrder(root); 
            printf("\n");
            printf("Thank you\n");
            return 0;
        }
        else {
            printf("Enter the appropriate choice\n");
        }
    }
}
