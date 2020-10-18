#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 26
#include"dictionary.h"

int main() {	
	dictionary Dict[SIZE];
	initDict(Dict);
	char word[50], meaning[50];	
	int choice;
	while(1) {	
		printf("1.Insert\n2.Update\n3.Delete\n4.Find and Print(With number of Comparisons)\n5.Print in Ascending Order\n6.Exit\n");
		scanf("%d", &choice);
		if(choice == 1) {
			printf("Enter word: ");
			scanf("%s", word);
			printf("Enter its meaning: ");
			scanf("%s",meaning);
			insert(Dict ,word ,meaning);	
		}
		else if(choice == 2) {
			printf("Enter word: ");
			scanf("%s", word);
			printf("Enter new meaning: ");
			scanf("%s",meaning);
			update(Dict ,word, meaning);
		}
		else if (choice == 3) {
			printf("Enter word: ");
			scanf("%s", word);
			delete(Dict ,word);
		}
		else if(choice == 4) {
			printf("Enter word: ");
			scanf("%s", word);
			findAndPrint(Dict ,word);
		}
		else if(choice == 5) {
			printDict(Dict);
		}
		else if(choice == 6) {
			return 0;
		}
		else {
			printf("Invalid Choice!!");
		}
	}
}
