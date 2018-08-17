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
//BOJ #10423

bool elec[1001];
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
	if (elec[u] && elec[v]) {
		return false;
	}
	parent[u] = v;
	if (elec[u]) {
		elec[v] = true;
	} else if (elec[v]) {
		elec[u] = true;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	int num;
	for (int i = 0; i < k; i++) {
		cin >> num;
		elec[num] = true;
	}
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	int a, b, c;
	priority_queue<pair<int, pair<int, int>>> pq;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		pq.push({ -c,{a,b} });
	}

	int ret = 0;
	while (!pq.empty()) {
		auto p = pq.top();
		pq.pop();
		if (elec[p.second.first] && elec[p.second.second]) {
			continue;
		}
		if (merge(p.second.first, p.second.second)) {
			ret += -p.first;
		}
	}
	cout << ret;
}
