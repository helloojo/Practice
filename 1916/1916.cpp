#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <functional>
using namespace std;
//BOJ #1916

int map[1001][1001];
int dis[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int n, m;

int dijkstra(int src, int dest) {
	dis[src] = 0;
	pq.push(make_pair(dis[src], src));
	while (!pq.empty()) {
		auto p = pq.top();
		pq.pop();
		if (p.first > dis[p.second]) continue;
		for (int i = 1; i <= n; i++) {
			if (map[p.second][i] != 987654321 && i!=p.second) {
				int next = i;
				int weight = map[p.second][i] + p.first;
				if (weight > dis[next]) continue;
				dis[next] = weight;
				pq.push(make_pair(dis[next], next));
			}
		}
	}
	return dis[dest];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int src, dst, pri;
	int a, b;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			map[i][j] = 987654321;
		}
		dis[i] = 987654321;
	}
	for (int i = 0; i < m; i++) {
		cin >> src >> dst >> pri;
		map[src][dst] = min(map[src][dst], pri);
	}
	cin >> a >> b;
	cout << dijkstra(a, b);
	return 0;
}