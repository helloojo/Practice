#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
//BOJ #1967
int n, m;
char map[51][51];
bool visited[301][301];
int pos[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
queue<pair<int, int>> q;

void bfs(int y, int x) {
	visited[y][x] = true;
	q.push(make_pair(y, x));
	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = p.second + pos[i][0];
			int ny = p.first + pos[i][1];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n) {
				continue;
			}
			if (visited[ny][nx]) {
				continue;
			}
			if (!map[ny][nx]) {
				map[p.first][p.second]--;
				if (map[p.first][p.second] < 0) {
					map[p.first][p.second] = 0;
				}
				continue;
			}
			visited[ny][nx] = true;
			q.push(make_pair(ny, nx));
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}
	return 0;
}