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
//BOJ #1944

struct coor {
	int x;
	int y;
	int dis;
};

char map[51][51];
int number[51][51];
int pos[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int n, m;
vector<pair<int, int>> coord;
priority_queue<pair<int, pair<int, int>>> pq;
int parent[252];

int bfs(int sx, int sy) {
	bool visited[51][51] = { 0 };
	queue<coor> q;
	q.push({ sx,sy,0 });
	visited[sy][sx] = true;
	int cnt = 0;
	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = pos[i][0] + p.x;
			int ny = pos[i][1] + p.y;
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
				continue;
			}
			if (map[ny][nx] == '1' || visited[ny][nx]) {
				continue;
			}
			if (map[ny][nx] == 'S' || map[ny][nx] == 'K') {
				pq.push({ -(p.dis + 1),{number[sy][sx],number[ny][nx]} });
				cnt++;
			}
			q.push({ nx,ny,p.dis + 1 });
			visited[ny][nx] = true;
		}
	}
	return cnt;
}


int find(int here) {
	if (parent[here] == here) {
		return here;
	}
	return parent[here] = find(parent[here]);
}
int merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) {
		return false;
	}
	parent[u] = v;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	int cnt = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'S' || map[i][j] == 'K') {
				coord.push_back({ i,j });
				number[i][j] = cnt++;
			}
		}
	}
	for (int i = 0; i < 252; i++) {
		parent[i] = i;
	}
	bool can = true;
	for (int i = 0; i < coord.size(); i++) {
		if (bfs(coord[i].second, coord[i].first) != m) {
			can = false;
		}
		parent[i + 1] = i + 1;
	}
	int ret = 0;
	while (!pq.empty()) {
		auto p = pq.top();
		pq.pop();
		if (merge(p.second.first, p.second.second)) {
			ret += -p.first;
		}
	}
	cout << (can ? ret : -1);
}
