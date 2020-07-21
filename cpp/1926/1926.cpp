#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;
//BOJ #1926
typedef long long ll;
typedef unsigned long long ull;

bool mapp[501][501];
int pos[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int n, m;

int bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push({ y,x });
	mapp[y][x] = 0;
	int ret = 0;
	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		ret++;
		for (int i = 0; i < 4; i++) {
			int ny = p.first + pos[i][0];
			int nx = p.second + pos[i][1];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (!mapp[ny][nx]) continue;
			mapp[ny][nx] = 0;
			q.push({ ny,nx });
		}
	}
	return ret;
}
queue<pair<int, int>> qq;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mapp[i][j];
			if (mapp[i][j]) {
				qq.push({ i,j });
			}
		}
	}
	int ret = 0;
	int cnt = 0;
	while (!qq.empty()) {
		auto p = qq.front();
		qq.pop();
		if (mapp[p.first][p.second]) {
			ret = max(ret, bfs(p.first, p.second));
			cnt++;
		}
	}
	cout << cnt << '\n' << ret;
}
