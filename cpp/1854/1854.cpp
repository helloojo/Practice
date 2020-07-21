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
//BOJ #1854

vector<vector<pair<int, int>>> adj;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<priority_queue<int>> dis;
int n, m, k;
void dijkstra(int here) {
	pq.push({ 0,here });
	while (!pq.empty()) {
		auto p = pq.top();
		pq.pop();
		if (dis[p.second].size() >= k) {
			continue;
		}
		dis[p.second].push(p.first);
		for (int i = 0; i < adj[p.second].size(); i++) {
			int next = adj[p.second][i].second;
			int weight = adj[p.second][i].first+p.first;
			if (dis[p.second].size() < k) {
				pq.push({ weight, next });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> k;
	adj.resize(n + 1);
	dis.resize(n + 1);
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		adj[a].push_back({ c,b });
	}
	dijkstra(1);
	for (int i = 1; i <= n; i++) {
		if (dis[i].size()<k) {
			cout << -1 << '\n';
		} else {
			cout << dis[i].top() << '\n';
		}
	}
}
