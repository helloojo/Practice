#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
//BOJ #4803
int n, m;
vector<vector<int>> adj;
bool visited[501];
queue<pair<int, int>> q;
bool bfs(int here) {
	visited[here] = true;
	q.push({ here,here });
	int node = 0;
	int line = 0;
	bool ret = true;
	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		node++;
		int si = adj[p.first].size();
		for (int i = 0; i < si; i++) {
			int next = adj[p.first][i];
			if (next == p.second) {
				continue;
			}
			if (visited[next]) {
				ret = false;
				continue;
			}
			line++;
			visited[next] = true;
			q.push({ next,p.first });
		}
	}
	if (node != line + 1) {
		ret = false;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	int c = 1;
	while (!(n == 0 && m == 0)) {
		adj = vector<vector<int>>(n + 1);
		memset(visited, 0, sizeof(visited));
		int a, b;
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		int ret = 0;
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				if (bfs(i)) {
					ret++;
				}
			}
		}
		cout << "Case " << c++ << ": ";
		if (ret > 1) {
			cout << "A forest of " << ret << " trees.\n";
		} else if (ret == 1) {
			cout << "There is one tree.\n";
		} else {
			cout << "No trees.\n";
		}
		cin >> n >> m;
	}
}