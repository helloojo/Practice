#include <iostream>
#include <algorithm>
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
	Result(int _x, int _y, int _dis) {
		x = _x;
		y = _y;
		dis = _dis;
	}
};
queue<Result> q;

Result BFS(int x,int y) {
	q.push(Result(x, y, 0));
	visit[y][x] = true;
	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		int cnt = 0;
		for (int i = 0; i < 4; i++) {
			int nx = p.x + pos[i][0];
			int ny = p.y + pos[i][1];
			if (nx < 0 || ny < 0 || nx >= w || ny >= l) {
				cnt++;
				continue;
			}
			if (map[ny][nx] == 'W' || visit[ny][nx]) {
				continue;
			}
			visit[ny][nx] == true;
			q.push(Result(nx, ny, p.dis + 1));
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	cin >> l >> w;
	for (int i = 0; i < l; i++) {
		cin >> map[i];
	}
	return 0;
}