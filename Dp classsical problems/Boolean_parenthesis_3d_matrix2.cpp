#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;


int dp[1001][1001][2];
int bp(string s, int i, int j, bool isTrue)
{
     if(dp[i][j][isTrue]!=-1)
        return dp[i][j][isTrue];
    
    if (i == j)
    {
        if (isTrue == true)
        {
            return dp[i][j][isTrue]=(s[i] == 'T');
        }
        else
        {
            return dp[i][j][isTrue]=(s[i] == 'F');
        }
    }

    if (i > j)
        return dp[i][j][isTrue]=0;

    int ans = 0;
    for (int k = i + 1; k <= j - 1; k += 2)
    {
        int lf,rf,lt,rt;
        if(dp[i][k-1][0]!=-1)
            lf=dp[i][k-1][0];
        else
        {
            lf = bp(s, i, k - 1, false);
            dp[i][k-1][0]=lf;
        }
            
        if(dp[i][k-1][1]!=-1)
            lt=dp[i][k-1][1];
        else
        {
            lt = bp(s, i, k - 1, true);
            dp[i][k-1][1]=lt;
        }
            
        if(dp[k+1][j][1]!=-1)
            rt=dp[k+1][j][1];
        else
        {
            rt = bp(s, k + 1, j, true);
            dp[k+1][j][1]=rt;
        }
            
        if(dp[k+1][j][0]!=-1)
            rf=dp[k+1][j][0];
        else
        {
            rf = bp(s, k + 1, j, false);
            dp[k+1][j][0]=rf;
        }
            // cout<<lf<<" "<<lt<<" "<<rt<<" "<<rf<<endl;
        if (s[k] == '^')
        {
            if (isTrue == true)
                ans += lf * rt + lt * rf;
            else
                ans += lt * rt + lf * rf;
        }
        else if (s[k] == '|')
        {
            if (isTrue == true)
            {
                ans += lt * rf + lt * rt + rt * lf;
            }
            else
            {
                ans += lf * rf;
            }
        }
        else if (s[k] == '&')
        {
            if (isTrue)
            {
                ans += lt * rt;
            }
            else
            {
                ans += lt * rf + lf * rf + rt * lf;
            }
        }
    }
    return dp[i][j][isTrue]=ans % 1003;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        memset(dp,-1,sizeof(dp));
        string s;
        cin >> s;
        cout << bp(s, 0, s.size() - 1, true);
        cout << endl;
    }
    return 0;
}
