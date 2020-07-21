#include <iostream>
#include <cmath>
using namespace std;
//BOJ #1074
int n, r, c;
int map[16][16];
int ret = -1;
void divide(int sx, int sy, int size) {
	static int order = 0;
	if (size == 2) {
		for (int i = sy; i < sy + size; i++) {
			for (int j = sx; j < sx + size; j++) {
				if (i == r && j == c) {
					ret = order;
				}
				order++;
			}
		}
	} else {
		size /= 2;
		divide(sx, sy, size);
		divide(sx + size, sy, size);
		divide(sx, sy + size, size);
		divide(sx + size, sy + size, size);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> r >> c;
	divide(0, 0, pow(2, n));
	cout << ret;
	return 0;
}