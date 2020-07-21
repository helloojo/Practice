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
//BOJ #1743

int n, m;
bool map[101][101];
int pos[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
queue<pair<int, int>> q;
int bfs(int y, int x) {
	map[y][x] = false;
	q.push({ y,x });
	int cnt = 1;
	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = p.second + pos[i][0];
			int ny = p.first + pos[i][1];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
			if (!map[ny][nx]) continue;
			q.push({ ny,nx });
			map[ny][nx] = false;
			cnt++;
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int k;
	cin >> n >> m >> k;
	int a, b;
	int ret = 0;
	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		map[a-1][b-1] = true;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j]) {
				ret = max(ret, bfs(i, j));
			}
		}
	}
	cout << ret;
}
