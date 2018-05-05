#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
//BOJ #10451

vector<vector<int>> adj;
bool visited[1001];

void dfs(int here) {
	if (visited[here]) return;
	visited[here] = true;
	int si = adj[here].size();
	for (int i = 0; i < si; i++) {
		dfs(adj[here][i]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		memset(visited,0,sizeof(visited));
		int n;
		cin >> n;
		int num;
		adj = vector<vector<int>>(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> num;
			adj[i].push_back(num);
		}
		int ret = 0;
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				dfs(i);
				ret++;
			}
		}
		cout << ret << '\n';
	}
}