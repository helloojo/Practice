#include <iostream>
using namespace std;
//BOJ #4963

int map[51][51];
int pos[8][2] = { {0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,1},{1,-1},{-1,-1} };
int w, h;
void dfs(int y, int x) {
	map[y][x] = 0;
	for (int i = 0; i < 8; i++) {
		int ny = y + pos[i][0];
		int nx = x + pos[i][1];
		if (nx < 0 || ny < 0 || nx >= w || ny >= h) {
			continue;
		}
		if (map[ny][nx]) {
			dfs(ny, nx);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> w >> h;
	while (!(w == 0 && h == 0)) {
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}
		int ret = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j]) {
					dfs(i, j);
					ret++;
				}
			}
		}
		cout << ret << '\n';
		cin >> w >> h;
	}	
}