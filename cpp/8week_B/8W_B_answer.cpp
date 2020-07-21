#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

vector<vector<int>> adj;
bool visited[51];
pair<int, int> ret[51];
int n, m;
bool can = true;
void dfs(int start, int here) {
	visited[here] = true;
	if (start != here) {
		ret[start].second++;
		ret[here].first++;
	}
	int si = adj[here].size();
	for (int i = 0; i < si; i++) {
		int next = adj[here][i];
		if (start==next) {
			can = false;
			return;
		}
		if (!visited[next]) dfs(start, next);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	int s, d;
	while (t--) {
		can = true;
		memset(ret, 0, sizeof(ret));
		cin >> n >> m;
		adj = vector<vector<int>>(n+1);
		while (m--) {
			cin >> s >> d;
			adj[s].push_back(d);
		}
		
		for (int i = 1; i <= n; i++) {
			memset(visited, 0, sizeof(visited));
			dfs(i, i);
			if (!can) {
				break;
			}
		}
		/*for (int i = 1; i <= n; i++) {
			if (ret[i].first + ret[i].second != n-1) {
				can = false;
				break;
			}
		}*/
		if (can) {
			for (int i = 1; i <= n; i++) {
				cout << ret[i].first << ' ' << ret[i].second << '\n';
			}
		} else {
			cout << -1 << '\n';
		}
	}
}