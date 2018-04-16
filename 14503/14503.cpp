#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
//BOJ #14503

struct robot {
	int x;
	int y;
	int d;
	int cnt;
};
int n, m;
int map[51][51];
int clean[51][51];
int pos[4][2] = { {0,-1},{1,0},{0,1},{-1,0} };
queue<robot> q;
int bfs(int r, int c, int d) {
	int ret = 1;
	clean[r][c] = true;
	q.push({ c,r,d,0 });
	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		if (p.cnt == 4) {
			int nx = p.x - pos[p.d][0];
			int ny = p.y - pos[p.d][1];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n) {
				continue;
			}
			if (map[ny][nx]) {
				continue;
			}
			q.push({ nx,ny,p.d,0 });
		} else {
			int td = ((p.d - 1) % 4 == -1 ? 3 : (p.d - 1) % 4);
			int nx = p.x + pos[td][0];
			int ny = p.y + pos[td][1];
			if ((nx < 0 || ny < 0 || nx >= m || ny >= n) || clean[ny][nx] || map[ny][nx]) {
				q.push({ p.x, p.y, td,p.cnt + 1 });
				continue;
			}
			clean[ny][nx] = true;
			ret++;
			q.push({ nx,ny,td,0 });
		}
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	int r, c, d;
	cin >> r >> c >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	cout << bfs(r, c, d);
	return 0;
}