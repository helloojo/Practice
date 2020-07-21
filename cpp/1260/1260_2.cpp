#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
//BOJ #1260

bool map[1001][1001];
bool visited[1001];
queue<int> q;
int n, m, v;

void dfs(int here) {
	if (visited[here]) {
		return;
	}
	visited[here] = true;
	cout << here << ' ';
	for (int i = 1; i <= n; i++) {
		if (map[here][i]) {
			if (!visited[i]) {
				dfs(i);
			}
		}
	}
}
void bfs(int here) {
	q.push(here);
	visited[here] = true;
	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		cout << p << ' ';
		for (int i = 1; i <= n; i++) {
			if (map[p][i]) {
				if (!visited[i]) {
					visited[i] = true;
					q.push(i);
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> v;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}
	dfs(v);
	memset(visited, 0, sizeof(visited));
	cout << '\n';
	bfs(v);
}
