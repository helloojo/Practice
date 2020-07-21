#include <iostream>
#include <algorithm>
using namespace std;
//BOJ #3085

char map[51][51];
int n;

int check() {
	int ret = 0;
	for (int i = 0; i < n; i++) {
		int cnt = 1;
		for (int j = 1; j < n; j++) {
			if (map[i][j] == map[i][j - 1]) {
				cnt++;
			} else {
				ret = max(ret, cnt);
				cnt = 1;
			}
		}
		ret = max(ret, cnt);
		cnt = 1;
		for (int j = 1; j < n; j++) {
			if (map[j][i] == map[j - 1][i]) {
				cnt++;
			} else {
				ret = max(ret, cnt);
				cnt = 1;
			}
		}
		ret = max(ret, cnt);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}
	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != n - 1) {
				swap(map[i][j], map[i + 1][j]);
				ret = max(ret, check());
				swap(map[i][j], map[i + 1][j]);
			}
			if (j != n - 1) {
				swap(map[i][j], map[i][j + 1]);
				ret = max(ret, check());
				swap(map[i][j], map[i][j + 1]);
			}
		}
	}
	cout << ret;
}