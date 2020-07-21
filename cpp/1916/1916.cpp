	#include <iostream>
	#include <algorithm>
	#include <queue>
	#include <cstring>
	#include <functional>
	using namespace std;
	//BOJ #1916

	vector<pair<int, int>> adj[1001];
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<int> dis;

	int dijkstra(int src, int dst) {
		dis[src] = 0;
		pq.push({ dis[src],src });
		while (!pq.empty()) {
			auto p = pq.top();
			pq.pop();
			if (p.first > dis[p.second]) {
				continue;
			}
			for (int i = 0; i < adj[p.second].size(); i++) {
				int next = adj[p.second][i].second;
				int weight = adj[p.second][i].first+p.first;
				if (dis[next] < weight) {
					continue;
				}
				dis[next] = weight;
				pq.push({ dis[next],next });
			}
		}
		return dis[dst];
	}

	int main() {
		int n, m;
		cin >> n >> m;
		int a, b, c;
		dis=vector<int>(n + 1, 987654321);
		for (int i = 0; i < m; i++) {
			cin >> a >> b >> c;
			adj[a].push_back({ c,b });
		}
		int src, dst;
		cin >> src >> dst;
		cout << dijkstra(src, dst);
		return 0;
	}