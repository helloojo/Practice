#include <iostream>
using namespace std;
//BOJ #1388

char map[101][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}
	int ret = 0;
	for (int i = 0; i < n; i++) {
		bool cont = false;
		int cnt = 0;
		for (int j = 0; j < m; j++) {
			if (!cont && map[i][j] == '-') {
				cont = true;
				cnt++;
			}
			else if (cont && map[i][j] != '-') {
				cont = false;
				cnt = 0;
				ret++;
			} else if (map[i][j] == '-') {
				cnt++;
			}
		}
		if (cnt) {
			ret++;
		}
	}
	for (int i = 0; i < m; i++) {
		bool cont = false;
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (!cont && map[j][i] == '|') {
				cont = true;
				cnt++;
			} else if (cont && map[j][i] != '|') {
				cont = false;
				cnt = 0;
				ret++;
			} else if (map[j][i] == '|') {
				cnt++;
			}
		}
		if (cnt) {
			ret++;
		}
	}
	cout << ret;
}