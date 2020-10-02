//find repeating and missing number
//tc:o(n)

#include<bits/stdc++.h>
using namespace std;

int main() {
	int arr[]={1,3,4,3,6,7};
	int n=sizeof(arr)/sizeof(arr[0]);
	int repeating,missing;
	bool present[n]={false};
	for(int i=0;i<n;i++) {
		if(present[arr[i]]==true) {
			repeating=arr[i];
		}
		present[arr[i]]=true;
	}
	for(int i=1;i<n;i++) {
		if(present[i]==false){
			missing=i;
			break;
		}
	}
	cout<<repeating<<" "<<missing;
	
	return 0;
}
