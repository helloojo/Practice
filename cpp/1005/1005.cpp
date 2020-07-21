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
//BOJ #1005



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> tt(n + 1);
		vector<vector<int>> adj(n + 1);
		vector<int> in(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			cin >> tt[i];
		}
		int a, b;
		for (int i = 0; i < k; i++) {
			cin >> a >> b;
			adj[a].push_back(b);
			in[b]++;
		}
		int w;
		cin >> w;
		priority_queue<pair<int, int>> pq;
		for (int i = 1; i <= n; i++) {
			if (in[i] == 0) {
				pq.push({ -tt[i],i });
			}
		}
		int ret = 0;
		while (!pq.empty()) {
			auto p = pq.top();
			pq.pop();
			if (p.second == w) {
				ret = -p.first;
			}
			for (int i = 0; i < adj[p.second].size(); i++) {
				int next = adj[p.second][i];
				in[next]--;
				if (in[next] == 0) {
					pq.push({ p.first - tt[next],next });
				}
			}
		}
		cout << ret << '\n';
	}
}
