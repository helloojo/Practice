#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
#include <cstring>
using namespace std;
//BOJ #1238
int n, m, x;
vector<vector<pair<int, int>>> adj;
int map[1001][1001];
int dis[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int dijkstra(int src,int dst) {
	pq.push({ 0,src });
	while (!pq.empty()) {
		auto p = pq.top();
		pq.pop();
		if (dis[p.second] != 987654321) {
			continue;
		}
		dis[p.second] = p.first;
		int ads = adj[p.second].size();
		for (int i = 0; i < ads; i++) {
			int next = adj[p.second][i].second;
			int weight = adj[p.second][i].first + p.first;
			if (dis[next] == 987654321) {
				pq.push({ weight,next });
			}
		}
	}
	return dis[dst];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> x;
	adj = vector<vector<pair<int, int>>>(n + 1);
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		adj[a].push_back({ c,b });
	}
	int ret = -1;
	int ret1 = -1;
	int ret2 = -1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dis[j] = 987654321;
		}
		ret1 = dijkstra(i, x);
		for (int j = 1; j <= n; j++) {
			dis[j] = 987654321;
		}
		ret2 = dijkstra(x, i);
		ret = max(ret, ret1 + ret2);
	}
	cout << ret;
	return 0;
}