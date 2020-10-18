#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>
#define TB 100

void conti_allocate();
void conti_deallocate();
void conti_display();
int conti_BFull();

void ind_allocate();
void ind_deallocate();
void ind_display();
int ind_BFull();

void lin_allocate();
void lin_deallocate();
void lin_display();
int lin_BFull();

struct Sequence
{
    char n[30];
    int len;
    int st;
}CF[30];

struct Indexed
{
    char n[30];
    int len;
    int indexblock;
    int *IB[TB];
}IF[30];

struct Link
{
    char n[30];
    int len;
    int st;
    struct node
    {
        int index;
        struct node *next;
    }*Start,*current,*newnode,*temp;
}LF[30];

int conti_Table[TB],conti_pos=0,conti_r,i,j,ch,conti_B=0;
char conti_fn[30];
int ind_Table[TB+1],ind_pos=0,ind_r,ind_B=0,indexblock,k=0;
char ind_fn[30];
int lin_Table[TB+1],lin_pos=0,lin_r,lin_B=0;
char lin_fn[30];

//Contigious memory allocation
void conti()
{
     printf("\n Contiguous File Allocation \n\n");
     do{
     printf("\n\n1.Allocate\n2.Deallocate\n3.Display\n4.Exit");
     printf("\n\nEnter Your choice : ");
     scanf("%d",&ch);
     switch(ch)
     {
                case 1:
                    conti_pos++;
                    conti_allocate();
                    break;

                case 2:
                    conti_deallocate();
                    break;

                case 3:
                    conti_display();
                    break;

                case 4:
                    exit(0);

                default:
                    printf("\nInvalid Choice ");
        }
     }while(ch!=4);

}
void conti_allocate()
{
   printf("\nEnter File Name : ");
   scanf("%s",&(CF[conti_pos].n));
   printf("\nEnter File Length : ");
   scanf("%d",&(CF[conti_pos].len));
   if(conti_BFull())
   {
        conti_pos--;
       printf("\n\nNo Enough Free Space Available \n");
       return;
   }
   while(1)
   {
        i=0;
        conti_r=(rand()%TB+1);
        if(conti_r+CF[conti_pos].len-1>TB)
           continue;
        if(conti_Table[conti_r]==0)
        {
                for(i=conti_r+1;i<conti_r+CF[conti_pos].len;i++)
                    if(conti_Table[i]==1)
                        break;
        }
        if(i==conti_r+CF[conti_pos].len)
            break;


    }
    CF[conti_pos].st=conti_r;
    for(i=conti_r;i<conti_r+CF[conti_pos].len;i++)
        conti_Table[i]=1;
    printf("\n\tFile Allocation Table\n");
    printf("\nFileName\tStart\tLength\n");
    for(i=1;i<=conti_pos;i++)
    {
        printf("\n%s\t\t%d\t%d",CF[i].n,CF[i].st,CF[i].len);
        printf("\n");
    }

}
void conti_deallocate()
{
   printf("\nEnter The File Name : ");
   scanf("%s",&conti_fn);
   for(i=1;i<=conti_pos;i++)
   {
            if(strcmp(CF[i].n,conti_fn)==0)
            {
                    for(j=CF[i].st ;j<(CF[i].len+CF[i].st);j++)
                        conti_Table[j]=0;
                    strcpy(CF[i].n,"NULL");
                    CF[i].st=0;
                    CF[i].len=0;
                    printf("\nFile (%s) Deleted Successfully \n",conti_fn);
                    break;
            }
            else
                printf("\nDeletion Unsuccessful\n");
    }
    printf("\n\t\tFile Allocation Table\n");
    printf("\nFileName\tStart\tLength\n");
    for(i=1;i<=conti_pos;i++)
    {
        printf("\n%s\t\t%d\t%d",CF[i].n,CF[i].st,CF[i].len);
        printf("\n");
    }
}
void conti_display()
{
    printf("\nEnter The File Name : ");
    scanf("%s",conti_fn);
    printf("\nBlocks Allocated Are : ");
    for(i=1;i<=conti_pos;i++)
    {
        if(strcmp(CF[i].n,conti_fn)==0)
        {
            for(j=CF[i].st;j<(CF[i].st+CF[i].len);j++)
                printf("--%d--",j);
            break;
        }
    }
}
int conti_BFull()
{
    for(i=1,conti_B=0;i<=conti_pos;i++)
        conti_B=conti_B+CF[i].len;
    if(conti_B>TB)
        return 1;
    else
        return 0;
}

