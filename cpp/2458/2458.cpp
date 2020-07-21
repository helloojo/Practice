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
//BOJ #2458

int map[501][501];
int rmap[501][501];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	int a, b;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				map[i][j] = 987654321;
				rmap[i][j] = 987654321;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		map[a][b] = 1;
		rmap[b][a] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				map[j][k] = min(map[j][k], map[j][i] + map[i][k]);
				rmap[j][k] = min(rmap[j][k], rmap[j][i] + rmap[i][k]);
			}
		}
	}
	int ret = 0;
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (map[i][j] == 987654321 && rmap[i][j]==987654321) {
				cnt++;
			}
		}
		if (cnt == 0) {
			ret++;
		}
	}
	cout << ret;

}
