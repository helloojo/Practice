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
//BOJ #10282

vector<vector<pair<int, int>>> adj;
vector<int> dis;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

pair<int, int> dijkstra(int src) {
	pq.push({ 0,src });
	pair<int, int> ret(0, 0);
	while (!pq.empty()) {
		auto p = pq.top();
		pq.pop();
		if (dis[p.second] != 987654321) {
			continue;
		}
		ret.first++;
		dis[p.second] = p.first;
		ret.second = max(dis[p.second], ret.second);
		int ads = adj[p.second].size();
		for (int i = 0; i < ads; i++) {
			int next = adj[p.second][i].second;
			int weight = adj[p.second][i].first + p.first;
			if (dis[next] == 987654321) {
				pq.push({ weight,next });
			}
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n, d, c;
		cin >> n >> d >> c;
		adj.clear();
		dis.clear();
		adj.resize(n + 1);
		dis.resize(n + 1, 987654321);
		int a, b, s;
		for (int i = 0; i < d; i++) {
			cin >> a >> b >> s;
			adj[b].push_back({ s,a });
		}
		pair<int, int> ret = dijkstra(c);
		cout << ret.first << ' ' << ret.second << '\n';
	}
}
