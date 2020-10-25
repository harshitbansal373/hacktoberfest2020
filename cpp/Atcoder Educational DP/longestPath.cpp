#include <bits/stdc++.h>
using namespace std;

#define fo(i, n) for(int i=0; i<n; i++)
#define Fo(i, k, n) for(int i=k; i<n; i++)
#define endl "\n"

const int N = 100005;
bool visited[N];
vector<int> adj[N];
int memo[N];

int traverse(int a) {
	if (visited[a]) return memo[a];
	int ans = 0;
	for (int j : adj[a]) {
		ans = max(ans, 1 + traverse(j));
	}
	visited[a] = true;
	return memo[a] = ans;

}

int main() {

	int e, v, temp1, temp2;
	cin >> v >> e;

	fo(i, e) {
		cin >> temp1 >> temp2;
		adj[temp1].emplace_back(temp2);
	}
	temp2 = 0;

	fo(i, v)
	temp2 = max(temp2, traverse(i + 1));

	cout << temp2;

	return 0;
}