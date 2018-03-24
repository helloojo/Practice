#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
//BOJ #1261

struct Node {
	int x;
	int y;
	int v;
	Node(int _x, int _y, int _v) {
		x = _x;
		y = _y;
		v = _v;
	}
	Node(){}
};
bool operator>(const Node& n,const Node& m) {
	return n.v > m.v;
}
bool operator<(const Node& n, const Node& m) {
	return n.v < m.v;
}
char map[101][101];
int m, n;
priority_queue < Node, vector<Node>,greater<Node>> pq;
int pos[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

int find() {
	int ret = 987654321;
	pq.push(Node(0, 0, map[0][0]-'0'));
	map[0][0] = -1;
	while (!pq.empty()) {
		auto p = pq.top();
		pq.pop();
		if (p.x == m - 1 && p.y == n - 1) {
			ret = min(ret, p.v);
		}
		for (int i = 0; i < 4; i++) {
			int nx = p.x + pos[i][0];
			int ny = p.y + pos[i][1];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n) {
				continue;
			}
			if (map[ny][nx] == -1) {
				continue;
			}
			pq.push(Node(nx, ny, p.v + (map[ny][nx]-'0')));
			map[ny][nx] = -1;
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}
	cout << find();
	return 0;
}