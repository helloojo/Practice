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
//BOJ #6497

int parent[200000];

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
	int m, n;
	cin >> m >> n;
	while (!(m == 0 && n == 0)) {
		for (int i = 0; i < m; i++) {
			parent[i] = i;
		}
		priority_queue<pair<int, pair<int, int>>> pq;
		int a, b, c;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> a >> b >> c;
			sum += c;
			pq.push({ -c,{ a,b, } });
		}
		int ret = 0;
		while (!pq.empty()) {
			auto p = pq.top();
			pq.pop();
			if (merge(p.second.first, p.second.second)) {
				ret += -p.first;
			}
		}
		cout << sum - ret << '\n';
		cin >> m >> n;
	}
}
