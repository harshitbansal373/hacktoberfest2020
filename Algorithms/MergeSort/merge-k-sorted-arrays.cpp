// function should return an pointer to output array int*
// of size k*k
int *mergeKArrays(int arr[][N], int k){

    // allot space for storing the sorted elements
    int *A = new int[k*k];
    int k1=0;
    
    // make a min heap of size k of value and their corresponding position which is represented by pair of pair
    priority_queue< pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > q;
    
    // just put the first element of each row inside the heap as the rows are sorted so we have the smallest of all as a root of the tree
    for(int i=0;i<k;i++){
        q.push({arr[i][0],{i,0}});
    }
    
    // pop the root element and put it inside the ans array and if there is any element left in that particular row
    // push the next element of the popped element inside the heap and repeat the same
    // if there is no element in that row do nothing
    while(!q.empty()){
        int a = q.top().first;
        pair<int, int> r = q.top().second;
        q.pop();
        A[k1]=a;
        k1+=1;
        if(r.second+1<k){
            q.push({arr[r.first][r.second+1], {r.first, r.second+1}});
        }
    }
    return A;
}
