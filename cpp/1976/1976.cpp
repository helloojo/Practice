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
//BOJ #1976

int parent[201];

int find(int here) {
	if (parent[here] == here) {
		return here;
	}
	return parent[here] = find(parent[here]);
}
void merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) {
		return;
	}
	parent[u] = v;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	int num;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> num;
			if (num == 1) {
				merge(i, j);
			}
		}
	}
	int plan[1001];
	for (int i = 0; i < m; i++) {
		cin >> plan[i];
	}
	int cmp = find(plan[0]);
	bool can = true;
	for (int i = 1; i < m; i++) {
		int tmp = find(plan[i]);
		if (cmp != tmp) {
			can = false;
		}
		cmp = tmp;
	}
	cout << (can ? "YES" : "NO");
}
