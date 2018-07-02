#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
//BOJ #1389

int k[101];
bool map[101][101];
int visited[101];
int v_cnt;
int n, m;

int dfs(int here, int cnt) {
	if (visited[here] == v_cnt) {
		return cnt;
	}
	visited[here] = v_cnt;
	int ret = 0;
	for (int i = 1; i <= n; i++) {
		if (map[here][i]) {
			ret += dfs(i, cnt + 1);
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		map[a][b] = true;
		map[b][a] = true;
	}
	v_cnt = 1;
	int minindex = 9999;
	int mine = 98754321;
	for (int i = 1; i <= n; i++) {
		k[i] = dfs(i, 0);
		if (k[i] < mine) {
			minindex = i;
			mine = k[i];
		}
		v_cnt++;
	}
	cout << minindex;
}
