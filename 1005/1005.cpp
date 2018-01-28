#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
//BOJ #1005

int ti[1001];
int indegree[1001];
int memo[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n, k, w;
		cin >> n >> k;
		vector<vector<int>> adj(n + 1);
		queue<int> q;
		memset(indegree, 0, sizeof(int) * 1001);
		memset(memo, 0, sizeof(int) * 1001);
		for (int i = 1; i <= n; i++) {
			cin >> ti[i];
		}
		int s, d;
		for (int i = 0; i < k; i++) {
			cin >> s >> d;
			adj[s].push_back(d);
			indegree[d]++;
		}
		cin >> w;
		for (int i = 1; i <= n; i++) {
			if (indegree[i] == 0) {
				q.push(i);
				memo[i] = ti[i];
			}
		}
		while (!q.empty()) {
			int here = q.front();
			q.pop();
			for (int i = 0; i < adj[here].size(); i++) {
				int next = adj[here][i];
				indegree[next]--;
				if (indegree[next] == 0) {
					q.push(next);
				}
				memo[next] = max(memo[next], memo[here] + ti[next]);
			}
		}
		cout << memo[w] << '\n';
	}
	return 0;
}