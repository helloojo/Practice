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
//BOJ #9370
int n, m, t;

void dijkstra(int src, vector<vector<pair<int, int>>>& adj, vector<int>& dis) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
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
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> m >> t;
		int s, g, h;
		cin >> s >> g >> h;
		int a, b, d;
		vector<vector<pair<int, int>>> adj(n + 1);
		vector<int> dest;
		vector<int> start(n + 1, 987654321);
		vector<int> gg(n + 1, 987654321);
		vector<int> hh(n + 1, 987654321);
		for (int i = 0; i < m; i++) {
			cin >> a >> b >> d;
			adj[a].push_back({ d,b });
			adj[b].push_back({ d,a });
		}
		int x;
		dijkstra(s, adj, start);
		dijkstra(h, adj, hh);
		dijkstra(g, adj, gg);
		for (int i = 0; i < t; i++) {
			cin >> x;
			dest.push_back(x);
			int cmp=min(start[g]+gg[h]+hh[x],start[h]+hh[g]+gg[x]);
			if (cmp!=start[x]) {
				dest.pop_back();
			}
		}
		sort(dest.begin(), dest.end());
		for (int i = 0; i < dest.size(); i++) {
			cout << dest[i] << ' ';
		}
		cout << '\n';
	}
}
