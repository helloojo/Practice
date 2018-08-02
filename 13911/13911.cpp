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
//BOJ #13911

vector<vector<pair<int, int>>> adj;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<int> star;
vector<int> mac;
bool house[10001];

void dijkstra(vector<int>& here,vector<int>& v) {
	for (int i = 0; i < here.size(); i++) {
		pq.push({ 0,here[i] });
	}
	while (!pq.empty()) {
		auto p = pq.top();
		pq.pop();
		if (v[p.second] != 987654321) {
			continue;
		}
		v[p.second] = p.first;
		int ads = adj[p.second].size();
		for (int i = 0; i < ads; i++) {
			int next = adj[p.second][i].second;
			int weight = adj[p.second][i].first + p.first;
			if (v[next] == 987654321) {
				pq.push({ weight,next });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int v, e;
	cin >> v >> e;
	adj = vector<vector<pair<int, int>>>(v + 3);
	star = vector<int>(v + 3, 987654321);
	mac = vector<int>(v + 3, 987654321);
	int a, b, c;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		adj[a].push_back({ c,b });
		adj[b].push_back({ c,a });
	}
	int m, x, s, y;
	cin >> m >> x;
	vector<int> temp;
	for (int i = 0; i < m; i++) {
		cin >> a;
		temp.push_back(a);
		house[a] = true;
	}
	cin >> s >> y;
	dijkstra(temp, mac);
	temp.clear();
	for (int i = 0; i < s; i++) {
		cin >> a;
		temp.push_back(a);
		house[a] = true;
	}
	dijkstra(temp, star);
	int ret = 987654321;
	for (int i = 1; i <= v; i++) {
		if (!house[i] && mac[i] <= x && star[i] <= y) {
			ret = min(ret, mac[i] + star[i]);
		}
	}
	if (ret == 987654321) {
		cout << -1;
	} else {
		cout << ret;
	}
}
