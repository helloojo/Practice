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
//BOJ #5427

struct coor {
	int x;
	int y;
	int dis;
};
char map[1001][1001];
bool visited[1001][1001];
int pos[4][2] = { { 0,1 },{ 0,-1 },{ 1,0 },{ -1,0 } };
vector<pair<int, int>> fire;
queue<coor> q;
int w, h;

void print() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

int bfs(int y, int x) {
	visited[y][x] = true;
	for (int i = 0; i < fire.size(); i++) {
		q.push({ fire[i].second,fire[i].first,0 });
	}
	q.push({ x,y,1 });
	int ret = 987654321;
	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = p.x + pos[i][0];
			int ny = p.y + pos[i][1];
			if (nx < 0 || ny < 0 || nx >= w || ny >= h) {
				if (p.dis) {
					ret = min(ret, p.dis);
				}
				continue;
			}
			if (map[ny][nx] == '#') {
				continue;
			}
			if (p.dis) {
				if (visited[ny][nx]) {
					continue;
				}
				if (map[ny][nx] == '*') {
					continue;
				}
				visited[ny][nx] = true;
				map[ny][nx] = '@';
				q.push({ nx,ny,p.dis + 1 });
			} else {
				if (visited[ny][nx]) {
					if (map[ny][nx] != '*') {
						map[ny][nx] = '*';
						q.push({ nx,ny,0 });
					}
					continue;
				}
				visited[ny][nx] = true;
				map[ny][nx] = '*';
				q.push({ nx,ny,0 });
			}
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		cin >> w >> h;
		int sx, sy;
		fire.clear();
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
				if (map[i][j] == '*') {
					fire.push_back({ i,j });
				} else if (map[i][j] == '@') {
					sx = j;
					sy = i;
				}
			}
		}
		int ret = bfs(sy, sx);
		if (ret == 987654321) {
			cout << "IMPOSSIBLE\n";
		} else {
			cout << ret << '\n';
		}
	}
}