//indexed memory allocation
void ind()
{
     printf("\n Indexed File Allocation \n\n");
     do{
     printf("\n\n1.Allocate\n2.Deallocate\n3.Display\n4.Exit");
     printf("\n\nEnter Your choice : ");
     scanf("%d",&ch);


     switch(ch)
     {
                case 1:
                    ind_pos++;
                    ind_allocate();
                    break;

                case 2:
                    k--;
                    ind_deallocate();
                    break;

                case 3:
                    ind_display();
                    break;

                case 4:
                    exit(0);

                default:
                    printf("\nInvalid Choice ");
        }
     }while(ch!=4);

}
void ind_allocate()
{
   printf("\nEnter File Name : ");
   scanf("%s",&(IF[ind_pos].n));
   printf("\nEnter File Length : ");
   scanf("%d",&(IF[ind_pos].len));
   if(ind_BFull())
   {
        ind_pos--;
       printf("\n\nNo Enough Free Space Available \n");
       return;
   }
    IF[ind_pos].indexblock=rand()%TB+1;
    ind_Table[IF[ind_pos].indexblock]=1;
   for(i=1;i<=IF[ind_pos].len;i++)
   {
        while(1)
        {

            ind_r=rand()%TB+1;
            if(ind_Table[ind_r]==0)
            {

                    IF[ind_pos].IB[i]=&ind_Table[ind_r];
                    ind_Table[ind_r]=ind_r;
                    break;
            }
        }
    }
    printf("\n\tDirectory\n");
    printf("\nFileName\tIndexBlock\n");
    for(i=1;i<=ind_pos;i++)
    {
        printf("\n%s\t\t%d",IF[i].n,IF[i].indexblock);
        printf("\n");
    }

}
void ind_deallocate()
{
   printf("\nEnter The File Name : ");
   scanf("%s",&ind_fn);
   for(i=1;i<=ind_pos;i++)
   {
            if(strcmp(IF[i].n,ind_fn)==0)
            {
                for(j=1;j<=IF[ind_pos].len;j++)
                   *IF[ind_pos].IB[j]=0;
                ind_Table[IF[ind_pos].indexblock]=0;
                strcpy(IF[i].n,"NULL");
                IF[i].indexblock=-1;
                IF[i].len=0;
                printf("\nFile (%s) Deleted Successfully \n",ind_fn);
                break;
            }
            else
                printf("\nDeletion Unsuccessful\n");
    }
    printf("\n\tDirectory\n");
    printf("\nFileName\tIndexBlock\n");
    for(i=1;i<=ind_pos;i++)
    {
        printf("\n%s\t\t%d",IF[i].n,IF[ind_pos].indexblock);
        printf("\n");
    }
}
void ind_display()
{
    printf("\nEnter The File Name : ");
    scanf("%s",ind_fn);
    printf("\nBlocks Allocated Are : \n");
    for(i=1;i<=ind_pos;i++)
    {
        if(strcmp(IF[i].n,ind_fn)==0)
        {
            printf("\n\t IndexBlock\n");
            printf("\n\t     %d\n",IF[ind_pos].indexblock);
            printf("\t------------");
            for(j=1;j<=IF[ind_pos].len;j++)
            {
                printf("\n\t|    %d\t   |\n",*IF[ind_pos].IB[j]);
            }
            printf("\t------------");

            break;
        }
    }
    if(i==ind_pos+1)
    {
        printf("\n\nNo File Found\n");
    }
}
int ind_BFull()
{
    for(i=1,ind_B=0;i<=ind_pos;i++)
        ind_B=ind_B+IF[i].len;
    if(ind_B>TB-ind_pos-k)
        return 1;
    else
        return 0;
}

