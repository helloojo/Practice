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
//BOJ #2583

int m, n, k;
int map[101][101];
queue<pair<int, int>> q;
vector<int> ret;
int pos[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int bfs(int y, int x) {
	q.push({ x,y });
	map[y][x] = true;
	int ret = 1;
	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = p.first + pos[i][0];
			int ny = p.second + pos[i][1];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (map[ny][nx]) continue;
			ret++;
			map[ny][nx] = true;
			q.push({ nx,ny });
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> m >> n >> k;
	int sx, dx, sy, dy;
	for (int i = 0; i < k; i++) {
		cin >> sx >> sy >> dx >> dy;
		for (int x = sx; x < dx; x++) {
			for (int y = sy; y < dy; y++) {
				map[y][x] = true;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!map[i][j]) {
				ret.push_back(bfs(i, j));
			}
		}
	}
	sort(ret.begin(), ret.end());
	cout << ret.size() << '\n';
	for (int i = 0; i < ret.size(); i++) {
		cout << ret[i] << ' ';
	}
}
