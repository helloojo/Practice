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
//BOJ #5567
vector<vector<int>> adj;
vector<bool> visited;
queue<pair<int, int>> q;

int bfs(int here) {
	q.push({ here,0 });
	visited[here] = true;
	int cnt = 0;
	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		if (p.second <= 2) {
			cnt++;
		}
		for (int i = 0; i < adj[p.first].size(); i++) {
			int next = adj[p.first][i];
			if (visited[next]) {
				continue;
			}
			q.push({ next,p.second + 1 });
			visited[next] = true;
		}
	}
	return cnt-1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	adj = vector<vector<int>>(n + 1);
	visited = vector<bool>(n + 1);
	int m;
	cin >> m;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	cout << bfs(1);
}
