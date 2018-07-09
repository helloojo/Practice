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
//BOJ #15783

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int here) {
	if (visited[here]) {
		return;
	}
	visited[here] = true;
	for (int i = 0; i < adj[here].size(); i++) {
		dfs(adj[here][i]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	int a, b;
	adj = vector<vector<int>>(n);
	visited = vector<bool>(n);
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
	}
	int ret = 0;
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			dfs(i);
			ret++;
		}
	}
	cout << ret;
}
