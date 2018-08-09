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
//BOJ #1766

vector<vector<int>> adj;
vector<int> in;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	int a, b;
	adj = vector<vector<int>>(n + 1);
	in = vector<int>(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		in[b]++;
	}
	priority_queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (in[i] == 0) {
			q.push(-i);
		}
	}
	while (!q.empty()) {
		int p = -q.top();
		q.pop();
		cout << p << ' ';
		for (int i = 0; i < adj[p].size(); i++) {
			int next = adj[p][i];
			in[next]--;
			if (in[next] == 0) {
				q.push(-next);
			}
		}
	}
}
