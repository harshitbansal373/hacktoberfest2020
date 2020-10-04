#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 10

typedef struct ArrayStack {
    int top;
    unsigned capacity;
    int* array;
}arrstack;

void push(arrstack*, int);
int pop(arrstack*);
arrstack* createStack();
void doubleStack(arrstack*);

arrstack* createStack() {
  arrstack* stack = (arrstack*) malloc(sizeof(arrstack));
  stack -> top = -1;
  stack -> capacity = MAX_SIZE;
  stack -> array = (int*) malloc(stack -> capacity * sizeof(int));
  return stack;
}

void push(arrstack* stack, int data) {
  if(stack -> top == stack -> capacity - 1) {
    doubleStack(stack);
    push(stack, data);
  } else {
    stack -> top++;
    stack -> array[stack -> top] = data;
  }
}

int pop(arrstack* stack) {
  if (stack -> top == -1)
    return INT_MIN;
  else
    return stack -> array[stack -> top--];
}

void doubleStack(arrstack* stack) {
  stack -> capacity *= 2;
  stack -> array = realloc(stack -> array, stack -> capacity * sizeof(int));
}

void main() {
  arrstack* stack = createStack();

  push(stack, 10);
  push(stack, 20);
  push(stack, 30);
  push(stack, 40);
  push(stack, 50);
  push(stack, 20);
  push(stack, 30);
  push(stack, 40);
  push(stack, 50);
  push(stack, 20);
  push(stack, 30);
  push(stack, 40);
  push(stack, 50);

  printf("%d\n", pop(stack));
  printf("%d\n", pop(stack));
  printf("%d\n", pop(stack));
  printf("%d\n", pop(stack));
  printf("%d\n", pop(stack));
  printf("%d\n", pop(stack));
}
