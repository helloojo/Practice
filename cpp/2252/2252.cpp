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
//BOJ #2252
int n, m;
vector<int> in;
vector<vector<int>> adj;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	adj = vector<vector<int>>(n + 1);
	in = vector<int>(n + 1);
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		in[b]++;
	}
	queue<int> q;

	for (int i = 1; i <= n; i++) {
		if (in[i] == 0) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int p = q.front();
		q.pop();
		cout << p << ' ';
		for (int i = 0; i < adj[p].size(); i++) {
			int next = adj[p][i];
			in[next]--;
			if (in[next] == 0) {
				q.push(next);
			}
		}
	}
}
