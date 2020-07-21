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
//BOJ #3665

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	int n, m, a, b;
	cin >> t;
	while (t--) {
		int map[501][501] = { 0 };
		int in[501] = { 0 };
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a;
			for (int j = 1; j <= n; j++) {
				if (j == a) continue;
				if (map[j][a] == 0) {
					map[a][j] = 1;
					in[j]++;
				}
			}
		}
		cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			if (map[a][b]) {
				in[b]--;
				in[a]++;
			} else {
				in[b]++;
				in[a]--;
			}
			swap(map[a][b], map[b][a]);
		}
		vector<pair<int, int>> ret(n + 1, { 0,0 });
		for (int i = 1; i <= n; i++) {
			ret[i].second = i;
		}
		queue<int> q;
		for (int i = 1; i <= n; i++) {
			if (in[i] == 0) {
				q.push(i);
			}
		}
		int maxrank = 0;
		while (!q.empty()) {
			auto p = q.front();
			q.pop();
			for (int i = 1; i <= n; i++) {
				if (map[p][i]) {
					in[i]--;
					ret[i].first++;
					maxrank = max(maxrank, ret[i].first);
					if (in[i] == 0) {
						q.push(i);
					}
				}
			}
		}
		bool can = true;
		sort(ret.begin() + 1, ret.end());
		
		for (int i = 1; i <= n; i++) {
			if (ret[i].first != i-1) {
				can = false;
			}
		}
		if (maxrank != n - 1) {
			cout << "IMPOSSIBLE";
		} else if (can) {
			for (int i = 1; i <= n; i++) {
				cout << ret[i].second << ' ';
			}
		} else {
			cout << "?";
		}
		cout << '\n';
	}
}
