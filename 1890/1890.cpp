#include <iostream>
using namespace std;
//BOJ #1890
typedef unsigned long long int;
int map[101][101];
int memo[101][101];
int n;

int finds(int y = 0, int x = 0) {
	if (x < 0 || y < 0 || x >= n || y >= n) {
		return 0;
	}
	if (x == n - 1 && y == n - 1) {
		return 1;
	}
	if (!map[y][x]) {
		return 0;
	}
	if (memo[y][x]) {
		return memo[y][x];
	}
	return memo[y][x] += finds(y + map[y][x], x) + finds(y, x + map[y][x]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(Nint);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	cout << finds();
	return 0;
}