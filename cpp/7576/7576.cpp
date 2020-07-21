#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
//BOJ #7576
struct to {
	int x;
	int y;
	int day;
};

int map[1001][1001];
bool visited[1001][1001];
int pos[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
queue<to> q;
int m, n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> m >> n;
	int maxt = m * n;
	int cur = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j]==1) {
				q.push({ j,i,0 });
				visited[i][j] = true;
				cur++;
			} else if (map[i][j] == -1) {
				maxt--;
			}
		}
	}
	if (cur == maxt) {
		cout << 0;
	} else {
		cur = q.size();
		int ret = 0;
		while (!q.empty()) {
			auto p = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = p.x + pos[i][0];
				int ny = p.y + pos[i][1];
				if (nx < 0 || ny < 0 || nx >= m || ny >= n) {
					continue;
				}
				if (visited[ny][nx]) {
					continue;
				}
				if (map[ny][nx] == -1) {
					continue;
				}
				if (map[ny][nx] == 0) {
					map[ny][nx] = 1;
					q.push({ nx,ny,p.day + 1 });
					visited[ny][nx] = true;
					ret = max(p.day + 1, ret);
					cur++;
				}
			}
		}
		if (cur == maxt) {
			cout << ret;
		} else {
			cout << -1;
		}
	}
	return 0;
}