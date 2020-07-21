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
//BOJ #1185

int cost[10001];
int parent[10001];
int minx = 1;
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
	int n, p;
	cin >> n >> p;
	
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		cin >> cost[i];
		if (cost[i] < cost[minx]) {
			minx = i;
		}
	}
	priority_queue<pair<int, pair<int, int>>> pq;
	int s, e, l;
	for (int i = 0; i < p; i++) {
		cin >> s >> e >> l;
		pq.push({ -(l*2+cost[s]+cost[e]),{ s,e } });
	}
	int ret = cost[minx];
	while (!pq.empty()) {
		int u = pq.top().second.first;
		int v = pq.top().second.second;
		int w = -pq.top().first;
		pq.pop();
		if (merge(u, v)) {
			ret += w;
		}
	}
	cout << ret;
}
