#include"heap.h"
#include<stdio.h>
void InitHeap(heap *h){
	h->n = 0;
}
void InsertInHeap(heap *h, tree *t){
	h->t[h->n] = *t;
	int c = h->n;
	int p = (c - 1)/2;
	tree tmp;
	while(c > 0){
		if((h->t[c])->d.count < (h->t[p])->d.count){
			tmp = h->t[c];
			h->t[c] = h->t[p];
			h->t[p] = tmp;	
		}
		else
			break;
		c = p;
		p = (c - 1)/2;
	}
	(h->n)++;
}
int findmin(heap *h, int x, int y, int z){
	if((h->t[x])->d.count <= (h->t[y])->d.count && 
		(h->t[x])->d.count <= (h->t[z])->d.count)
		return x;
	else if((h->t[y])->d.count <= (h->t[x])->d.count && 
		(h->t[y])->d.count <= (h->t[z])->d.count)
		return y;
	else
		return z;
}
tree RemoveFromHeap(heap *h){
	tree ret, tmp;
	ret = h->t[0];
	h->t[0] = h->t[--(h->n)];
	int c1, c2, p, small;
	p = 0;
	c1 = 2*p + 1;
	c2 = 2*p + 2;
	while(c1 < h->n){
		small = findmin(h, p, c1, c2);
		if(small == p)
			break;
		tmp = h->t[small];
		h->t[small] = h->t[p];
		h->t[p] = tmp;
		p = small;
		c1 = 2*p + 1;
		c2 = 2*p + 2;
	}
	return ret;
}
int IsHeapEmpty(heap *h){
	return h->n == 0;
}
int IsHeapFull(heap *h){
	return h->n == SIZE;
}
void printheap(heap *h){
	int i = 0;
	for(i = 0; i < h->n; i++){
		printf("%d ", (h->t[i])->d.count);
	}
}
