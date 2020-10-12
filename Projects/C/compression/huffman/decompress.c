#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include"tree.h"
void getpreorder(int fdr, int* arr, int* n){
	unsigned char ch, next, nextkanext;
	int i = 0, j, k;
	read(fdr, &ch, sizeof(char));
	read(fdr, &next, sizeof(char));
	while(read(fdr, &nextkanext, sizeof(char))){
		if(nextkanext == '\0')
			break;
		while(i < 8){
			k = ch & 0x80;
			if(k == 0)
				arr[(*n)++] = 0;
			else if(k != 0) 
				arr[(*n)++] = 1;
			ch = ch << 1;
			i++;
		}
		i = 0 ;
		ch = next;
		next = nextkanext;
	}
	int use = next - '0';
	for(j = 0; j < use; j++){
		k = ch & 0x80;
		if(k == 0)
			arr[(*n)++] = 0;
		else if(k != 0)
			arr[(*n)++] = 1;
		ch = ch << 1;
	}
}
tree buildtreeconti(int* arr, int* index, int n){
	int in = *index;
	if(in == n)
		return NULL;
	node* tmp = (node*)malloc(sizeof(node));
	tmp->isleaf = arr[in];
	tmp->left = tmp->right =  NULL;
	(*index)++;
	if(arr[in] == 0){
		tmp->left = buildtreeconti(arr, index, n);
		tmp->right = buildtreeconti(arr, index, n);
	}
	return tmp;
}
tree buildtree(int*arr, int n){
	int index = 0;
	return buildtreeconti(arr, &index, n);
}
void giveleaves(tree* t, int fdr){
	if(*t == NULL)
		return;
	if((*t)->left == NULL && (*t)->right == NULL){
		unsigned char ch;
		read(fdr, &ch, sizeof(ch));
		(*t)->d.ch = ch;
	}
	giveleaves(&((*t)->left), fdr);
	giveleaves(&((*t)->right), fdr);	
}
void decode(int fdr, int fdw, tree* t){
	node* p = *t;
	int i = 0, j, k; 
	unsigned char ch, next, nextkanext;
	read(fdr, &ch, sizeof(char));
	read(fdr, &next, sizeof(char));
	while(read(fdr, &nextkanext, sizeof(char))){
		while(i < 8){
			k = ch & 0x80;
			if(k == 0){
				if(p->left == p->right){
					write(fdw, &(p->d.ch), sizeof(p->d.ch));
					p = *t;
				}
				p = p->left;
				ch = ch << 1;
			}
			else if(k != 0) {
				if(p->left == p->right){
					write(fdw, &(p->d.ch), sizeof(p->d.ch));
					p = *t;
				}
				p = p->right;
				ch = ch << 1;
			}
			i++;
		}
		i = 0 ;
		ch = next;
		next = nextkanext;
	}
	int use = next - '0';
	for(j = 0; j < use; j++){
		k = ch & 0x80;
		if(k == 0){
			if(p->left == p->right){
				write(fdw, &(p->d.ch), sizeof(p->d.ch));
				p = *t;
			}
			p = p->left;
			ch = ch << 1;
		}
		else if(k != 0){
			if(p->left == p->right){
				write(fdw, &(p->d.ch), sizeof(p->d.ch));
				p = *t;
			}
			p = p->right;
			ch = ch << 1;
		}
	}
	write(fdw, &(p->d.ch), sizeof(p->d.ch));
}
void decompress(int fdr, int fdw){
	int arr[1024], n = 0, i;
	getpreorder(fdr, arr, &n);
	tree t;
	t = buildtree(arr, n);
	giveleaves(&t, fdr);
	decode(fdr, fdw, &t);
}
