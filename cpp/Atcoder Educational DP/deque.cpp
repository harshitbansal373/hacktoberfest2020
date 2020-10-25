#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fo(i, n) for(i=0; i<n; i++)
#define Fo(i, k, n) for(i=k; i<n; i++)

int main() {

	int n, i, j;
	cin >> n;
	ll dp[n], a[n];
	fo(i, n) cin >> a[i], dp[i] = a[i];
	Fo(i, 1, n) fo(j, (n - i)) dp[j] = max(a[i + j] - dp[j], a[j] - dp[j + 1]);
	cout << dp[0];

	return 0;
}