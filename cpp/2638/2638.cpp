#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
//BOJ #2638
int map[101][101];
int visit[101][101];
int pos[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
enum { OUT=1, IN=2, CHEESE=3 };
queue<pair<int, int>> q;
int n, m;
int bfs(int y, int x,int check) {
	visit[y][x] = check;
	q.push(make_pair(y, x));
	int ret = 0;
	if (check == OUT) {
		ret++;
	}
	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		int outcnt = 0;
		for (int i = 0; i < 4; i++) {
			int nx = p.second + pos[i][1];
			int ny = p.first + pos[i][0];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n) {
				continue;
			}
			switch (check) {
			case OUT:
				if (visit[ny][nx] != 0) {
					continue;
				}
				if (map[ny][nx] == 1) {
					continue;
				}
				visit[ny][nx] = check;
				q.push(make_pair(ny, nx));
				ret++;
				break;
			case IN:
				if (visit[ny][nx] != 0) {
					continue;
				}
				if (map[ny][nx] == 1) {
					continue;
				}
				visit[ny][nx] = check;
				q.push(make_pair(ny, nx));
				break;
			case CHEESE:
				if (visit[ny][nx] == OUT) {
					outcnt++;
					continue;
				}
				if (visit[ny][nx] != 0) {
					continue;
				}
				visit[ny][nx] = check;
				q.push(make_pair(ny, nx));
				break;
			}
		}
		if (outcnt >= 2) {
			map[p.first][p.second] = 0;
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
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	int whitecnt = 0;
	int time = -1;
	while (whitecnt != n * m) {
		time++;
		memset(visit, 0, sizeof(visit));
		whitecnt=bfs(0, 0,OUT);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (visit[i][j]!=OUT) {
					if (map[i][j] == 0) {
						bfs(i, j, IN);
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (visit[i][j]!=IN && visit[i][j]!=OUT) {
					if (map[i][j]) {
						bfs(i, j, CHEESE);
					}
				}
			}
		}
	}
	cout << time;
	return 0;
}