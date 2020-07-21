#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//BOJ #1504
vector<vector<pair<int, int>>> adj;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int n, e;
int ma, mb;
long long dijkstra(int src, int dst) {
	vector<long long> dis(n + 1, 987654321);
	pq.push({ 0,src });
	while (!pq.empty()) {
		auto p = pq.top();
		pq.pop();
		if (dis[p.second] != 987654321) continue;
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
	cin >> n >> e;
	adj = vector<vector<pair<int, int>>>(n + 1);

	int a, b, c;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		adj[a].push_back({ c,b });
		adj[b].push_back({ c,a });
	}
	cin >> ma >> mb;
	long long ret = 0;
	long long onea = dijkstra(1, ma);
	long long ab = dijkstra(ma, mb);
	long long oneb = dijkstra(1, mb);
	long long an = dijkstra(ma, n);
	long long bn = dijkstra(mb, n);
	long long ret1 = onea + ab + bn;
	long long ret2 = oneb + ab + an;
	ret = min(ret1, ret2);
	if (ret >= 987654321) {
		ret = -1;
	}
	cout << ret;
	return 0;
}