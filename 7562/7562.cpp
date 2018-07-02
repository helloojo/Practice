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
//BOJ #7562

struct night {
	int x;
	int y;
	int cnt;
};

int map[301][301];
int pos[8][2] = { {1,2},{2,1},{2,-1},{1,-2},{-1,2},{-2,1},{-2,-1},{-1,-2} };
int l;
int sx, sy;
int dx, dy;
int visit;
queue<night> q;

int bfs() {
	map[sy][sx] = visit;
	q.push({ sx,sy,0 });
	int ret = 9875321;
	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		if (p.x == dx && p.y == dy) {
			ret = min(ret, p.cnt);
		}
		for (int i = 0; i < 8; i++) {
			int nx = p.x + pos[i][0];
			int ny = p.y + pos[i][1];
			if (nx < 0 || ny < 0 || nx >= l || ny >= l) continue;
			if (map[ny][nx] == visit) continue;
			q.push({ nx,ny,p.cnt + 1 });
			map[ny][nx] = visit;
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
		visit++;
		cin >> l;
		cin >> sx >> sy;
		cin >> dx >> dy;
		cout << bfs() << '\n';
	}
}
