#include <stdio.h>
#include <stdlib.h>

#define N 5
int a[N];
int top=-1;

void push()
{
    int temp;
    printf("\nEnter the number to store in the stack\n");
    scanf("%d",&temp);
    if(top==N-1)
    {
        printf("\nOverflow condition\n");
    }
    else
    {
        top++;
        a[top]=temp;
        printf("\nNumber stored successfully\n");
    }
}
void pop()
{
    int temp;
    if(top==-1)
    {
        printf("\nUnderflow condition\n");
    }
    else
    {
        temp=a[top];
        top--;
        printf("\n%d deleted from stack\n",temp);
    }
}
void peek()
{
    if(top==-1)
    {
        printf("\nUnderflow Condition\n");
    }
    else
    {
        printf("\nTop of the stack is %d\n",a[top]);
    }
}
void display()
{
    int i;
    if(top==-1)
    {
        printf("\nUnderflow condition\n");
    }
    else
    {
        printf("\nElements of array are\n");
        for(i=top;i>=0;i--)
        {
        printf("--> %d\n",a[i]);
        }
    }
}

int main()
{
    while(1)
    {
        system("cls");
        int n;
        printf("\nEnter option of your choice\n");
        printf("\n1. Push() \n2. Pop() \n3. Peek() \n4. Display() \n5. Exit()\n");
        scanf("%d",&n);

        switch(n)
        {
        case 1:
            push();
            getch();
            break;

        case 2:
            pop();
            getch();
            break;

        case 3:
            peek();
            getch();
            break;

        case 4:
            display();
            getch();
            break;

        case 5:
            exit(0);
            break;

        default:
            printf("Enter valid option!!!");
        }

    }
}
