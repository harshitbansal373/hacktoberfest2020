#include <bits/stdc++.h>
using namespace std;

#define fo(i, n) for(int i=0; i<n; i++)
#define Fo(i, k, n) for(int i=k; i<n; i++)
#define endl "\n"

int dp[3002][3002];

int main() {

	string a, b;
	cin >> a >> b;

	int al = a.length(), bl = b.length(), find;
	fo(i, al + 1) fo(j, bl + 1) dp[i][j] = 0;

	Fo(i, 1, al + 1)
	Fo(j, 1, bl + 1) {
		dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		if (a[i - 1] == b[j - 1]) {
			dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
		}
	}

	find = dp[al][bl];
	int i = al, j = bl;
	char ans[find + 1];
	ans[find] = '\0';

	while (i > 0 && j > 0) {
		if (a[i - 1] == b[j - 1]) {
			ans[find - 1] = a[i - 1];
			find--;
			j--;
			i--;
		} else if (dp[i - 1][j] < dp[i][j - 1]) {
			j--;
		} else {
			i--;
		}
	}

	cout << ans;

	return 0;
}