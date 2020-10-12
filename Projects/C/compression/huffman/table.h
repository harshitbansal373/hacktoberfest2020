#include"tree.h"
typedef struct table{
	char ch;
	char str[1024];
	int count;
}table;
void InitTable(table *t, int n);
int CreateTable(table* th, tree *t, char* str, int pos);
int printtable(table *t, int n);
