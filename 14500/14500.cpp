#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
//BOJ #14500
int map[501][501];
bool visited[501][501];
int pos[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int n, m;
int ret = 0;
void dfs(int y, int x, int cnt, int sum) {
	if (y < 0 || x < 0 || x >= m || y >= n) return;
	if (visited[y][x]) return;
	visited[y][x] = true;
	if (cnt == 4) {
		ret = max(ret, sum+ map[y][x]);
	}
	for (int i = 0; i < 4; i++) {
		int ny = y + pos[i][0];
		int nx = x + pos[i][1];
		dfs(ny, nx, cnt + 1, sum + map[y][x]);
	}
}
int T[4][4][2] = {
	{{0,0},{1,0},{2,0},{1,1}},
	{{0,0},{0,1},{0,2},{1,1}},
	{{0,0},{1,0},{2,0},{1,-1}},
	{{0,0},{0,1},{0,2},{-1,1}}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			memset(visited, 0, sizeof(visited));
			dfs(i, j, 1, 0);
			int cur = 0;
			for (int k = 0; k < 4; k++) {
				cur = 0;
				for (int p = 0; p < 4; p++) {
					int nx = j + T[k][p][0];
					int ny = i + T[k][p][1];
					if (nx < 0 || ny < 0 || nx >= m || ny >= n) {
						cur = 0;
						break;
					}
					cur += map[ny][nx];
				}
				ret = max(ret, cur);
			}
		}
	}
	cout << ret;
}