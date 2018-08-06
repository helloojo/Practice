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
//BOJ #1956

int map[401][401];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int v, e;
	cin >> v >> e;
	int a, b, c;
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			map[i][j] = 987654321;
		}
	}
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		map[a][b] = c;
	}
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			for (int k = 1; k <= v; k++) {
				map[j][k] = min(map[j][k], map[j][i] + map[i][k]);
			}
		}
	}
	int ret = 987654321;
	for (int i = 1; i <= v; i++) {
		ret = min(ret, map[i][i]);
	}
	cout << (ret==987654321 ? -1 : ret);

}
