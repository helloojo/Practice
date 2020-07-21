#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;
//BOJ #15971
typedef long long ll;
typedef unsigned long long ull;
vector<pair<int, int>> graph[100001];
int n, one, two;
int visited[100001][2];
int ret = 987654321;
void bfs(int here, int type) {
	queue<pair<int, int>> q;
	q.push({ here,0 });
	visited[here][type] = -1;
	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		for (int i = 0; i < graph[p.first].size(); i++) {
			int next = graph[p.first][i].first;
			int weight = p.second + graph[p.first][i].second;
			if (type) {
				ret = min(ret, p.second + (next==one ? 0 : visited[next][0]));
			}
			if (visited[next][type]) {
				continue;
			}
			visited[next][type] = weight;
			q.push({ next,weight });
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> one >> two;
	int a, b, c;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}
	if (one == two || n==2) {
		cout << 0;
	} else {
		bfs(one, 0);
		bfs(two, 1);
		cout << ret;
	}
}
