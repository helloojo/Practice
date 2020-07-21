#include <iostream>
using namespace std;
//BOJ #1780

int map[2188][2188];
int one, zero, mone;
void divide(int sx, int sy, int size) {
	int first = map[sy][sx];
	for (int i = sy; i < sy + size; i++) {
		for (int j = sx; j < sx + size; j++) {
			if (first != map[i][j]) {
				first = -2;
				break;
			}
		}
		if (first == -2) {
			break;
		}
	}
	if (first == -2) {
		size /= 3;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				divide(sx + size * i, sy + size * j, size);
			}
		}
	} else {
		if (first == 1) {
			one++;
		} else if (first == 0) {
			zero++;
		} else {
			mone++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	divide(0, 0, n);
	cout << mone << '\n' << zero << '\n' << one;
	return 0;
}