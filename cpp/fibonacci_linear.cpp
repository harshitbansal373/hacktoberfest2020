#include<bits/stdc++.h>
using namespace std;
int fib(int n){
	int a=0,b=1,i=2,ans=0;
	while(i<n){
		ans = a + b;
		a = b;
		b = ans;
		i++;
	}
	return ans;
}
int main(){
	int n=6;
	cout<<fib(n);
	return 0;
}