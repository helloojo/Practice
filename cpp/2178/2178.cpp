#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
//BOJ #2178
int n, m;

struct coor {
	int x;
	int y;
	int cnt;
};
char map[101][101];
queue<coor> q;
int pos[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int bfs(int y, int x) {
	q.push({ x,y,1 });
	map[y][x] = '0';
	int ret = 987654321;
	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		if (p.x == m - 1 && p.y == n - 1) {
			ret = min(ret, p.cnt);
		}
		for (int i = 0; i < 4; i++) {
			int nx = p.x + pos[i][0];
			int ny = p.y + pos[i][1];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n) {
				continue;
			}
			if (map[ny][nx]=='0') {
				continue;
			}
			map[ny][nx] = '0';
			q.push({ nx,ny,p.cnt + 1 });
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}
	cout<<bfs(0, 0);
}