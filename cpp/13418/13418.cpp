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
//BOJ #13418

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
	int a, b, c;
	priority_queue<pair<int, pair<int, int>>> maxpq;
	priority_queue<pair<int, pair<int, int>>> minpq;
	for (int i = 0; i < m + 1; i++) {
		cin >> a >> b >> c;
		minpq.push({ c,{ a,b } });
		maxpq.push({ -c,{ a,b } });
	}
	int cnt = 0;
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}
	while (!minpq.empty()) {
		auto p = minpq.top();
		minpq.pop();
		if (merge(p.second.first, p.second.second)) {
			if (p.first == 0) {
				cnt++;
			}
		}
	}
	int cnt2 = 0;
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}
	while (!maxpq.empty()) {
		auto p = maxpq.top();
		maxpq.pop();
		if (merge(p.second.first, p.second.second)) {
			if (p.first == 0) {
				cnt2++;
			}
		}
	}
	cout << cnt2 * cnt2 - cnt * cnt;
}
