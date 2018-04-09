#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//BOJ #1504
vector<vector<pair<int, int>>> adj;
priority_queue<pair<int, int>> pq;
int n, e;
int ma, mb;
int dijkstra(int src) {
	pq.push(make_pair(0, src));
	while (!pq.empty()) {
		auto p = pq.top();
		int here = p.second;
		int dis = p.first;
		for (int i = 0; i < adj[here].size(); i++) {

		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> e;
	int a, b, c;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		adj[a].push_back(make_pair(b, c));
	}
	cin >> ma >> mb;
	return 0;
}