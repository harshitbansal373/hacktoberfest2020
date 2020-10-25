#include <bits/stdc++.h>
using namespace std;

#define fo(i, n) for(int i=0; i<n; i++)

int arr[105];
bool winner[100005];

int main() {

	int n, k;
	scanf("%d %d", &n, &k);

	fo(i, n) scanf("%d", &arr[i]);

	fo(i, k) if (!winner[i])
		fo(j, n) if (i + arr[j] <= k)
			winner[i + arr[j]] = true;

	cout << (winner[k] ? "First" : "Second");

	return 0;
}