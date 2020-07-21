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
//BOJ #10026
int n;
char map[101][101];
int visited[101][101];
int cnt;
int pos[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
queue<pair<int, int>> q;

void bfs(int y, int x, int type, char color) {
	q.push({ y,x });
	visited[y][x] = cnt;
	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = pos[i][0] + p.second;
			int ny = pos[i][1] + p.first;
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
				continue;
			}
			if (visited[ny][nx] == cnt) {
				continue;
			}
			if (type) {
				if (color == 'B') {
					if (map[ny][nx] == 'R' || map[ny][nx] == 'G') {
						continue;
					}
				} else {
					if (map[ny][nx] == 'B') {
						continue;
					}
				}
			} else {
				if (color != map[ny][nx]) {
					continue;
				}
			}
			visited[ny][nx] = cnt;
			q.push({ ny,nx });
		}
	}
}

void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << visited[i][j] << ' ';
		}
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}

	cnt = 1;
	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] != cnt) {
				bfs(i, j, 0, map[i][j]);
				ret++;
			}
		}
	}
	cout << ret << ' ';
	cnt = 2;
	ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] != cnt) {
				bfs(i, j, 1, map[i][j]);
				ret++;
			}
		}
	}
	cout << ret;
}
