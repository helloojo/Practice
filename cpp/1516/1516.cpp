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
//BOJ #1516

vector<vector<int>> adj;
vector<int> tt;
vector<int> in;
vector<int> ret;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int a, b = 0;
	adj.resize(n + 1);
	tt.resize(n + 1);
	in.assign(n + 1, 0);
	ret.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a;
		tt[i] = a;
		cin >> b;
		while (b != -1) {
			adj[b].push_back(i);
			cin >> b;
			in[i]++;
		}
	}
	priority_queue<pair<int, int>> q;
	for (int i = 1; i <= n; i++) {
		if (in[i] == 0) {
			q.push({ -tt[i],i });
		}
	}
	while (!q.empty()) {
		auto p = q.top();
		q.pop();
		int here = p.second;
		int weight = -p.first;
		ret[here] = weight;
		int size = adj[here].size();
		for (int i = 0; i < size; i++) {
			int next = adj[here][i];
			in[next]--;
			if (in[next] == 0) {
				q.push({ -(weight + tt[next]), next });
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << ret[i] << endl;
	}
}
