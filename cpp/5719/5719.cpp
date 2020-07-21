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
//BOJ #5719

int map[501][501];
int parent[501];
int dis[501];
int n, m;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int dijkstra(int src, int dst) {
	parent[src] = src;
	dis[src] = 0;
	pq.push({ 0,src });
	while (!pq.empty()) {
		auto p = pq.top();
		pq.pop();
		if (dis[p.second]!=-1 && p.first > dis[p.second]) {
			continue;
		}
		for (int i = 0; i < n; i++) {
			if (map[p.second][i]) {
				int next = i;
				int weight = map[p.second][i] + p.first;
				if (dis[next] != -1 && weight > dis[next]) {
					continue;
				}
				dis[next] = weight;
				parent[next] = p.second;
				pq.push({ weight,i });
			}
		}
	}
	return dis[dst];
}

void deletepath(int cur) {
	if (dis[cur] == 0) {
		return;
	}
	for (int i = 0; i < n; i++) {
		if (map[i][cur]) {
			if (map[i][cur] + dis[i] == dis[cur]) {
				map[i][cur] = 0;
				deletepath(i);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	while (!(n == 0 && m == 0)) {
		memset(map, 0, sizeof(map));
		int s, d;
		cin >> s >> d;
		int u, v, p;
		for (int i = 0; i < m; i++) {
			cin >> u >> v >> p;
			map[u][v] = p;
		}
		memset(dis, -1, sizeof(dis));
		dijkstra(s, d);
		int cur = d;
		deletepath(cur);
		memset(dis, -1, sizeof(dis));
		cout << dijkstra(s, d) << '\n';
		cin >> n >> m;
	}
}

