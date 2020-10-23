#include <bits/stdc++.h>
using namespace std;

#define fo(i, n) for(int i=0; i<n; i++)
#define endl "\n"

int main() {

	int n;
	cin >> n;

	long arr[n][3], dp[n][3];
	fo(i, n) fo(j, 3) cin >> arr[i][j];

	fo(i, n) {
		if (i == 0) {
			dp[i][0] = arr[i][0];
			dp[i][1] = arr[i][1];
			dp[i][2] = arr[i][2];
		} else {
			dp[i][0] = arr[i][0] + max(dp[i - 1][1], dp[i - 1][2]);
			dp[i][1] = arr[i][1] + max(dp[i - 1][2], dp[i - 1][0]);
			dp[i][2] = arr[i][2] + max(dp[i - 1][0], dp[i - 1][1]);
		}
	}

	cout << max(dp[n - 1][1], max(dp[n - 1][0], dp[n - 1][2]));

	return 0;
}