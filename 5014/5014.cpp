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
//BOJ #5014

int f, s, g, u, d;
bool visited[1000001];
queue<pair<int,int>> q;

int bfs(int here) {
	visited[here] = true;
	q.push({ here,0 });
	int ret = 987654321;
	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		if (p.first == g) {
			ret = min(ret, p.second);
			continue;
		}
		if (p.first + u <= f) {
			if (!visited[p.first + u]) {
				visited[p.first + u] = true;
				q.push({ p.first + u,p.second + 1 });
			}
		}
		if (p.first - d > 0) {
			if (!visited[p.first - d]) {
				visited[p.first - d] = true;
				q.push({ p.first - d,p.second + 1 });
			}
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> f >> s >> g >> u >> d;
	int ret=bfs(s);
	if (ret == 987654321) {
		cout << "use the stairs";
	} else {
		cout << ret;
	}
}
