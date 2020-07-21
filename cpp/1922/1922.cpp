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
//BOJ #1922

int parent[1001];
int find(int here) {
	if (parent[here] == here) {
		return here;
	}
	return parent[here] = find(parent[here]);
}

bool merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) {
		return false;
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
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	int a, b, c;
	vector<pair<int, pair<int, int>>> edge;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		edge.push_back({c, { a,b }});
	}
	sort(edge.begin(), edge.end());
	int ret = 0;
	for (int i = 0; i < m; i++) {
		if (merge(edge[i].second.first, edge[i].second.second)) {
			ret += edge[i].first;
		}
	}
	cout << ret;
}
