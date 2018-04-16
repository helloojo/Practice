#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
//BOJ #7576
int map[1001][1001];
bool visit[1001][1001];
int pos[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
queue<pair<int, int>> q;
int n, m;
int bfs(int y, int x) {
	visit[y][x] = true;
	int ret = 1;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = p.first + pos[i][0];
			int ny = p.second + pos[i][1];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
			if (visit[ny][nx]) continue;
			if (!map[ny][nx]) {
				map[ny][nx] = 1;
				continue;
			}
			visit[ny][nx] = true;
			q.push(make_pair(nx, ny));
			ret++;
		}
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	int bfscnt = -1;
	int tomato = 0;
	int time = -1;
	while (tomato!=m*n && bfscnt!=0) {
		bfscnt = 0;
		tomato = 0;
		memset(visit, 0, sizeof(visit));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!visit[i][j] && map[i][j]) {
					tomato+=bfs(i, j);
					bfscnt++;
				}
			}
		}
		time++;
	}
	if (bfscnt) {
		cout << time;
	} else {
		cout << 0;
	}

	return 0;
}