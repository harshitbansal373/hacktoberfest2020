#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int r) {
    int nl = m - l + 1;
    int nr = r - m;
    int larr[nl], rarr[nr];
    for (int i = 0; i < nl; i++) {
        larr[i] = arr[l + i];
    }
    for (int j = 0; j < nr; j++) {
        rarr[j] = arr[m + 1 + j];
    }
    int i = 0;
    int j = 0;
    int k = l;
    while (i < nl && j < nr) {
        if (larr[i] <= rarr[j]) {
            arr[k] = larr[i];
            i++;
        }
        else {
            arr[k] = rarr[j];
            j++;
        }
        k++;
    }
    while (i < nl) {
        arr[k] = larr[i];
        i++;
        k++;
    }
    while (j < nr) {
        arr[k] = rarr[j];
        j++;
        k++;
    }
}

void MergeSort(int arr[], int l, int r) {
    int m = l + ((r - l) / 2);
    if (l < r) {
        MergeSort(arr, l, m);
        MergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main(int argc, char* argv[]) {
    freopen(argv[1], "r", stdin);
    freopen("mergesort.txt", "w", stdout);
    vector <int> v ;
    int s;
    while (cin>>s) {
        v.push_back(s);
    }
    int n = v.size();
    int arr[n];
    for(int i = 0; i < n; i++){
        arr[i] = v[i];
    }
    MergeSort(arr, 0, n - 1);
    for (int i = 0; i < n-1; i++) {
        cout << arr[i] << endl;
    }
    cout<<arr[n-1];
    return 0;
}
