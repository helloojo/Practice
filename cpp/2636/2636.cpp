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
//BOJ #2636
int map[101][101];
bool visited[101][101];
queue<pair<int, int>> q;
int pos[4][2] = { { 0,1 },{ 0,-1 },{ 1,0 },{ -1,0 } };
int n, m;

int bfs() {
	visited[0][0] = true;
	q.push({ 0,0 });
	int cnt = 0;
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
			if (map[ny][nx] == 1) {
				visited[ny][nx] = true;
				map[ny][nx] = 0;
				cnt++;
				continue;
			}
			q.push({ ny,nx });
			visited[ny][nx] = true;
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	int prev = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (!map[i][j]) {
				cnt++;
			}
		}
	}
	int ret = -1;
	do {
		ret++;
		memset(visited, 0, sizeof(visited));
		prev = cnt;
		cnt = bfs();
	} while (cnt != 0);
	cout << ret << '\n';
	cout << prev;

}
