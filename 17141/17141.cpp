#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
//BOJ #17141
typedef long long ll;
typedef unsigned long long ull;

int n, m, cidx, v;
int map[51][51];
int visited[51][51];
pair<int, int> cand[10];
int arr[11] = { -1 };
int pos[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int allspace;

int bfs(int level) {
	queue<pair<int, pair<int, int>>> q;
	int cnt = 0;
	int ret = 0;
	for (int i = 1; i < level; i++) {
		q.push({ 0,cand[arr[i]] });
		visited[cand[arr[i]].first][cand[arr[i]].second] = v;
	}
	while (!q.empty()) {
		int time = q.front().first;
		auto p = q.front().second;
		q.pop();
		ret = max(ret, time);
		cnt++;
		for (int i = 0; i < 4; i++) {
			int nx = p.second + pos[i][0];
			int ny = p.first + pos[i][1];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
				continue;
			}
			if (visited[ny][nx] == v) {
				continue;
			}
			if (map[ny][nx] == 1) {
				continue;
			}
			visited[ny][nx] = v;
			q.push({ time + 1,{ny,nx} });
		}
	}
	return (allspace == cnt ? ret : 987654321);
}

int solve(int level = 1) {
	if (level > m) {
		v++;
		return bfs(level);
	}
	int ret = 987654321;
	for (int i = arr[level - 1] + 1; i < cidx; i++) {
		arr[level] = i;
		ret = min(ret, solve(level + 1));
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	cidx = 0;
	allspace = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				cand[cidx++] = { i,j };
				allspace++;
			} else if (map[i][j] == 0) {
				allspace++;
			}
		}
	}
	int ret = solve();
	cout << (ret == 987654321 ? -1 : ret);
}
