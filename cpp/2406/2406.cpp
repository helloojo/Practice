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
//BOJ #2406

int map[1001][1001];
int parent[1001];

int find(int here) {
	if (parent[here] == here) {
		return here;
	}
	return parent[here] = find(parent[here]);
}

int merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) {
		return false;
	}
	if (u < v) {
		swap(u, v);
	}
	parent[u] = v;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	int x, y;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		merge(x, y);
	}
	priority_queue<pair<int, pair<int, int>>> pq;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			if (i<j && i!=1 && j!=1) {
				pq.push({ -map[i][j],{i,j} });
			}
		}
	}
	int ret = 0;
	vector<pair<int, int>> retv;
	while (!pq.empty()) {
		auto p = pq.top();
		pq.pop();
		if (p.second.first == 1 || p.second.second == 1) {
			continue;
		}
		if (merge(p.second.first, p.second.second)) {
			ret += -p.first;
			retv.push_back({ p.second.first,p.second.second });
		}
	}
	cout << ret << ' ' << retv.size() << '\n';
	for (int i = 0; i < retv.size(); i++) {
		cout << retv[i].first << ' ' << retv[i].second << ' ';
	}
}
