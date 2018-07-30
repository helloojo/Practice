#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

int n, m;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<vector<pair<int, int>>> adj;
vector<int> dis;
vector<int> parent;

int dijkstra(int start, int dest, int blocksrc = 0, int blockdest = 0) {
	dis[start] = 0;
	pq.push({ dis[start],start });
	parent[start] = start;
	while (!pq.empty()) {
		auto p = pq.top();
		pq.pop();
		if (p.first > dis[p.second]) {
			continue;
		}
		int si = adj[p.second].size();
		for (int i = 0; i < si; i++) {
			int next = adj[p.second][i].second;
			if (next == blockdest && p.second == blocksrc) {
				continue;
			}
			int weight = adj[p.second][i].first + p.first;
			if (weight > dis[next]) {
				continue;
			}
			dis[next] = weight;
			pq.push({ dis[next],next });
			if (!blocksrc) {
				parent[next] = p.second;
			}
		}
	}
	return dis[dest];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	int a, b, c;
	adj = vector<vector<pair<int, int>>>(n + 1);
	dis = vector<int>(n + 1, 987654321);
	parent = vector<int>(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		adj[a].push_back({ c,b });
		adj[b].push_back({ c,a });
	}
	int great = dijkstra(1, n);
	int next = n;
	int another = 0;
	while (next != parent[next]) {
		dis.assign(n + 1, 987654321);
		another = max(another, dijkstra(1, n, parent[next], next));
		next = parent[next];
	}
	if (another == 987654321) {
		cout << -1 << '\n';
	} else {
		cout << another - great << '\n';
	}

}