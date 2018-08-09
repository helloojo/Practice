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
//BOJ #2623

vector<vector<int>> adj;
bool visited[1001];
bool finish[1001];
bool cycle;
vector<int> ret;

void dfs(int here) {
	if (visited[here]) {
		if (!finish[here]) {
			cycle = true;
		}
		return;
	}
	visited[here] = true;
	int size = adj[here].size();
	for (int i = 0; i < size; i++) {
		int next = adj[here][i];
		dfs(next);
	}
	finish[here] = true;
	ret.push_back(here);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	adj.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		int a, b;
		cin >> a;
		for (int j = 1; j < num; j++) {
			cin >> b;
			adj[a].push_back(b);
			a = b;
		}
	}
	for (int i = 1; i <= n; i++) {
		dfs(i);
		if (cycle) {
			break;
		}
	}
	if (cycle) {
		cout << 0;
	} else {
		for (int i = ret.size() - 1; i >= 0; i--) {
			cout << ret[i] << '\n';
		}
	}
}
