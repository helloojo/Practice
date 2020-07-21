#include <iostream>
using namespace std;

int map[257][257];
int white;
int black;
void make(int sx, int sy, int dx, int dy) {
	int first = map[sy][sx];
	for (int i = sy; i <= dy; i++) {
		for (int j = sx; j <= dx; j++) {
			if (first != map[i][j]) {
				first = -1;
			}
		}
		if (first == -1) {
			break;
		}
	}
	if (first == -1) {
		make(sx, sy, (sx + dx - 1) / 2, (sy + dy - 1) / 2);
		make((sx + dx - 1) / 2 + 1, sy, dx, (sy + dy - 1) / 2);
		make(sx, (sy + dy - 1) / 2 + 1, (sx + dx - 1) / 2, dy);
		make((sx + dx - 1) / 2 + 1, (sy + dy - 1) / 2 + 1, dx, dy);
	} else {
		first ? black++ : white++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		white = 0;
		black = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}
		make(0, 0, n - 1, n - 1);
		cout << white << ' ' << black << '\n';
	}
	return 0;
}