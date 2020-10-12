void heapify(int A[], int n, int root){
    int l = 2*root + 1;
    int r = l+1;
    int i = root;
    
    if(l<n && A[i] > A[l]){
        i=l;
    }
    if(r<n && A[i] > A[r]){
        i=r;
    }
    
    if(A[i] < A[root]){
        swap(A[i], A[root]);
        heapify(A,n,i);
    }
}

void buildHeap(int A[], int k){
    for(int i=(k/2)-1;i>=0;i--){
        heapify(A,k,i);
    }
}

int KthLargest(int arr[], int n, int k) {

    // build a min heap of size k
    int A[k];
    for(int i=0;i<k;i++){
        A[i] = arr[i];
    }
    buildHeap(A,k);
    int i=k;
    
    // starting from the kth element to nth element check if root element is smaller than the upcomming element
    // it is smaller than it can't contribute in kth largest element so replace root with the upcomming element
    // and heapify the tree
    while(i<n){
        if(arr[i]>A[0]){
            A[0] = arr[i];
            heapify(A,k,0);
        }
        i+=1;
    }
    
    // as root is the smallest of all the elements is the tree which of size k so it will be our kth largest element
    return A[0];
}
