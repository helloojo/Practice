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
//BOJ #1613
int map[401][401];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	int a, b;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				map[i][j] = 987654321;
			}
		}
	}
	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		map[a][b] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				map[j][k] = min(map[j][k], map[j][i] + map[i][k]);
			}
		}
	}
	int s;
	cin >> s;
	for (int i = 0; i < s; i++) {
		cin >> a >> b;
		if (map[a][b] == 987654321) {
			if (map[b][a] == 987654321) {
				cout << 0 << '\n';
			} else {
				cout << 1 << '\n';
			}
		} else {
			cout << -1 << '\n';
		}
	}
}
