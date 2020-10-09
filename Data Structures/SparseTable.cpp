//Range minimum query using Sparse Table in constant time O(1) per query. Implemented in C++17
//Author : github.com/yadavnaman
#include <bits/stdc++.h>
#define K 25
#define int long long
using namespace std;
const int MAXN = 1e5 + 10;
int log[MAXN];
int st[MAXN][K+1];
int array[MAXN];
int N,q; //N is the size of array, q is the number of queries
int L,R; // the lower and upper bounds of the RMQ
void lg() {
	// pre-calculate log of all possible values
	log[1] = 0;
	for (int i = 2; i <= MAXN; i++)
	    log[i] = log[i/2] + 1;

}
void build() {
	for (int i = 0; i < N; i++)
	    st[i][0] = array[i];

	for (int j = 1; j <= K; j++)
	    for (int i = 0; i + (1 << j) <= N; i++)
	        st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);

  	//time for precomputation is(NlogN)
}

void solve() {
	cin >> N >> q;
	for(int i = 0; i < N; ++i) {
		cin >> array[i];
	}
	lg();
	build();
	while(q--) {
		cin >> L >> R;
		int j = log[R- L + 1];
		cout << min(st[L][j], st[R - (1 << j) + 1][j]);
	}
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
}
