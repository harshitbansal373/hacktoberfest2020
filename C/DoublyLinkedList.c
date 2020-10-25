#include<stdio.h>
struct node
{
    struct node *prev;
    struct node *next;
    int data;
};
struct node *head;
void insertBeg();
void insertLast();
void insertAt();
void deleteBeg();
void deleteLast();
void deleteAt();
void display();
void search();
void main ()
{
int c =0;
    while(c != 9)
    {
        printf("\nChoose: ");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            insertBeg();
            break;
            case 2:
            insertLast();
            break;
            case 3:
            insertAt();
            break;
            case 4:
            deleteBeg();
            break;
            case 5:
            deleteLast();
            break;
            case 6:
            deleteAt();
            break;
            case 7:
            search();
            break;
            case 8:
            display();
            break;
            case 9:
            exit(0);
            break;
            default:
            printf("enter valid value.");
        }
    }
}
void insertBeg()
{
   struct node *ptr=(struct node *)malloc(sizeof(struct node));
   int item;
   if(ptr == NULL)
   {
       printf("\n overflow");
   }
   else
   {
    printf("\nEnter Item value: ");
    scanf("%d",&item);

   if(head==NULL)
   {
       ptr->next = NULL;
       ptr->prev=NULL;
       ptr->data=item;
       head=ptr;
   }
   else
   {
       ptr->data=item;
       ptr->prev=NULL;
       ptr->next = head;
       head->prev=ptr;
       head=ptr;
   }
}

}
void insertLast()
{
   struct node *ptr,*temp;
   int item;
   ptr = (struct node *) malloc(sizeof(struct node));
   if(ptr == NULL)
   {
       printf("\n overflow");
   }
   else
   {
       printf("\nEnter value: ");
       scanf("%d",&item);
        ptr->data=item;
       if(head == NULL)
       {
           ptr->next = NULL;
           ptr->prev = NULL;
           head = ptr;
       }
       else
       {
          temp = head;
          while(temp->next!=NULL)
          {
              temp = temp->next;
          }
          temp->next = ptr;
          ptr ->prev=temp;
          ptr->next = NULL;
          }
       }
    }
void insertAt()
{
   struct node *ptr,*temp;
   int item,loc,i;
   ptr = (struct node *)malloc(sizeof(struct node));
   if(ptr == NULL)
   {
       printf("\n overflow");
   }
   else
   {
       temp=head;
       printf("Enter the location");
       scanf("%d",&loc);
       for(i=0;i<loc;i++)
       {
           temp = temp->next;
           if(temp == NULL)
           {
               printf("\n underflow");
               return;
           }
       }
       printf("Enter value");
       scanf("%d",&item);
       ptr->data = item;
       ptr->next = temp->next;
       ptr -> prev = temp;
       temp->next = ptr;
       temp->next->prev=ptr;
   }
}
void deleteBeg()
{
    struct node *ptr;
    if(head == NULL)
    {
        printf("\n underflow");
    }
    else if(head->next == NULL)
    {
        head = NULL;
        free(head);
    }
    else
    {
        ptr = head;
        head = head -> next;
        head -> prev = NULL;
        free(ptr);
    }

}
void deleteLast()
{
    struct node *ptr;
    if(head == NULL)
    {
        printf("\n underflow");
    }
    else if(head->next == NULL)
    {
        head = NULL;
        free(head);
    }
    else
    {
        ptr = head;
        if(ptr->next != NULL)
        {
            ptr = ptr -> next;
        }
        ptr -> prev -> next = NULL;
        free(ptr);
    }
}
void deleteAt()
{
    struct node *ptr, *temp;
    int val;
    printf("\n enter the data after which the node is to be deleted: ");
    scanf("%d", &val);
    ptr = head;
    while(ptr -> data != val)
    ptr = ptr -> next;
    if(ptr -> next == NULL)
    {
        printf("\n can't delete");
    }
    else if(ptr -> next -> next == NULL)
    {
        ptr ->next = NULL;
    }
    else
    {
        temp = ptr -> next;
        ptr -> next = temp -> next;
        temp -> next -> prev = ptr;
        free(temp);
    }
}
void display()
{
    struct node *ptr;
    ptr = head;
    while(ptr != NULL)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}
void search()
{
    struct node *ptr;
    int item,i=0,flag;
    ptr = head;
    if(ptr == NULL)
    {
        printf("\nEmpty List");
    }
    else
    {
        printf("\n enter item to be searched");
        scanf("%d",&item);
        while (ptr!=NULL)
        {
            if(ptr->data == item)
            {
                printf("\n item found at location %d ",i+1);
                flag=0;
                break;
            }
            else
            {
                flag=1;
            }
            i++;
            ptr = ptr -> next;
        }
        if(flag==1)
        {
            printf("\n item not found");
        }
    }

}
