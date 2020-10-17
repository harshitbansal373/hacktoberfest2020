#include <bits/stdc++.h>

#define INF 1000000000
#define MOD 1000000007
#define MAXN 1000005
#define ins insert
#define pb push_back
#define mp make_pair
#define sz size
#define rep(i, n) for(int i = 0; i < n; ++i)
#define sd(n) scanf("%d",&n)
#define sll(n) scanf("%I64d",&n)
#define pdn(n) printf("%d\n",n)
#define plln(n) printf("%I64d\n",n)
#define pd(n) printf("%d ",n)
#define nl() printf("\n")
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vi;
typedef vector<vi> vii;
typedef pair<int, int> pii;

int budget, parties;

int fun[101], fee[101];

int dp[101][501];

int solve(int idx, int rembudget) {
	if(rembudget == 0)
		return 0;
	if(rembudget < 0)
		-INF;
	if(idx == 0) {
		if(rembudget >= 0)
			return 0;
		return -INF;
	}
	if(dp[idx][rembudget] != -1)
		return dp[idx][rembudget];
	return dp[idx][rembudget] = max(solve(idx-1, rembudget), fun[idx]+solve(idx-1, rembudget-fee[idx]));
}

int main() {
	while((cin >> budget >> parties) && (budget) && (parties)) {
		for(int i = 0; i < 101; ++i)
			for(int j = 0; j < 501; ++j)
				dp[i][j] = -1;
		for(int i = 0; i < parties; ++i) {
			cin >> fee[i] >> fun[i];
		}
		for(int i = 0; i < 501; ++i)
			solve(parties-1, i);
		int ans = solve(parties-1, budget);
		int currmin = INF;
		for(int i = 0; i < 501; ++i) {
			if(dp[parties-1][i] == ans) {
					currmin = i;
					break;
			}
		}
		cout << currmin << " " << ans << endl;
	}
	return 0;	
}	
