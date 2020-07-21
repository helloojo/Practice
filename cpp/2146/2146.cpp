#include <iostream>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
//BOJ #2146
struct coor {
	int x;
	int y;
	int dis;
};
int map[101][101];
bool visited[101][101];
int land[101][101];
int pos[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int n;
int cnt = 1;
queue<coor> q;

int bfs(int y, int x, int type) {
	int ret = 987654321;
	switch (type) {
	case 0:
		q.push({ x,y,0 });
		land[y][x] = cnt;
		while (!q.empty()) {
			auto p = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = pos[i][0] + p.x;
				int ny = pos[i][1] + p.y;
				if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
					continue;
				}
				if (land[ny][nx] || !map[ny][nx]) continue;
				land[ny][nx] = cnt;
				q.push({ nx,ny,0 });
			}
		}
		break;
	case 1:
		int ll = land[y][x];
		q.push({ x,y,0 });
		visited[y][x] = true;
		while (!q.empty()) {
			auto p = q.front();
			q.pop();
			if (land[p.y][p.x] && ll != land[p.y][p.x]) {
				
				ret = min(ret, p.dis-1);
			}
			for (int i = 0; i < 4; i++) {
				int nx = pos[i][0] + p.x;
				int ny = pos[i][1] + p.y;
				if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
					continue;
				}
				if (visited[ny][nx]) continue;
				visited[ny][nx] = true;
				q.push({ nx,ny,p.dis + 1 });
			}
		}
		break;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] && !land[i][j]) {
				bfs(i, j, 0);
				cnt++;
			}
		}
	}
	int ret = 987654321;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			memset(visited, 0, sizeof(visited));
			if (land[i][j]) {
				ret=min(ret,bfs(i, j, 1));
			}
		}
	}
	cout << ret;
}
