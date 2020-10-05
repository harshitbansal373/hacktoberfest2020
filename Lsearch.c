#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int linear_search(int data[],int size,int key);

int linear_search(int data[],int size,int key)
{
    int found=0;            //flag to indicate whether the value is found or not
    int position=-1;        //to record the position of search value
    int index=0;

    while (index < size  && !found)

	{
		if(data[index]==key)

   			{
				found = 1;
                position = index;
				break;
			}
		 	index++;
	}
	return position;
}


int main()
{
    int d[]={10,5,2,83,4,5,61,17,8,29};
    int key;
    int x;
    printf("Your array elements are as follows:\n\n");

    for(x=0;x<10;x++)
    {
                printf("%d  ",d[x]);
    }
    while(1)
	{
        printf("\n\n Enter a number to search: ");
        scanf("%d",&key);
        printf("\nThe index is %d\n",linear_search(d,10,key));
   	 }
}


