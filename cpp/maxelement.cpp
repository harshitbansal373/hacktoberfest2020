#include<iostream>
using namespace std;

int main() {
    cout<<"Enter the number of elements\n"; int n;
    cin>>n;
    int arr[n];
    cout<<"enter "<<n<<" the elements\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
        
    }
    int max; int temp;
    max=arr[0];
    for(int i=0;i<n;i++){
        if(max<arr[i])
        {max=arr[i];
            temp=i;
        }
    }
    cout<<"The largest element is "<<max<<" at "<<temp<<" position";
	return 0;
}
