#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
//BOJ #2667

int map[26][26];
bool visited[26][26];
int pos[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int n;

queue<pair<int, int>> q;
vector<int> cc;
int bfs(int y, int x) {
	q.push({ x,y });
	int cnt = 1;
	visited[y][x] = true;
	while (!q.empty()) {
		auto p = q.front();
		q.pop(); 
		for (int i = 0; i < n; i++) {
			int nx = pos[i][0] + p.first;
			int ny = pos[i][1] + p.second;
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (!map[ny][nx] || visited[ny][nx]) continue;
			cnt++;
			visited[ny][nx] = true;
			q.push({ nx,ny });
		}
	}
	return cnt;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j]) {
				if (!visited[i][j]) {
					ret++;
					cc.push_back(bfs(i, j));
				}
			}
		 }
	}
	sort(cc.begin(), cc.end());
	printf("%d\n", ret);
	for (int i = 0; i < cc.size(); i++) {
		printf("%d\n", cc[i]);
	}
}
