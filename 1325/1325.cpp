#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
//BOJ #1325
vector<vector<int>> adj;
bool visited[10001];
int ret[10001];
queue<int> q;
int bfs(int here) {
	int ret = 1;
	q.push(here);
	visited[here] = true;
	while (!q.empty()) {
		int p = q.front();
		q.pop();
		int si = adj[p].size();
		for (int i = 0; i < si; i++) {
			int next = adj[p][i];
			if (visited[next]) continue;
			visited[next] = true;
			q.push(next);
			ret++;
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	adj = vector<vector<int>>(n + 1);
	int a, b;
	while (m--) {
		cin >> a >> b;
		adj[b].push_back(a);
	}
	int maxret = -1;
	for (int i = 1; i <= n; i++) {
		memset(visited, 0, sizeof(visited));
		ret[i] = bfs(i);
		//cout << ret[i] << endl;
		maxret = max(maxret, ret[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (maxret == ret[i]) {
			cout << i << ' ';
		}
	}
}