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
//BOJ #1647

int parent[100001];
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
	int sum = 0;
	priority_queue<pair<int, pair<int, int>>> pq;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		sum += c;
		pq.push({ -c,{a,b} });
	}
	int ret = 0;
	int maxweight = 0;
	while (!pq.empty()) {
		auto p = pq.top();
		pq.pop();
		if (merge(p.second.first, p.second.second)) {
			maxweight = max(maxweight, -p.first);
			ret += -p.first;
		}
	}
	cout << ret-maxweight;
}
