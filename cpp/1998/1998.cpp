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
//BOJ #1998
char map[129][129];
int quad(int sx, int sy, int dx, int dy) {
	bool can = true;
	char first = map[sy][sx];
	for (int i = sy; i < dy; i++) {
		for (int j = sx; j < dx; j++) {
			if (first != map[i][j]) {
				can = false;
				break;
			}
		}
		if (!can) {
			break;
		}
	}
	if (can) {
		return 1;
	} else {
		int ret = 0;
		ret += quad(sx, sy, (sx + dx) / 2, (sy + dy) / 2);
		ret += quad((sx + dx) / 2, sy, dx, (sy + dy) / 2);
		ret += quad(sx, (sy + dy) / 2, (sx + dx) / 2, dy);
		ret += quad((sx + dx) / 2, (sy + dy) / 2, dx, dy);
		return ret;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}
	cout << n * m + 1 << ' ' << quad(0, 0, m, n);
}
