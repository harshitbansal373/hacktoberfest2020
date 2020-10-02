//repeated element in the array
//TC:o(nlogn)
//SC:o(1)

#include<bits/stdc++.h>
using namespace std;

int main() {
	int arr[]={1,5,2,9,2,6,4};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	sort(arr,arr+n);
	
	for(int i=0;i<n;i++) {
		if(arr[i]==arr[i+1]) {
			cout<<arr[i]<<endl;
		}
	}
	
	return 0;
}
