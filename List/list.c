#include "list.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void init(list *l) {
	(*l) = (list)malloc(sizeof(ends));
	(*l) -> front = NULL;
	(*l ) -> rear = NULL;
}


int length(list l) {
	node *ptr;
	int count = 0;
	ptr = l->front;
	if(!ptr) {
		return 0;
	}
	while(l->rear != ptr) {
		ptr = ptr->next;
		count++;
	}
	return count+1;
}
void insert(list *l, char *str, int pos) {
	int i, len;
	node *ptr, *temp;
	len = length(*l);
	ptr = (node*)malloc(sizeof(node));
	strcpy(ptr->data, str);
	if(pos < 0 || pos > len) {
		return;
	}
	else if(pos == 0) {
	        if((*l)->front == NULL) {
	                (*l)->front = (*l)->rear = ptr->next = ptr;       
	        }
	        else {
	                ptr->next = (*l)->front;
	                (*l)->front = ptr;
	                (*l)->rear->next = ptr;
	        }
	}
	else if(pos == len) {
	        ptr->next = (*l)->front;
	        (*l)->rear->next = ptr;
	        (*l)->rear = ptr;
	}
	else {
	        temp = (*l)->front;
	        for(i = 1; i < pos; i++) {
	                temp = temp->next;
	        }
	        ptr->next = temp->next;
	        temp->next = ptr;        
	}  
}
	                        	                    
char s[100];
char *traverse(list *l) {
	n ptr;
	int i = 0;
	if(((*l) -> front) != NULL) {
		ptr = ((*l) -> front);
		strcpy(s, ptr -> data);
		while(s[i] != '\0') {
			i++;
		}
		s[i] = '\n';
		s[++i] = '\0';
		while((ptr -> next) != ((*l) -> front)) {
			i =0;
			ptr = ptr -> next;
			strcat(s, ptr -> data);	
			while(s[i] != '\0') {
				i++;
			}
			s[i] = '\n';
			s[++i] = '\0';
		}
	}	
	return s;
}

void remDuplicate(list *l) {
	n ptro = ((*l) -> front), ptrc = ((*l) -> front), p = ((*l) -> front), temp;
	int res;
	if(ptro != NULL) {
		while((ptro-> next) != ((*l) -> front)) {
			ptrc = ((*l) -> front);
			ptro = ptro -> next;
			while((ptrc -> next) != ((*l) -> front)) {
				if(ptrc != ptro) {
					res = strcmp(ptrc -> data, ptro -> data);
					if(res != 0) {
						ptrc = ptrc -> next;
						continue;
					}
					else if(res == 0){
						while(p -> next != ptrc) {
							p = p -> next;
						}
						temp = ptrc;
						ptrc = ptrc -> next;
						p -> next = ptrc;
						free(temp);
					}
				}
				else
					ptrc = ptrc -> next;
				
			}
		}
	}
}

void interseclist(list *l1, list *l2) {
	int j = 0;
	node *temp1 = ((*l1) -> front), *temp2;
	printf("[");
	do {
		temp2 = ((*l2) -> front);
		do {
			if(!strcmp(temp1 -> data , temp2 -> data)) {
				printf("%s\t", temp1 -> data);
				j++;
			}
			temp2 = temp2 -> next;
		}while(temp2 != ((*l2) ->rear -> next));
		temp1 = temp1 -> next;
	}while(temp1 != ((*l1) -> rear -> next));
	printf("]\n");
}	
