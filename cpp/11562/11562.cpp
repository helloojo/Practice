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
//BOJ #11562
int map[251][251];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	int u, v, b;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				map[i][j] = 987654321;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> b;
		if (b) {
			map[u][v] = 0;
			map[v][u] = 0;
		} else {
			map[u][v] = 0;
			map[v][u] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				map[j][k] = min(map[j][k], map[j][i] + map[i][k]);
			}
		}
	}
	int k;
	cin >> k;
	int s, e;
	for (int i = 0; i < k; i++) {
		cin >> s >> e;
		cout << map[s][e] << '\n';
	}
}
