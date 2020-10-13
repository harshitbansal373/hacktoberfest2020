#include <bits/stdc++.h> 
using namespace __gnu_pbds;
typedef long int ll; 
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
    return a * b / gcd(a, b);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b;
    cin>>a>>b;
    cout<<"GCD="<<gcd(a,b)<<"\n";
    cout<<"LCM="<<lcm(a,b)<<"\n";
    
}
