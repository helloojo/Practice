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
//BOJ #2660
int map[51][51];
int score[51];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int a, b;
	cin >> a >> b;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				map[i][j] = 987654321;
			}
		}
	}
	while (!(a == -1 && b == -1)) {
		map[a][b] = min(map[a][b], 1);
		map[b][a] = min(map[b][a], 1);
		cin >> a >> b;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				map[j][k] = min(map[j][k], map[j][i] + map[i][k]);
			}
		}
	}
	int sc = 987654321;
	for (int i = 1; i <= n; i++) {
		score[i] = *max_element(map[i], map[i] + n + 1);
		sc = min(score[i], sc);
	}
	vector<int> ret;
	for (int i = 1; i <= n; i++) {
		if (sc == score[i]) {
			ret.push_back(i);
		}
	}
	cout << sc << ' ' << ret.size() << '\n';
	for (int i = 0; i < ret.size(); i++) {
		cout << ret[i] << ' ';
	}
}
