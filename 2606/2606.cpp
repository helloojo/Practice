#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
//BOJ #2606

vector<vector<int>> adj;
queue<int> q;
int visited[101];

int bfs(int here) {
	visited[here] = true;
	q.push(here);
	int ret = 0;
	while (!q.empty()) {
		int p = q.front();
		q.pop();
		int si = adj[p].size();
		for (int i = 0; i < si; i++) {
			int next = adj[p][i];
			if (visited[next]) continue;
			visited[next] = true;
			q.push(next);
			ret++;
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int m;
	cin >> m;
	int a, b;
	adj = vector<vector<int>>(n + 1);
	while (m--) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);		
	}
	cout << bfs(1);
}