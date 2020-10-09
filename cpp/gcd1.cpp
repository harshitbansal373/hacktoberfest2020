#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    if (b == 0) 
    return a; 
    
    gcd(b,a%b);
}
int main()
 {
     int a[] = {2, 3, 60, 90, 50};
    int n = sizeof(a)/sizeof(a[0]); 
    int l = 0; 
    int r = 1; 
    int temp;
    for(int i=l;i<r;i++)
    {
         temp = gcd(a[i],a[i+1]);
    }
     cout<<temp;
     
	return 0;
 }
