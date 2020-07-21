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
//BOJ #14502

int map[9][9];
int visited[9][9];
int v = 1;
int n, m;
int pos[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int ret = 0;
int bfs(int y, int x) {
	queue<pair<int, int>> q;
	visited[y][x] = v;
	q.push({ y,x });
	int cnt = 1;
	bool virus = false;
	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = pos[i][0] + p.second;
			int ny = pos[i][1] + p.first;
			if (nx < 0 || ny < 0 || nx >= m || ny >= n) {
				continue;
			}
			if (visited[ny][nx]==v) {
				continue;
			}
			if (map[ny][nx] == 2) {
				virus = true;
				continue;
			}
			if (map[ny][nx] == 1) {
				continue;
			}
			visited[ny][nx] = v;
			q.push({ ny,nx });
			cnt++;
		}
	}
	return (virus ? 0 : cnt);
}

void solve(int cnt = 1) {
	int c = 0;
	if (cnt == 3) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 0) {
					if (visited[i][j] != v) {
						c += bfs(i, j);
					}
				}
			}
		}
		ret = max(ret, c);
		v++;
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;
				solve(cnt + 1);
				map[i][j] = 0;
			}
		}
	}
}

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
			if (map[i][j] == 0) {
				map[i][j] = 1;
				solve();
				map[i][j] = 0;
			}
		}
	}
	cout << ret;
}
