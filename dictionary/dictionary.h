typedef struct node {
	char word[50];
	char meaning[50];
	struct node *next;
}node;

typedef struct node * dictionary;

void initDict(dictionary* Dict);

void printDict(dictionary *Dict);

int hashFunction(char letter);

void insert(dictionary* Dict, char *word, char *meaning);

void delete(dictionary* Dict ,char *word);

void update(dictionary* Dict ,char *word, char* meaning);

void findAndPrint(dictionary* Dict ,char *word);
