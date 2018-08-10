#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
//BOJ #2637

int adj[101][101];
int out[101];
int ret[101];
int n, m;
void dfs(int here, int cnt) {
	ret[here] += cnt;
	for (int i = 1; i <= n; i++) {
		if (adj[here][i]) {
			dfs(i, cnt*adj[here][i]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	int x, y, k;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> k;
		adj[x][y] = k;
		out[x]++;
	}
	dfs(n, 1);
	for (int i = 1; i <= n; i++) {
		if (out[i] == 0) {
			cout << i << ' ' << ret[i] << '\n';
		}
	}
}
