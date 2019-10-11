#include<iostream>
using namespace std;
int search(int arr[],int l,int r,int x){
	if(r>=l){
		int mid=l+r/2;
		if(arr[mid]==x)
			return mid;
		if(arr[mid]>=x)
			return search(arr,l,mid-1,x);
		return search(arr,mid+1,r,x);
	}
	return -1;

}
int main(){
	int arr[]={1,2,3,4,5,6,7};
	int l=0,i,x;
	int n=sizeof(arr)/sizeof(arr[0]);
//	for(i=0;i<n;i++)
//		cout<<arr[i]<<"\t";
	cout<<"Enter number to search:\n";
	cin>>x;
	i=search(arr,l,n,x);
	if(i==-1)
		cout<<"Not found\n";
	else
		cout<<"found at position "<<i<<endl;
	return 0;
}
