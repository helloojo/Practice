#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
//BOJ #2665

struct coor {
	int x;
	int y;
	int change;
};
int n;
int map[51][51];
queue<coor> q;
bool visited[51][51];
int pos[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

int bfs(int x = 0, int y = 0) {
	int ret = 987654321;
	q.push({ x,y,0 });
	visited[y][x] = true;
	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		if (p.x == n - 1 && p.y == n - 1) {
			ret = min(ret, p.change);
			continue;
		}
		for (int i = 0; i < 4; i++) {
			int nx = p.x + pos[i][0];
			int ny = p.y + pos[i][1];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (visited[ny][nx]) continue;
			if (map[ny][nx] == -1) continue;
			if (map[ny][nx] == 0) {
				map[ny][nx] = -1;
				q.push({ nx,ny,p.change + 1 });
			} else {
				q.push({ nx,ny,p.change });
			}
		}
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	cout << bfs();
}