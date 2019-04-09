#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
using namespace std;
//BOJ #17135
typedef long long ll;
typedef unsigned long long ull;

int map[16][16];
int copymap[16][16];
int n, m, d;

void cp() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			copymap[i][j] = map[i][j];
		}
	}
}

void down() {
	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < m; j++) {
			copymap[i][j] = (copymap[i - 1][j]==1 ? 1:0);
		}
	}
	for (int i = 0; i < m; i++) {
		copymap[0][i] = 0;
	}
}

int caldis(int x1, int y1, int x2, int y2) {
	return abs(x2 - x1) + abs(y2 - y1);
}

int simulate(int i, int j, int k) {
	int arr[3] = { i,j,k };
	int kill = 0;
	for (int day = 0; day < 15; day++) {
		for (int a = 0; a < 3; a++) {
			int mind = 987654321;
			pair<int, int> minpos;
			for (int i = 0; i < m; i++) {
				for (int j = n - 1; j >= 0; j--) {
					if (copymap[j][i]) {
						int cald = caldis(i, j, arr[a], n);
						if (cald < mind) {
							if (cald <= d) {
								mind = cald;
								minpos = { i,j };
							}
						}
					}
				}
			}
			if (mind != 987654321) {
				if (copymap[minpos.second][minpos.first] == 1) {
					kill++;
				}
				copymap[minpos.second][minpos.first] = 2;
			}
		}
		down();
	}
	return kill;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	int ret = 0;
	for (int i = 0; i < m; i++) {
		for (int j = i + 1; j < m; j++) {
			for (int k = j + 1; k < m; k++) {
				cp();
				ret = max(ret, simulate(i, j, k));
			}
		}
	}
	cout << ret;
}
