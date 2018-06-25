#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
//BOJ #2589
char map[51][51];
bool visit[51][51];
int l, w;
int pos[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
struct Result {
	int x;
	int y;
	int dis;
};
queue<Result> q;

int BFS(int x, int y) {
	q.push({ x, y, 0 });
	visit[y][x] = true;
	int ret = 0;
	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		ret = max(ret, p.dis);
		for (int i = 0; i < 4; i++) {
			int nx = p.x + pos[i][0];
			int ny = p.y + pos[i][1];
			if (nx < 0 || ny < 0 || nx >= w || ny >= l) {
				continue;
			}
			if (map[ny][nx] == 'W' || visit[ny][nx]) {
				continue;
			}
			visit[ny][nx] = true;
			q.push({ nx, ny, p.dis + 1 });
		}
	}
	return ret;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> l >> w;
	for (int i = 0; i < l; i++) {
		cin >> map[i];
	}
	int ret = 0;
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < w; j++) {
			if (map[i][j] == 'L') {
				memset(visit, 0, sizeof(visit));
				ret = max(ret, BFS(j, i));
			}
		}
	}
	cout << ret;
	return 0;
}