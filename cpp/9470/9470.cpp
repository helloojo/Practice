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
//BOJ #9470

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int k, m, p;
		cin >> k >> m >> p;
		vector<vector<int>> adj(m + 1);
		vector<int> in(m + 1, 0);
		int a, b;
		for (int i = 0; i < p; i++) {
			cin >> a >> b;
			adj[a].push_back(b);
			in[b]++;
		}
		queue<int> q;
		vector<pair<int, vector<int>>> ret(m + 1, { 0, vector<int>(m + 2,0) });
		for (int i = 1; i <= m; i++) {
			if (in[i] == 0) {
				q.push(i);
				ret[i].first = 1;
			}
		}
		while (!q.empty()) {
			int p = q.front();
			q.pop();
			for (int i = 0; i < adj[p].size(); i++) {
				int next = adj[p][i];
				in[next]--;
				ret[next].second[ret[p].first]++;
				if (ret[next].second[ret[p].first] > 1) {
					ret[next].first = max(ret[next].first,ret[p].first + 1);
				} else {
					ret[next].first = max(ret[next].first, ret[p].first);
				}
				if (in[next] == 0) {
					q.push(next);
				}
			}
		}
		cout << k << ' ' << ret[m].first << '\n';
	}
}
