#include<bits/stdc++.h>
#define lli long long int
#define floop(a,b,c) for(lli a = b; a < c; a++)
using namespace std;
int main(){
  lli n;
  cin >> n;
  floop(i,0,n){
    lli input;
    cin >> input;
    lli digit = input%10;
    lli count = 0;
    while(input != 0){
      count++;
      input/=10;
    }
    if(count == 1) cout << digit*10 - 9 << endl;
    if(count == 2) cout << digit*10 - 7 << endl;
    if(count == 3) cout << digit*10 - 4 << endl;
    if(count == 4) cout << digit*10 << endl;
  }
  return 0;
}
