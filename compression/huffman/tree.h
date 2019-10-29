typedef struct data{
	unsigned char ch;
	int count;
}data;
typedef struct node{
	data d;
	int isleaf;
	struct node* left;
	struct node* right;
}node;
typedef node* tree;

void inittree(tree *t);
tree CreateTreeOfOneNode(data d);
tree CreateTreeFromTwoTree(tree *t1, tree *t2);
void inorder(tree *t);
int printleaves(tree *t);
