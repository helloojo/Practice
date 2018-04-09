#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
#include <cstring>
using namespace std;
//BOJ #1238
int n, m, x;
int map[1001][1001];
int dis[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int dijkstra(int n) {
	dis[n] = 0;
	pq.push(make_pair(dis[n], n));
	while (!pq.empty()) {
		auto p = pq.top();
		pq.pop();
		if (p.first > dis[p.second]) continue;
		for (int i = 1; i <= n; i++) {
			if (i != p.second && map[p.second][i]) {
				int next = i;
				int weight = p.first + map[p.second][i];
				if (weight > dis[next]) continue;
				dis[next] = weight;
				pq.push(make_pair(weight, next));
			}
		}
	}
	return dis[x];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> x;
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		map[a][b] = c;
	}
	int ret = -1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dis[j] = 987654321;
		}
		ret = max(ret, dijkstra(i));
	}
	cout << ret * 2;

	return 0;
}