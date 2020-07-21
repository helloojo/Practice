#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
//BOJ #1697

bool visited[100001];
int n, k;
queue<pair<int, int>> q;
int bfs(int here) {
	q.push({ here,0 });
	visited[here] = true;
	int ret = 987654321;
	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		if (p.first == k) {
			ret = min(p.second, ret);
		}
		if (p.first + 1 <= 100000) {
			if (!visited[p.first + 1]) {
				visited[p.first + 1] = true;
				q.push({ p.first + 1,p.second + 1 });
			}
		}
		if (p.first - 1 >= 0) {
			if (!visited[p.first - 1]) {
				visited[p.first - 1] = true;
				q.push({ p.first - 1,p.second + 1 });
			}
		}
		if (p.first * 2 <= 100000) {
			if (!visited[p.first * 2]) {
				visited[p.first * 2] = true;
				q.push({ p.first * 2,p.second + 1 });
			}
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	cout << bfs(n);
}