//HASHING USING CHAINING METHOD

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 26
#include"dictionary.h"

///////////////////////////////////////////////////////

//TIME cOMPLEXITY

//BEST CASE -: O(1)
//WORST CASE -: O(n)
//////////////////////////////////////////////////////

void initDict(dictionary* Dict) {
	for(int i = 0; i < SIZE; i++) {
		Dict[i] = NULL;
	}
	return;
}

void printDict(dictionary *Dict) {
	for(int i = 0; i < SIZE; i++) {
		node *current = Dict[i];
		while(current) {
			printf("%s %s\n", (current->word), (current->meaning));
			current = current-> next;
		}
	}
	return;
}

int hashFunction(char letter) {
	if(('a' <= letter) && (letter<= 'z')) {
		return (letter - 'a');
	}
	else if(('A' <= letter) && (letter<= 'Z')) {
		return (letter - 'A');
	}
	return -1;
}

void insert(dictionary* Dict, char *word, char *meaning) {
	int index = hashFunction(word[0]);
	if (index == -1) {
		printf("Can't Enter Element\n");
		return;
	}
	node* temp = (node *)malloc(sizeof(node));
	temp -> next = NULL;
	strcpy((temp -> word), word);
	strcpy((temp -> meaning), meaning);

	if(Dict[index] == NULL) {
		Dict[index] = temp;
		return;
	}
	node *current = Dict[index];
	while(current) {
		if(strcmp(current -> word, word) < 0) {
			if(((current -> next) && (strcmp(current -> next-> word,word) > 0))||!(current -> next)) {
				temp -> next = current -> next;
				current -> next = temp;
				return;
			}
			else {
				current = current -> next;
			}
		}
		else {
			temp -> next = Dict[index];
			Dict[index] = temp;
			return;
		}
	}
}

void delete(dictionary* Dict ,char *word) {
	int index = hashFunction(word[0]);
	node* current=Dict[index];
	node* prev = NULL;
	while(current && strcmp(current->word,word)) {
		prev = current;
		current = current -> next;
	}
	if(current) {
		if(!prev) {
			Dict[index] = current -> next;
			free(current);
			return;
		}
		prev -> next = current -> next;
		free(current);
		return;
	}
	else {
		printf("Word is not in dictionary\n");
	}
}

void update(dictionary* Dict ,char *word, char* meaning) {
	int index = hashFunction(word[0]);
	node* current=Dict[index];
	while(current && strcmp(current->word,word)) {
		current = current -> next;
	}
	if(current) {
		strcpy(current -> meaning, meaning);
		return;
	}
	else {
		printf("Word is not in dictionary\n");
		
	}
}

void findAndPrint(dictionary* Dict ,char *word) {
	int index = hashFunction(word[0]);
	node* current=Dict[index];
	int count = 1;
	while(strcmp(current->word,word) && current) {
		count++;
		current = current -> next;
	}
	if(current) {
		printf("Word: %s  Meaning:%s  NumberOfComparisions: %d\n", (current-> word), (current->meaning), count);
		return;
	}
}
