#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
//BOJ #1967

vector<vector<pair<int, int>>> adj;
bool visited[10001];
queue<pair<int, int>> q;

int bfs(int src) {
	q.push(make_pair(src, 0));
	visited[src] = true;
	int ret = 0;
	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		ret = max(ret, p.second);
		for (int i = 0; i < adj[p.first].size(); i++) {
			int next = adj[p.first][i].first;
			int dis = adj[p.first][i].second + p.second;
			if (visited[next]) {
				continue;
			}
			visited[next] = true;
			q.push(make_pair(next, dis));
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int a, b, c;
	adj = vector<vector<pair<int, int>>>(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		adj[a].push_back(make_pair(b, c));
		adj[b].push_back(make_pair(a, c));
	}
	int maxdis = -1;
	for (int i = 1; i <= n; i++) {
		maxdis = max(maxdis, bfs(i));
		memset(visited, 0, sizeof(visited));
	}
	cout << maxdis;
	return 0;
}