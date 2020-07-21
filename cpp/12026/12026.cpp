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
//BOJ #12026

vector<vector<pair<int, int>>> adj;
vector<int> dis;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

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
	return (dis[dst] == 987654321 ? -1 : dis[dst]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	adj = vector<vector<pair<int, int>>>(n);
	dis = vector<int>(n,987654321);
	string s;
	cin >> s;
	for (int i = 0; i < n; i++) {
		char here = s[i];
		char next;
		switch (here) {
		case 'B':
			next = 'O';
			break;
		case 'O':
			next = 'J';
			break;
		case 'J':
			next = 'B';
			break;
		}
		for (int j = i + 1; j < n; j++) {
			if (s[j] == next) {
				adj[i].push_back({ pow(j - i,2),j });
			}
		}
	}
	cout << dijkstra(0, n-1);
}
