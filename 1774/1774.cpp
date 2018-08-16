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
//BOJ #1774

pair<int, int> arr[1001];
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
	int a, b;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		cin >> a >> b;
		arr[i] = { a,b };
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		merge(a, b);
	}
	priority_queue<pair<double, pair<int, int>>> pq;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			double dis = sqrt(pow(arr[j].second - arr[i].second, 2) + pow(arr[j].first - arr[i].first, 2));
			pq.push({ -dis, { i,j } });
		}
	}
	double ret = 0;
	while (!pq.empty()) {
		auto p = pq.top();
		pq.pop();
		if (merge(p.second.first, p.second.second)) {
			ret += -p.first;
		}
	}
	printf("%.02lf", ret);
}
