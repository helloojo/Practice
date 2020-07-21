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
//BOJ #11780
int map[101][101];
int map2[101][101];

void print(int cur, int next, vector<int>& v) {
	if (map[cur][next] == 987654321) {
		return;
	}
	if (map2[cur][next] == 0) {
		v.push_back(cur);
		return;
	}
	print(cur, map2[cur][next], v);
	print(map2[cur][next], next, v);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				map[i][j] = 987654321;
			}
		}
	}
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		map[a][b] = min(map[a][b], c);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (map[j][k] > map[j][i] + map[i][k]) {
					map[j][k] = map[j][i] + map[i][k];
					map2[j][k] = i;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << (map[i][j] == 987654321 ? 0 : map[i][j]) << ' ';
		}
		cout << '\n';
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				vector<int> v;
				print(i, j, v);
				cout << v.size() + 1 << ' ';
				for (int k = 0; k < v.size(); k++) {
					cout << v[k] << ' ';
				}
				cout << j << '\n';
			} else {
				cout << 0 << '\n';
			}
		}
	}
}
