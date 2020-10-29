#include<bits/stdc++.h>
#define lli long long int
#define floop(a,b,c) for(lli a = b; a < c; a++)
using namespace std;
int main(){
  lli n;
  cin >> n;
  floop(i,0,n){
    lli m;
    cin >> m;
    lli input[m];
    lli count = 0;
    floop(j,0,m){
      cin >> input[j];
      if(input[j] == 0){
        input[j]++;
        count++;
      }
    }
    lli sum = 0;
    floop(j,0,m) sum += input[j];
    if(sum == 0){
      floop(j,0,m){
        if(input[j] < 0) {
          input[j]++;
          count++;
          break;
        }
      }
    }
    cout << count << endl;
  }
}
