#include<iostream>
#include<vector>

using namespace std;

vector<pair<int,int>> prime_factorization(int x) // caculates the prime factorization of x
{
    int i = 0, j = 2;
    vector<pair<int,int>> factors;
    factors.push_back({j,0});
    while(j <= x)
    {
        if((x % j) == 0 )
        {
            factors[i].second ++ ;
            x /= j;
        }
        else {
            j ++;
            if(factors[i].second > 0)
            {
                factors.push_back({j,0});
                i ++;
            }
            else factors[i].first = j;
        }
    }
    return factors; // contaions vector of {prime_factor,power}, which is present in the prime factorization of x
}
int main()
{
    int n;
    cout<<"Enter the no. to calculate it's prime factorization :- ";
    cin >> n; // input of integer
    vector<pair<int,int>> ans; 
    ans = prime_factorization(n); 
    int s = ans.size();
    cout<<n<<" = ";
    for(int i = 0; i < s; i++) // prints the prime factorization in nicely fomatted way....
    {
        printf("(%d ^ %d)",ans[i].first,ans[i].second);
        if(i == s-1) cout<<endl;
        else cout<<" * ";
    }
    return 0;
}