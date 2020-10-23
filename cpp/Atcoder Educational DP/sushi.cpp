#include <bits/stdc++.h>
using namespace std;

#define fo(i, n) for(int i=0; i<n; i++)
#define Fo(i, k, n) for(int i=k; i<n; i++)
#define endl "\n"

int n, val[4];
double dp[305][305][305];

double dfs(int a, int b, int c) {
	if (a == 0 && b == 0 && c == 0) return 0.0;
	else if (dp[a][b][c]) return dp[a][b][c];
	double ans = (double)n / (a + b + c);
	if (a) ans += (double)a / (a + b + c) * dfs(a - 1, b, c);
	if (b) ans += (double)b / (a + b + c) * dfs(a + 1, b - 1, c);
	if (c) ans += (double)c / (a + b + c) * dfs(a, b + 1, c - 1);
	return dp[a][b][c] = ans;
}

int main() {

	int temp;
	cin >> n;
	fo(i, n) {
		cin >> temp;
		val[temp]++;
	}

	cout << setprecision(14) << dfs(val[1], val[2], val[3]);

	return 0;
}