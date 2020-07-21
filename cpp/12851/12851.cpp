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
//BOJ #12851

bool visited[100001];
queue<pair<int, int>> q;
int bfs(int here, int dest, int minr = -1000) {
	q.push({ here,0 });
	visited[here] = true;
	int ret = 0;
	if (minr == -1000) {
		ret = 987654321;
	}
	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		if (p.first == dest) {
			if (minr == -1000) {
				ret = min(ret, p.second);
			}
		}
		int next = p.first + 1;
		if (next == dest) {
			if (p.second + 1 == minr) {
				ret++;
			}
		}
		if (next>=0 && next<=100000 && !visited[next]) {
			visited[next] = true;
			q.push({ next,p.second + 1 });
		}
		next = p.first - 1;
		if (next == dest) {
			if (p.second + 1 == minr) {
				ret++;
			}
		}
		if (next >= 0 && next <= 100000 && !visited[next]) {
			visited[next] = true;
			q.push({ next,p.second + 1 });
		}
		next = p.first * 2;
		if (next == dest) {
			if (p.second + 1 == minr) {
				ret++;
			}
		}
		if (next >= 0 && next <= 100000 && !visited[next]) {
			visited[next] = true;
			q.push({ next,p.second + 1 });
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	int minr = bfs(n, k);
	memset(visited, 0, sizeof(visited));
	cout << minr << '\n';
	cout << bfs(n, k, minr) << '\n';
}
