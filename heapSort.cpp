/*  
    Consider an array 'arr' which is to be sorted using Heap Sort.

    a) Initially build a max heap of elements in 'arr'.
    b) The root element, that is arr[0], will contain maximum 
       element of arr. After that, swap this element with the 
       last element of arr and heapify the max heap excluding the 
       last element which is already in its correct position and 
       then decrease the length of heap by one.
    c) Repeat the step 2, until all the elements are in their correct position.

    Time complexity: O(n + n*logn) = O(n*logn)
*/

#include<bits/stdc++.h>
using namespace std;

// Auxiliary Functions
void printArray(int arr[], int n) { 
    for (int i=0; i<n; ++i) 
        cout << arr[i] << " "; 
    cout << "\n"; 
} 

// Main logic
void heapify (int arr[], int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l<n && arr[l]>arr[largest])
        largest = l;
    
    if (r<n && arr[r]>arr[largest])
        largest = r;

    if (largest != i) {
        swap (arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort (int arr[], int n) {
    for (int i = n/2-1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n-1; i>=0; i--) {
        swap (arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

/* -------------- MAIN DRIVER CODE ----------------- */
int main() 
{ 
    int arr[] = {12, 11, 13, 5, 6, 7}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    heapSort(arr, n); 
  
    cout << "Sorted array is: \n"; 
    printArray(arr, n); 
} 