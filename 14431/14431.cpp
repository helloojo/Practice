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
//BOJ #14431

vector<vector<pair<int, int>>> adj;
vector<int> dis;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<pair<int, int>> coor;

int getdis(int x1, int y1, int x2, int y2) {
	return sqrt(pow(y2 - y1, 2) + pow(x2 - x1, 2));
}

int dijkstra(int src, int dst) {
	pq.push({ 0,src });
	while (!pq.empty()) {
		auto p = pq.top();
		pq.pop();
		if (dis[p.second] != 987654321) {
			continue;
		}
		dis[p.second] = p.first;
		for (int i = 0; i < adj[p.second].size(); i++) {
			int next = adj[p.second][i].second;
			int weight = adj[p.second][i].first + p.first;
			if (dis[next] == 987654321) {
				pq.push({ weight,next });
			}
		}
	}
	return dis[dst];
}
#define SIZE 10000
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	coor.push_back({ x1,y1 });
	coor.push_back({ x2,y2 });
	int distance;
	int n;
	cin >> n;
	adj = vector<vector<pair<int, int>>>(n + 2);
	dis = vector<int>(n + 2, 987654321);
	bool prime[SIZE] = { false };
	for (int i = 2; i*i < SIZE; i++) {
		if (prime[i]) continue;
		for (int j = i * i; j < SIZE; j += i) {
			prime[j] = true;
		}
	}
	int x3, y3;
	for (int i = 0; i < n; i++) {
		cin >> x3 >> y3;
		coor.push_back({ x3, y3 });
	}
	for (int i = 0; i < coor.size(); i++) {
		for (int j = i + 1; j < coor.size(); j++) {
			distance = getdis(coor[i].first, coor[i].second, coor[j].first, coor[j].second);
			if (!prime[distance]) {
				adj[i].push_back({ distance,j });
				adj[j].push_back({ distance,i });
			}
		}
	}
	int ret = dijkstra(0, 1);
	if (ret == 987654321) {
		cout << -1;
	} else {
		cout << ret;
	}
}
