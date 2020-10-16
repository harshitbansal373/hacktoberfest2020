typedef struct node {
	char data[15];
	struct node *next;
}node;

typedef struct ends {
	node *front;
	node *rear;
}ends;

typedef ends *list;

typedef node *n;

int length(list l);

void init(list *l);

void insert(list *l, char *str, int pos); 
 
char *traverse(list *l);
 
void remDuplicate(list *l);

void interseclist(list *l1, list *l2);
