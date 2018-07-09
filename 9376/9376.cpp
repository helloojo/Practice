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
//BOJ #9376

struct coor {
	int x;
	int y;
	int door;
};

int w, h;
char map[102][102];
int visited[102][102];
int pos[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
queue<coor> q;
vector<pair<int, int>> v;

int bfs(int y, int x) {
	q.push({ x,y,0 });
	visited[y][x] = 0;
	int ret1 = 987654321;
	int ret2 = 987654321;
	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		for (int i = 0; i < 2; i++) {
			if (v[i].second == p.y && v[i].first == p.x) {
				if (i) {
					ret1 = min(ret1, p.door);
				} else {
					ret2 = min(ret2, p.door);
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			int nx = pos[i][0] + p.x;
			int ny = pos[i][1] + p.y;
			if (nx < 0 || ny < 0 || nx > w || ny > h) continue;
			if (map[ny][nx] == '*') continue;
			if (map[ny][nx] == '#') {
				if (visited[ny][nx] != -1 && visited[ny][nx] <= p.door + 1) {
					continue;
				}
				visited[ny][nx] = p.door + 1;
				q.push({ nx,ny,p.door + 1 });
			} else {
				if (visited[ny][nx] != -1 && visited[ny][nx] <= p.door) {
					continue;
				}
				visited[ny][nx] = p.door;
				q.push({ nx,ny,p.door });
			}
		}
	}
	return ret1 + ret2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;

	cin >> t;
	while (t--) {
		v.clear();
		memset(visited, -1, sizeof(visited));
		cin >> h >> w;
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				cin >> map[i][j];
				if (map[i][j] == '$') {
					v.push_back({ i,j });
				}
			}
		}
		cout << bfs(0, 0) << endl;
	}
}