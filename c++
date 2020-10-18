#include<iostream>
using namespace std;
int bina(int arr[],int x,int count)
{
	int left =0;
	int right=count-1;
	while(left<=right)
	{
		int mid=(left+right)/2;
		if(arr[mid]==x)
			{
				return mid;
			}
		
			else if (arr[mid]<x)
			{
				left=mid+1;
			}	
			else
			{
				right=mid-1;
			}
	}		
return -1;
}



int main()
{ int x,arr[100],output,item;
	cout<<"enter the no of elements";
	cin>>x;
	cout<<"enter the sorted elements";
	for(int i=0;i<x;i++)
	{
		cin>>arr[i];
	}
	cout<<"enter the item to search";
	cin>>item;
	output=bina(arr,item,x);
	if(output==-1)
	{
		cout<<"element not found";
	}
	else
	{
		cout<<"element found at"<<output<<endl;
	}	
	return 0;
}
