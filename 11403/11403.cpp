#include <iostream>
#include <cstring>
using namespace std;
//BOJ #11403

int map[101][101];
int ret[101][101];
int visited[101];
int n;
void dfs(int start, int here) {
	if (visited[here]) return;
	visited[here] = true;
	for (int i = 0; i < n; i++) {
		if (map[here][i]) {
			ret[start][i] = 1;
			dfs(start, i);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		memset(visited, 0, sizeof(visited));
		dfs(i, i);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ret[i][j] << ' ';
		}
		cout << '\n';
	}
}