#include <bits/stdc++.h>
using namespace std;

#define fo(i, n) for(int i=0; i<n; i++)
#define Fo(i, k, n) for(int i=k; i<n; i++)
#define endl "\n"

int main() {

	int t, a, b, n;
	long long arr[105][105][50];
	cin >> t >> a >> b;
	arr[a + 2][b + 2][0] = 1;
	cin >> a >> b >> n;

	Fo(m, 1, n + 1) {
		Fo(i, 2, t + 2) {
			Fo(j, 2, t + 2) {
				arr[i][j][m] += arr[i - 2][j - 1][m - 1] + arr[i - 2][j + 1][m - 1] + arr[i + 2][j - 1][m - 1] + arr[i + 2][j + 1][m - 1] + arr[i - 1][j - 2][m - 1] + arr[i - 1][j + 2][m - 1] + arr[i + 1][j - 2][m - 1] + arr[i + 1][j + 2][m - 1] + arr[i - 1][j - 1][m - 1] + arr[i - 1][j][m - 1] + arr[i - 1][j + 1][m - 1] + arr[i][j - 1][m - 1] + arr[i][j + 1][m - 1] + arr[i + 1][j - 1][m - 1] + arr[i + 1][j][m - 1] + arr[i + 1][j + 1][m - 1];
			}
		}
	}

	cout << arr[a + 2][b + 2][n];
	return 0;
}