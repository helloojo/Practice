#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
#include <cstring>
using namespace std;
//BOJ #1238
int n, m, x;
vector<vector<pair<int, int>>> adj;
vector<vector<pair<int, int>>> rev;
int dis[1001];
int disrev[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void dijkstra(int src, vector<vector<pair<int, int>>>& ad, int* dis) {
	pq.push({ 0,src });
	while (!pq.empty()) {
		auto p = pq.top();
		pq.pop();
		if (dis[p.second] != 987654321) {
			continue;
		}
		dis[p.second] = p.first;
		int ads = ad[p.second].size();
		for (int i = 0; i < ads; i++) {
			int next = ad[p.second][i].second;
			int weight = ad[p.second][i].first + p.first;
			if (dis[next] == 987654321) {
				pq.push({ weight,next });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> x;
	adj = vector<vector<pair<int, int>>>(n + 1);
	rev = vector<vector<pair<int, int>>>(n + 1);
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		adj[a].push_back({ c,b });
		rev[b].push_back({ c,a });
	}
	for (int i = 1; i <= n; i++) {
		dis[i] = 987654321;
		disrev[i] = 987654321;
	}
	dijkstra(x, adj, dis);
	dijkstra(x, rev, disrev);
	int ret = -1;
	for (int i = 1; i <= n; i++) {
		ret = max(dis[i] + disrev[i], ret);
	}
	cout << ret;
	return 0;
}