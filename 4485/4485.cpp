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
//BOJ #4485

int map[126][126];
int dis[126][126];
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
int pos[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int n;

int dijkstra() {
	pq.push({ map[0][0],{0,0} });
	while (!pq.empty()) {
		auto p = pq.top();
		pq.pop();
		auto coor = p.second;
		if (dis[coor.first][coor.second] != 987654321) {
			continue;
		}
		dis[coor.first][coor.second] = p.first;
		for (int i = 0; i < 4; i++) {
			int nx = coor.second + pos[i][0];
			int ny = coor.first + pos[i][1];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
				continue;
			}
			int weight = p.first + map[ny][nx];
			if (dis[ny][nx] == 987654321) {
				pq.push({ weight,{ ny,nx } });
			}
		}
	}
	return dis[n - 1][n - 1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	int t = 1;
	while (n != 0) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dis[i][j] = 987654321;
				cin >> map[i][j];
			}
		}
		cout << "Problem " << t++ << ": " << dijkstra() << '\n';
		cin >> n;
	}
}
