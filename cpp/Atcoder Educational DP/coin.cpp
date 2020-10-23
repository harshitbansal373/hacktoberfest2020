#include <bits/stdc++.h>
using namespace std;

#define fo(i, n) for(int i=0; i<n; i++)
#define Fo(i, k, n) for(int i=k; i<n; i++)

int main() {

	int n;
	cin >> n;
	long double dp[n + 2] = {0}, p;
	dp[1] = 1;

	fo(i, n) {
		cin >> p;
		for (int j = i + 2; j > 0; j--) {
			dp[j] = dp[j] * (1 - p) + dp[j - 1] * p;
		}
	}

	p = 0;
	Fo(i, n / 2 + 2, n + 2) p += dp[i];

	cout << setprecision(10) << p;

	return 0;
}