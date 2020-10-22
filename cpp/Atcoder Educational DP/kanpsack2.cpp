#include <bits/stdc++.h>
using namespace std;

#define fo(i, n) for(long i=0; i<n; i++)
#define Fo(i, k, n) for(long i=k; i<n; i++)
#define endl "\n"

int main() {

	long long total = 0;
	long n, w, temp1, temp2;
	cin >> n >> w;

	vector<pair<long, long>> item;
	fo(i, n) {
		cin >> temp1 >> temp2;
		item.push_back(make_pair(temp1, temp2));
		total += temp2;
	}

	long dp[n + 1][total + 1];
	fo(i, n + 1) fo(j, total + 1) dp[i][j] = 0;

	Fo(i, 1, n + 1) {
		Fo(j, 1, total + 1) {
			temp1 = item[i - 1].second;
			if (j >= temp1) {
				if (dp[i - 1][j] == 0) {
					dp[i][j] = item[i - 1].first + dp[i - 1][j - temp1];
				} else {
					dp[i][j] = min(dp[i - 1][j], item[i - 1].second + dp[i - 1][j - temp1]);
				}
			} else {
				dp[i][j] = dp[i - 1][j];
			}
			if (dp[i][j] != 0 && dp[i][j] <= w && temp2 <= j) {
				temp1 = dp[i][j];
				temp2 = j;
			}
		}
	}

	// cout << dp[n][total];
	cout << temp2;

	return 0;
}