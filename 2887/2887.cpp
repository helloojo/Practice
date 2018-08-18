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
//BOJ #2887

int parent[100001];
pair<int, int> x[100001];
pair<int, int> y[100001];
pair<int, int> z[100001];

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
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		x[i].second = y[i].second = z[i].second = i;
		parent[i] = i;
		cin >> x[i].first >> y[i].first >> z[i].first;
	}
	priority_queue<pair<int, pair<int, int>>> pq;
	sort(x + 1, x + 1 + n);
	sort(y + 1, y + 1 + n);
	sort(z + 1, z + 1 + n);
	for (int i = 1; i < n; i++) {
		pq.push({ -abs(x[i].first - x[i + 1].first),{x[i].second,x[i + 1].second} });
		pq.push({ -abs(y[i].first - y[i + 1].first),{ y[i].second,y[i + 1].second } });
		pq.push({ -abs(z[i].first - z[i + 1].first),{ z[i].second,z[i + 1].second } });
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
