#include<stdio.h>













void heapify(int arr[],int n, int i)
{
	int q;
	int largest=i;
	int left=2*i+1;
	int right= 2*i+2;
	
	
	
	if(left<n && arr[left]>arr[largest])
	{
		largest=left;
	}
	
	
	if(right<n && arr[right]>arr[largest])
	{
		largest=right;
	}
	
	if(largest!=i)
	{
		q=arr[i];
		arr[i]=arr[largest];
		arr[largest]=q;
		heapify(arr,n, largest);
	}
	
	
}



void heapsort(int arr[],int n)
{
	int i,q;
	
	
	
	for(i=(n/2)-1;i>=0;i--)
	{
		
		heapify(arr,n,i);
	}
	
	for(i=n-1;i>0;i--)
	{

		q=arr[0];
		arr[0]=arr[i];
		arr[i]=q;
		heapify(arr,i,0);
	}
	
	
}




void print(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	
	printf("\n");
}



int main()
{
	int arr[200000];
	
	int n,i;
	printf("Enter the size of array:");
	scanf("%d",&n);
	
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	

	
	heapsort(arr,n);



	print(arr,n);
}


