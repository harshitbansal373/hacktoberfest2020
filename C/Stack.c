// Implementation of Stack 
// Operation : Push() and Pop()

#include <stdio.h>
#define MAX 10
int A[10];
void push(int [],int,int*);
int pop(int[],int*);
void main()
{
	int top = 0,ch,num;
	do
	{
	
		printf("\n enter your choices \n1.Push operation \n2.Pop operration \n3.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\n Pls enter  a num to be pushed : ");
				scanf("%d",&num);
				push(A,num,&top);
				break;
			case 2:
				printf("\n Pls enter a number to be pop:");
				scanf("%d",num);
				break;
			case 3:
				break;
			default:
				printf("\n Wrong choise !");
		}
	}while(ch != 3);
}
void push(int A[],int num, int* top)
{
	if(*top == MAX)
	{
		printf("\n The stack is FULL !");
		return;
	}
	else
	{
		*top = *top + 1;
		A[*top] = num;
		printf("\n The pushed element is %d and position is %d",num,*top);
	}
}
int pop(int A[], int* top)
{
	int num;
	if(*top == 0)
	{
		printf("\n The stack is empty !");
		return;
	}
	else
	{
		A[*top] = num;
		printf("\n The poped element is %d and position is %d",num,*top);
		*top = *top - 1;
		return(num);
	}
}
