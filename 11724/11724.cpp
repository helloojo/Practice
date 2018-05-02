#include <iostream>
#include <vector>
using namespace std;
//BOJ #11724
int n, m;
vector<vector<int>> adj;
bool visited[1001];
void dfs(int here) {
	if (visited[here]) return;
	visited[here] = true;
	for (int i = 0; i < adj[here].size(); i++) {
		dfs(adj[here][i]);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	adj = vector<vector<int>>(n + 1);
	int u, v;
	while (m--) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int ret = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs(i);
			ret++;
		}
	}
	cout << ret;
}