#include <bits/stdc++.h>
using namespace std;

#define fo(i, n) for(int i=0; i<n; i++)
#define Fo(i, k, n) for(int i=k; i<n; i++)
#define endl "\n"

int main() {

	int n, w, temp1, temp2;
	cin >> n >> w;

	long dp[n + 1][w + 1];
	fo(i, n + 1) fo(j, w + 1) dp[i][j] = 0;

	vector<pair<int, int>> item;
	fo(i, n) {
		cin >> temp1 >> temp2;
		item.push_back(make_pair(temp1, temp2));
	}

	Fo(i, 1, n + 1) {
		Fo(j, 1, w + 1) {
			temp1 = item[i - 1].first;
			if (j >= temp1) {
				dp[i][j] = max(dp[i - 1][j], item[i - 1].second + dp[i - 1][j - temp1]);
			} else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	cout << dp[n][w];
	// fo(i, n + 1) {
	// 	fo(j, w + 1) cout << dp[i][j] << " ";
	// 	cout << endl;
	// }

	return 0;
}