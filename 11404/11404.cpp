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
//BOJ #11404

int map[101][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	int a, b, c;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				map[i][j] = 987654321;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		map[a][b] = min(map[a][b], c);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				map[j][k] = min(map[j][k], map[j][i] + map[i][k]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << (map[i][j] == 987654321 ? 0 : map[i][j]) << ' ';
		}
		cout << '\n';
	}
}
