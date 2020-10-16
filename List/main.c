#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>
#include<limits.h>
#include<unistd.h>
#include"list.h"

int main() {
	list l, l2;
	char *s;
	init(&l);
	init(&l2);
	insert(&l, "hey", 0);
	insert(&l, "Muskan", 1);
	insert(&l, "People", 2);
	insert(&l, "Level", 3);
	insert(&l, "Muskan", 2);
	insert(&l, "Pune", 4);
	insert(&l, "Pune", 5);
	insert(&l, "Pune", 6);
	insert(&l2, "People", 0);
	insert(&l2, "Level", 1);
	insert(&l2, "Muskan", 2);
	insert(&l2, "Pune", 3);
	insert(&l2, "Vrinda", 4);
	s = traverse(&l);
	int i = 0;
	printf("[");
	while(s[i] != '\0') {
		if(s[i] == '\n') 
			printf("\t");
		else
			printf("%c", s[i]);
			i++;
	}
	printf("]");
	printf("\n");
	s = traverse(&l2);
	i = 0;
	printf("[");
	while(s[i] != '\0') {
		if(s[i] == '\n') 
			printf("\t");
		else
			printf("%c", s[i]);
			i++;
	}
	printf("]");
	printf("\n");
	remDuplicate(&l);
	remDuplicate(&l2);
	interseclist(&l, &l2);
	return 0;
	}

