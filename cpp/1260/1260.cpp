#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
//BOJ #1260

vector<vector<int>> adj;
int visited[1001];
queue<int> q;

void dfs(int here) {
	if (visited[here]) return;
	cout << here << ' ';
	visited[here] = true;
	int si = adj[here].size();
	for (int i = 0; i < si; i++) {
		dfs(adj[here][i]);
	}
}
void bfs(int here) {
	q.push(here);
	visited[here] = true;
	while (!q.empty()) {
		int p = q.front();
		q.pop();
		cout << p << ' ';
		int si = adj[p].size();
		for (int i = 0; i < si; i++) {
			int next = adj[p][i];
			if (visited[next]) continue;
			visited[next] = true;
			q.push(next);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	int m;
	int v;
	cin >> n >> m >> v;
	int a, b;
	adj = vector <vector<int>>(n + 1);
	while (m--) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		sort(adj[i].begin(), adj[i].end());
	}
	dfs(v);
	memset(visited, 0, sizeof(visited));
	cout << '\n';
	bfs(v);
}