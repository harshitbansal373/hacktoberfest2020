#include"table.h"
#include<stdio.h>
#include<string.h>
void InitTable(table *th, int n){
	int i;
	for(i = 0; i < n; i++){
		th[i].count = 0;
		strcpy(th[i].str, "");
	}
}
#define leftd '0'
#define rightd '1'
int CreateTable(table* th, tree *t, char* str,int pos){
	static int c = 0;
	if((*t)->left){
		str[pos] = leftd;
		CreateTable(th, &((*t)->left), str, pos + 1);
	}
	if((*t)->right){
		str[pos] = rightd;
		CreateTable(th, &((*t)->right), str, pos + 1);
	}
	if((*t)->right == NULL && (*t)->left == NULL){
		str[pos] = '\0';
		int index = (int)(*t)->d.ch;
		th[index].ch = (*t)->d.ch;
		th[index].count = (*t)->d.count;
		strcpy(th[index].str, str);
		c++;
	}
	return c;
}
int printtable(table *th, int n){
	int i;
	int c = 0;
	for(i = 0; i < n; i++){
		if(th[i].count != 0){
			printf("%4d, %3c, %10s, %3d\n",i,  th[i].ch, th[i].str, th[i].count);
			c++;
		}
	}
	return c;
}
