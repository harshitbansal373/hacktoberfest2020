#include <bits/stdc++.h>
using namespace std;

#define fo(i, n) for(int i=0; i<n; i++)
#define endl "\n"

int main() {

	int n, k, var;
	cin >> n >> k;

	long arr[n], temp[n], mi;
	fo(i, n) cin >> arr[i];

	fo(i, n) {
		var = i - 1;
		mi = INT_MAX;
		while (var >= 0 && var >= i - k) {
			mi = min(abs(arr[i] - arr[var]) + temp[var], mi);
			var--;
		}
		temp[i] = mi == INT_MAX ? 0 : mi;
	}

	cout << temp[n - 1];
	return 1;
}