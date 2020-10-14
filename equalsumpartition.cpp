#include<bits/stdc++.h>
using namespace std;

bool isequalpartition(int set[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum = sum + set[i];
	if (sum % 2 != 0)
		return false;
	bool partition[n + 1][sum / 2 + 1];
	for (int i = 0; i <= sum / 2; i++)
		partition[0][i] = false;
	for (int i = 0; i <= n; i++)
		partition[i][0] = true;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= sum / 2; j++)
		{
			if (set[i - 1] > j)
				partition[i][j] = partition[i - 1][j];
			else
				partition[i][j] = partition[i - 1][j] || partition[i - 1][j - set[i - 1]];
		}
	}
	return partition[n][sum / 2];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int set[n];
		for (int i = 0; i < n; i++)
			cin >> set[i];
		if (isequalpartition(set, n) == true)
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}
	return 0;
}