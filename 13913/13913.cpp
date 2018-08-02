#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;
//BOJ #13913
int dis[100001];
int parent[100001];
priority_queue<pair<int, int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
int find(int src, int dst) {
	pq.push({ 0,src });
	dis[src] = 0;
	parent[src] = src;
	while (!pq.empty()) {
		auto p = pq.top();
		pq.pop();
		if (dis[p.second] < p.first) {
			continue;
		}
		int next = p.second + 1;
		int weight = p.first + 1;
		if (next <= 100000) {
			if (weight <= dis[next]) {
				parent[next] = p.second;
				dis[next] = weight;
				pq.push({ weight,next });
			}
		}
		next = p.second - 1;
		weight = p.first + 1;
		if (next >= 0) {
			if (weight <= dis[next]) {
				parent[next] = p.second;
				dis[next] = weight;
				pq.push({ weight,next });
			}
		}
		next = p.second * 2;
		weight = p.first + 1;
		if (next <= 100000) {
			if (weight <= dis[next]) {
				parent[next] = p.second;
				dis[next] = weight;
				pq.push({ weight,next });
			}
		}
	}
	return dis[dst];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < 100001; i++) {
		dis[i] = 987654321;
	}
	int ret=find(n, k);
	cout << ret << '\n';
	int cur = k;
	vector<int> r;
	r.push_back(cur);
	while (parent[cur] != cur) {
		cur = parent[cur];
		r.push_back(cur);
		
	}
	for (int i = r.size() - 1; i >= 0; i--) {
		cout << r[i] << ' ';
	}
}
