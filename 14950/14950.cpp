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
//BOJ #14950

int parent[10001];
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
	int n, m, t;
	cin >> n >> m >> t;
	int a, b, c;
	priority_queue<pair<int, pair<int, int>>> pq;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		pq.push({ -c,{a,b} });
		pq.push({ -c,{b,a} });
	}
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	int cur = 0;
	int ret = 0;
	while (!pq.empty()) {
		auto p = pq.top();
		pq.pop();
		if (merge(p.second.first, p.second.second)) {
			ret += -p.first + cur;
			cur += t;
		}
	}
	cout << ret;
}
