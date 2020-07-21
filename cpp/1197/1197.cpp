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
//BOJ #1197

int parent[10001];

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
	int v, e;
	cin >> v >> e;
	int a, b, c;
	for (int i = 1; i <= v; i++) {
		parent[i] = i;
	}
	priority_queue<pair<int, pair<int, int>>> pq;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		pq.push({ -c,{a,b} });
	}
	int ret = 0;
	while (!pq.empty()) {
		auto p = pq.top();
		pq.pop();
		if (merge(p.second.first, p.second.second)) {
			ret += -p.first;
		}
	}
	cout << ret;
}
