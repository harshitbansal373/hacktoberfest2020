#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node {
	char *str;
	struct node *prev, *next;
}node;

typedef struct list {
	node *p, *q;
}list;


void init(list *l) {
	l->p = NULL;
	l->q = NULL;
}

int length(list l) {
	node *tmp;
	int len = 0;
	tmp = l.p;
	if(!tmp)
		return 0;
	do {
		len++;
		tmp = tmp->next;
	}while(tmp != l.p);
	return len;
}

void reverse(list *l) {
	node *p, *q, *r, *tmp;
	if(l->p == NULL)
		return;          	//empty list
	q = l->p;
	p = q->next;
	r = p->next;
	while(r != q) {
		p->next = q;
		q = p;
		p = r;
		r = r->next;
	}
	q = l->q;
	p = q->prev;
	r = p->prev;
	while(r != q) {
		p->prev = q;
		q = p;
		p = r;
		r = r->prev;
	}
	tmp = l->p;
	l->p = l->q;
	l->q = tmp;
}

void traverse(list l) {
	node *tmp;
	tmp = l.p;
	printf("List : [ ");
	if(!tmp) {
		printf("]\n");
		return;
	}
	do {
		printf("%s ", tmp->str);
		tmp = tmp->next;
	}while(tmp != l.p);
	printf("]\n");
}


void insert(list *l, char *str, int pos) {
	int i, len;
	node *x, *tmp;
	len = length(*l);
	if(pos < 0 || pos > len) {
		printf("Enter proper position\n");
		return;
	}
	tmp = l->p;
	x = (node *)malloc(sizeof(node));
	x->str = (char *)malloc(sizeof(strlen(str) + 1));
	strcpy(x->str, str);
	if(len == 0) {
		l->p = l->q = x;
		x->prev = x->next = x;
		traverse(*l);
		return;
	}
	tmp = l->p;
	for(i = 0; i < pos - 1; i++) 
		tmp = tmp->next;
	if(pos == 0)
		tmp = l->q;
	
	tmp->next->prev = x;
	x->next = tmp->next;
	tmp->next = x;
	x->prev = tmp;
	if(pos == 0)
		l->p = x;
	if(pos == len)
		l->q =x;
	traverse(*l);
}




int cchoice() {
	int n;
	printf("Enter Your Choice\n");
	printf("1.Insert\n2.Traverse\n3.Reverse\n");
	scanf("%d", &n);
	return n;
}
int main() {
	int choice, pos;
	list l;
	init(&l);
	char str[50];
	
	while(1) {
		choice = cchoice();
		switch(choice) {
			case 1:
				printf("Enter the string and position\n");
				scanf("%s%d", str, &pos);
				insert(&l, str, pos);
				break;
			case 2:
				traverse(l);
				break;
			case 3:
				reverse(&l);
				break;
			default:
				printf("Wrong Choice\n");
				break;
		}
	}
	return 0;
}
		
	

//Above function can reverse the linked list in which 3 pointers are used  
//q points to node, p points to nodes's next and r points to p's next node  
