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
//BOJ #4386

pair<double,double> arr[101];
int parent[101];

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
		cin >> arr[i].first >> arr[i].second;
		parent[i] = i;
	}
	double ret = 0;
	priority_queue<pair<double, pair<int, int>>> pq;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			pq.push({ -sqrt(pow(arr[i].first - arr[j].first, 2) + pow(arr[i].second - arr[j].second, 2)), { i,j } });
		}
	}
	while (!pq.empty()) {
		auto p = pq.top();
		pq.pop();
		if (merge(p.second.first, p.second.second)) {
			ret += -p.first;
		}
	}
	printf("%.02lf", ret);
}
