#include <iostream>
#include <algorithm>
#include <vector>
//BOJ #14500
using namespace std;

int n, m;
int map[501][501];
vector<vector<vector<pair<int, int>>>> tetris{
	{
		{{0,0},{1,0},{2,0},{3,0}},
		{{0,0},{0,1},{0,2},{0,3}}
	},
	{
		{{0,0},{1,0},{0,1},{1,1}}
	},
	{
		{{0, 0}, {0, 1}, {1, 1}, {2, 1}},
		{{0, 0}, {1, 0}, {0, 1}, {0, 2}},
		{{0, 0}, {1, 0}, {2, 0}, {2, 1}},
		{{1, 0}, {1, 1}, {1, 2}, {0, 2}}
	},
	{
		{{2, 0}, {2, 1}, {1, 1}, {0, 1}},
		{{0, 0}, {0, 1}, {0, 2}, {1, 2}},
		{{0, 0}, {0, 1}, {1, 0}, {2, 0}},
		{{0, 0}, {1, 0}, {1, 1}, {1, 2}}
	},
	{
		{{0, 1}, {1, 1}, {1, 0}, {2, 0}},
		{{0, 0}, {0, 1}, {1, 1}, {1, 2}},
		{{0, 1}, {1, 1}, {1, 0}, {2, 0}},
		{{0, 0}, {0, 1}, {1, 1}, {1, 2}}
	},
	{
		{{0, 1}, {1, 1}, {1, 0}, {2, 1}},
		{{0, 0}, {0, 1}, {1, 1}, {0, 2}},
		{{0, 0}, {1, 0}, {1, 1}, {2, 0}},
		{{0, 1}, {1, 0}, {1, 1}, {1, 2}}
	},
	{
		{{0, 0}, {1, 0}, {1, 1}, {2, 1}},
		{{1, 0}, {1, 1}, {0, 1}, {0, 2}},
		{{0, 0}, {1, 0}, {1, 1}, {2, 1}},
		{{1, 0}, {1, 1}, {0, 1}, {0, 2}}
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	int ret = 0;
	int ts1 = tetris.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int p = 0; p < ts1; p++) {
				int ts2 = tetris[p].size();
				for (int q = 0; q < ts2; q++) {
					int cur = 0;
					int ts3 = tetris[p][q].size();
					for (int r = 0; r < ts3; r++) {
						int nx = j + tetris[p][q][r].first;
						int ny = i + tetris[p][q][r].second;
						if (nx < 0 || ny < 0 || nx >= m || ny >= n) {
							cur = 0;
							break;
						}
						cur += map[ny][nx];
					}
					ret = max(ret, cur);
				}
			}
		}
	}
	cout << ret;
	return 0;
}