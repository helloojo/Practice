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
//BOJ #14621

bool school[1001];
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
	parent[u] = v;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	char s;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		school[i] = (s == 'M' ? true : false);
		parent[i] = i;
	}
	int a, b, c;
	priority_queue<pair<int, pair<int, int>>> pq;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		pq.push({ -c,{a,b} });
	}
	int ret = 0;
	int cnt = 0;
	while (!pq.empty()) {
		auto p = pq.top();
		pq.pop();
		if (school[p.second.first] == school[p.second.second]) {
			continue;
		}
		if (merge(p.second.first, p.second.second)) {
			ret += -p.first;
			cnt++;
		}
	}
	if (cnt == n - 1) {
		cout << ret;
	} else {
		cout << -1;
	}
	
}
