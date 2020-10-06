#include<iostream>
#include<algorithm>
#include<vector>

using namespace std ;

int numberOfCoins (vector<int> v , int n) {
    int ans = INT_MAX ;
    if(n==0){
        return 0 ;
    }
        
    for(int i = 0 ; i < v.size() ; i++){
        if(n-v[i]>=0){   
            int sub = numberOfCoins(v,n-v[i]) ;
            if(sub != ans && sub + 1 < ans) {
               ans = sub + 1 ;
            }
        }
    }
    
    return ans ;
}

int main(int argc, char const *argv[])
{
    vector<int> v = {1,5,6,9,11} ;
    int ans = numberOfCoins(v,22) ;
    cout << ans ;
    return 0;
}
