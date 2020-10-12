#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int array[5]={9,2,3,4,1};

    InsertionSort(array,5);

    for(i=0;i<5;i++)
    {
        printf("%d ",array[i]);
    }

    return 0;
}

void InsertionSort(int arr[],int size)
{
    int x,temp,k;

    for(x=1;x<size;x++)
    {
        temp=arr[x];

        for(k=x;k>0 && temp<arr[k-1];k--)
        {
            arr[k]=arr[k-1];
        }
        arr[k]=temp;
    }
}