//linked memory allocation
void linked()
{
     printf("\n Linked File Allocation \n\n");
     do{
     printf("\n\n1.Allocate\n2.Deallocate\n3.Display\n4.Exit");
     printf("\n\nEnter Your choice : ");
     scanf("%d",&ch);


     switch(ch)
     {
                case 1:
                    lin_pos++;
                    lin_allocate();
                    break;

                case 2:
                    lin_deallocate();
                    break;

                case 3:
                    lin_display();
                    break;

                case 4:
                    exit(0);

                default:
                    printf("\nInvalid Choice ");
        }
     }while(ch!=4);

}
void lin_allocate()
{
   printf("\nEnter File Name : ");
   scanf("%s",&(LF[lin_pos].n));
   printf("\nEnter File Length : ");
   scanf("%d",&(LF[lin_pos].len));
   LF[lin_pos].Start=NULL;
   if(lin_BFull())
   {
        lin_pos--;
       printf("\n\nNo Enough Free Space Available \n");
       return;
   }

   for(i=1;i<=LF[lin_pos].len;i++)
   {
        LF[lin_pos].newnode=(struct Link::node *)malloc(sizeof(struct Link::node));

        while(1)
        {

            lin_r=rand()%TB+1;
            if(lin_Table[lin_r]==0)
            {
                    LF[lin_pos].newnode->index =lin_r;
                    LF[lin_pos].newnode->next=NULL;
                    if(LF[lin_pos].Start==NULL)
                    {
                        LF[lin_pos].Start=LF[lin_pos].newnode;
                        LF[lin_pos].current=LF[lin_pos].newnode;
                    }
                    else
                    {
                        LF[lin_pos].current->next=LF[lin_pos].newnode;
                        LF[lin_pos].current=LF[lin_pos].newnode;
                    }

                    lin_Table[lin_r]=1;
                    break;
            }
        }
    }
    LF[lin_pos].st=LF[lin_pos].Start->index;
    for(i=lin_r;i<lin_r+LF[lin_pos].len;i++)
        lin_Table[i]=1;
    printf("\n\tFile Allocation Table\n");
    printf("\nFileName\tStart\tEnd\tLength\n");
    for(i=1;i<=lin_pos;i++)
    {
        printf("\n%s\t\t%d\t%d\t%d",LF[i].n,LF[i].st,LF[lin_pos].current->index,LF[i].len);
        printf("\n");
    }

}
void lin_deallocate()
{
   printf("\nEnter The File Name : ");
   scanf("%s",&lin_fn);
   for(i=1;i<=lin_pos;i++)
   {
            if(strcmp(LF[i].n,lin_fn)==0)
            {
                LF[i].current=LF[i].Start;
                while(LF[i].current)
                {
                    lin_Table[LF[i].current->index]=0;
                    LF[i].temp=LF[i].current;
                    LF[i].current=LF[i].current->next;
                    free(LF[i].temp);
                }

                strcpy(LF[i].n,"NULL");
                LF[i].st=0;
                LF[i].len=0;
                printf("\nFile (%s) Deleted Successfully \n",lin_fn);
                break;
            }
            else
                printf("\nDeletion Unsuccessful\n");
    }
    printf("\n\t\tFile Allocation Table\n");
    printf("\nFileName\tStart\tLength\n");
    for(i=1;i<=lin_pos;i++)
    {
        printf("\n%s\t\t%d\t%d",LF[i].n,LF[i].st,LF[i].len);
        printf("\n");
    }
}
void lin_display()
{
    printf("\nEnter The File Name : ");
    scanf("%s",lin_fn);
    printf("\nBlocks Allocated Are : ");
    for(i=1;i<=lin_pos;i++)
    {
        if(strcmp(LF[i].n,lin_fn)==0)
        {
            LF[i].current=LF[i].Start;
            while(LF[i].current)
            {
               printf(">--%d-->",LF[i].current->index);
               LF[i].current=LF[i].current->next;
            }
            break;
        }
    }
    if(i==lin_pos+1)
    {
        printf("\n\nNo File Found\n");
    }
}
int lin_BFull()
{
    for(i=1,lin_B=0;i<=lin_pos;i++)
        lin_B=lin_B+LF[i].len;
    if(lin_B>TB)
        return 1;
    else
        return 0;
}

int main()
{
	int cho;
		printf("1.Contigious memory allocation\n2.Indexed memory allocation\n3.Linked memory allocation\n4.Exit\n");
		scanf("%d",&cho);
		switch(cho)
		{
			case 1:{
				conti();
				break;
			}
			case 2:{
				ind();
				break;
			}
			case 3:{
				linked();
				break;
			}
			case 4:{
				exit(0);
				break;
			}
			default :{
				printf("Wrong choice");
				break;
			}
		}
}


















