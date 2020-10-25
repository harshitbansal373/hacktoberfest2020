#include <bits/stdc++.h>
using namespace std;

#define fo(i, n) for(int i=0; i<n; i++)
#define Fo(i, k, n) for(int i=k; i<n; i++)
#define endl "\n"

int main() {

	int n;
	cin >> n;

	long arr[n], temp[n];
	fo(i, n) cin >> arr[i];

	temp[0] = 0;
	temp[1] = abs(arr[0] - arr[1]);

	Fo(i, 2, n)
	temp[i] = min(abs(arr[i] - arr[i - 1]) + temp[i - 1], abs(arr[i] - arr[i - 2]) + temp[i - 2]);

	cout << temp[n - 1];
}