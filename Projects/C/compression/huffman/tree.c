#include"tree.h"
#include<stdio.h>
#include<stdlib.h>
void inittree(tree *t){
	*t = NULL;
}
tree CreateTreeOfOneNode(data d){
	node* tmp = (node*)malloc(sizeof(node));
	tmp->d = d;
	tmp->isleaf = 1;
	tmp->left = tmp->right = NULL;
	return tmp;
}
tree CreateTreeFromTwoTree(tree *t1, tree *t2){
	node *tmp = (node*)malloc(sizeof(node));
	tmp->d.ch = '\0';
	tmp->d.count = (*t1)->d.count + (*t2)->d.count;
	tmp->isleaf = 0;
	tmp->left = *t1;
	tmp->right = *t2;
	return tmp;
}
void inorder(tree *t){
	if(*t == NULL)
		return;
	if((*t)->left == (*t)->right){
		printf("1 %c ", (*t)->d.ch);
	}
	else{
		printf("0 ");
	}
	inorder(&((*t)->left));
	inorder(&((*t)->right));
}
int printleaves(tree *t){
	if(*t == NULL)
		return 0;
	static int c = 0;
	if((*t)->left == NULL && (*t)->right == NULL){
		printf("%d %c", (*t)->d.count, (*t)->d.ch);
		c++;
	}
	printleaves(&((*t)->left));
	printleaves(&((*t)->right));
	return c;
}
