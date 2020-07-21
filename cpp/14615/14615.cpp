#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<vector<int>> adj[2];
bool a[100001];
bool b[100001];

int v;
void bfs(vector<vector<int>>& adj, bool* arr, int here) {
	arr[here] = true;
	queue<int> q;
	q.push(here);
	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		for (int i = 0; i < adj[p].size(); i++) {
			int next = adj[p][i];
			if (arr[next]) {
				continue;
			}
			arr[next] = true;
			q.push(next);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	adj[0].resize(n + 1);
	adj[1].resize(n + 1);
	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		adj[0][x].push_back(y);
		adj[1][y].push_back(x);
	}
	bfs(adj[0], a, 1);
	bfs(adj[1], b, n);
	int t;
	cin >> t;
	int c;
	while (t--) {
		cin >> c;
		if (a[c] && b[c]) {
			cout << "Defend the CTP\n";
		} else {
			cout << "Destroyed the CTP\n";
		}
	}
	return 0;
}