#include"table.h"
#define SIZE 257
typedef struct heap{
	tree t[SIZE];
	int n;
}heap;
void InitHeap(heap *h);
void InsertInHeap(heap *h, tree *t);
tree RemoveFromHeap(heap *h);
int IsHeapEmpty(heap *h);
int IsHeapFull(heap *h);
void printheap(heap *h);
