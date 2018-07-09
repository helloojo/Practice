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
//BOJ #9328

int h, w;
char map[102][102];
bool visited[102][102];
int pos[4][2] = { { 0,1 },{ 0,-1 },{ 1,0 },{ -1,0 } };
queue<pair<int, int>> q;
bool key[26];
int ret;
int bfs(int y, int x) {
	visited[y][x] = true;
	q.push({ y,x });
	int cnt = 1;
	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = pos[i][0] + p.second;
			int ny = pos[i][1] + p.first;
			if (nx < 0 || ny < 0 || nx > w || ny > h) continue;
			if (visited[ny][nx] || map[ny][nx] == '*') continue;
			if (map[ny][nx] >= 'A' && map[ny][nx] <= 'Z') {
				if (!key[map[ny][nx] - 'A' + 'a']) {
					continue;
				}
			}
			if (map[ny][nx] >= 'a' && map[ny][nx] <= 'z') {
				key[map[ny][nx] - 'a'] = true;
			}
			if (map[ny][nx] == '$') {
				ret++;
			}
			map[ny][nx] = '.';
			visited[ny][nx] = true;
			q.push({ ny,nx });
			cnt++;
		}
	}
	return cnt;
}

void print() {
	for (int i = 1; i <= h; i++) {
		for (int j = 0; j < w; j++) {
			cout << map[i][j];
		}
		cout << '\n';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		memset(key, 0, sizeof(key));
		memset(visited, 0, sizeof(visited));
		cin >> h >> w;
		for (int i = 1; i <= h; i++) {
			cin >> map[i];
		}
		string s;
		cin >> s;
		for (int i = 0; i < s.size(); i++) {
			key[s[i] - 'a'] = true;
		}
		ret = 0;
		int prev = 0;
		int cur = 987654321;
		while (prev != cur) {
			memset(visited, 0, sizeof(visited));
			prev = cur;
			cur = bfs(0, 0);
			print();
		}
		cout << ret << '\n';
	}
}
