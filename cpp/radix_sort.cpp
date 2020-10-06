#include<bits/stdc++.h>
using namespace std;

//Count sort algorithm for sorting
void countsort(long long int arr[],long long int n,long long int divi){
    long long int output[n];
    long long int i, cnt[10]={0};
    // counting the occurance of each of the 10 digits and storing in cnt
    for(i=0;i<n;i++){
        cnt[(arr[i]/divi)% 10]++ ;
    }
    //storing the position of each digit in the cnt array
    for(i=1;i<10;i++){
        cnt[i]=cnt[i]+cnt[i-1];
    }
    //storing the digits in output array
    for(i=n-1;i>=0;i--){
        output[cnt[(arr[i]/divi)%10]-1]=arr[i];
        cnt[(arr[i]/divi)%10]--;
    }
    //copying the elements from output to arr
    for(i=0;i<n;i++){
        arr[i]=output[i];
    }
}

//radix sort
void radixsort(long long int arr[],long long int n, int d){
    //carrying out count sort for each set of significant digits
    for(int div=0;div<d;div +=1){
        countsort(arr,n,pow(10,div));
    }
}

int main(int argc, char* argv[]) {
    freopen(argv[1], "r", stdin);
    freopen("radix.txt", "w", stdout);
    vector <long long int> v ;
    long long int s;
    int d=int(argv[2]);
    while (cin>>s) {
        v.push_back(s);
    }
    long long int n = v.size();
    long long int arr[n];
    for(long long int i = 0; i < n; i++){
        arr[i] = v[i];
    }
    radixsort(arr, n, 6);
    for (long long int i = 0; i < n-1; i++) {
        cout << arr[i] << endl;
    }
    cout<<arr[n-1];
    return 0;
}
