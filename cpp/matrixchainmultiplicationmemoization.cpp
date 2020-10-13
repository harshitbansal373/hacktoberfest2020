#include <bits/stdc++.h>
using namespace std;

int t[1001][1001];
int mcm(int arr[], int i, int j)
{
	if (i >= j)
		return 0;
	if (t[i][j] != -1)
		return t[i][j];
	int mn = INT_MAX;
	for (int k = i; k <= j - 1; k++)
	{
		int temp = mcm(arr, i, k) + mcm(arr, k + 1, j) + (arr[i - 1] * arr[k] * arr[j]);
		if (temp < mn)
			mn = temp;
	}
	return t[i][j] = mn;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	memset(t, -1, sizeof(t));
	cout << mcm(arr, 1, n - 1);
	return 0;
}