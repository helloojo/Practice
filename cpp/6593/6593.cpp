#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
//BOJ #6593
struct coor {
	int x;
	int y;
	int z;
	int dis;
};
char map[31][31][31];
int pos[6][3] = { { 0,0,1 },{ 0,0,-1 },{ 0,1,0 },{ 0,-1,0 },{ 1,0,0 },{ -1,0,0 } };
int l, r, c;
queue<coor> q;
int bfs(coor start) {
	q.push(start);
	map[start.z][start.y][start.x] = '#';
	int ret = 987654321;
	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		if (map[p.z][p.y][p.x] == 'E') {
			ret = min(ret, p.dis);
			continue;
		}
		for (int i = 0; i < 6; i++) {
			int nx = p.x + pos[i][0];
			int ny = p.y + pos[i][1];
			int nz = p.z + pos[i][2];
			if (nx < 0 || ny < 0 || nz < 0 || nx >= c || ny >= r || nz >= l) {
				continue;
			}
			if (map[nz][ny][nx] == '#') {
				continue;
			}
			if (map[nz][ny][nx] != 'E') {
				map[nz][ny][nx] = '#';
			}
			q.push({ nx,ny,nz,p.dis + 1 });
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	coor start;
	cin >> l >> r >> c;
	while (!(l == 0 && r == 0 && c == 0)) {
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				cin >> map[i][j];
				for (int k = 0; k < c; k++) {
					if (map[i][j][k] == 'S') {
						start.x = k;
						start.y = j;
						start.z = i;
						start.dis = 0;
					}
				}
			}
		}
		int ret = bfs(start);
		if (ret!=987654321) {
			cout << "Escaped in " << ret << " minute(s).\n";
		} else {
			cout<<"Trapped!\n";
		}
		cin >> l >> r >> c;
	}
}