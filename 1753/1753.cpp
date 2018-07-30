#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
//BOJ #1753

vector<vector<pair<int, int>>> adj;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<int> dis;
int v, e;
int k;
void dijkstra(int n) {
	dis[n] = 0;
	pq.push(make_pair(dis[n], n));
	while (!pq.empty()) {
		auto p = pq.top();
		pq.pop();
		if (p.first > dis[p.second]) continue;
		int adjs = adj[p.second].size();
		for (int i = 0; i < adjs; i++) {
			int next = adj[p.second][i].second;
			int weight = p.first + adj[p.second][i].first;
			if (dis[next] < weight) continue;
			dis[next] = weight;
			pq.push(make_pair(weight, next));
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> v >> e;
	cin >> k;
	adj = vector<vector<pair<int, int>>>(v + 1);
	dis = vector<int>(v + 1, 987654321);
	int u, vv, w;
	for (int i = 0; i < e; i++) {
		cin >> u >> vv >> w;
		adj[u].push_back(make_pair(w, vv));
	}
	dijkstra(k);
	for (int i = 1; i <= v; i++) {
		if (dis[i] == 987654321) {
			cout << "INF\n";
		} else {
			cout << dis[i] << '\n';
		}
	}
	return 0;
}