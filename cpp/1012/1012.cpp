#include <iostream>
using namespace std;
//BOJ #1012

int map[51][51];
int pos[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int m, n;
void dfs(int y, int x) {
	map[y][x] = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + pos[i][0];
		int nx = x + pos[i][1];
		if (ny < 0 || nx < 0 || nx >= m || ny >= n) continue;
		if (map[ny][nx]) {
			dfs(ny, nx);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int k;
		cin >> m >> n >> k;
		while (k--) {
			int x, y;
			cin >> x >> y;
			map[y][x] = 1;
		}
		int ret = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j]) {
					dfs(i, j);
					ret++;
				}
			}
		}
		cout << ret << '\n';
	}
}