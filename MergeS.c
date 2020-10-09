#include <stdio.h>
#include <stdlib.h>

void msort(int d[],int size)
{
    int i,j,k, result[size],mid=size/2;
    if(size==1)
        return;     // nothing to do, already sorted
    msort(d,mid);           // sort first half of d[]
    msort(&d[mid],size-mid);// sort 2nd half of d[]

    for(k=0,i=0,j=mid;i<mid && j<size;k++)
    {
        result[k]=d[i]<d[j]?d[i++]:d[j++];
    }

    while(i<mid)
    {
        result[k++]=d[i++]; //swap first half
    }
    while(j<size)
    {
        result[k++]=d[j++]; //swap second half
    }

    for(k=0;k<size;k++)
    {
        d[k]=result[k];
    }
}

void main(){
int i, a[]={1,23,45,67,3};
msort(a,5);
printf("\n"); for(i=0;i<5;i++) printf("%d\t",a[i]);

}