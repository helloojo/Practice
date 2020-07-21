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
//BOJ #12893
bool ret = true;
int parent[2001];
int enemy[2001];

int find(int here) {
	if (parent[here] == here || here == -1) {
		return here;
	}
	return parent[here] = find(parent[here]);
}

void merge(int u, int v) {
	u = find(u);
	v = find(v);
	int ue = find(enemy[u]);
	int ve = find(enemy[v]);
	if (u == ve || v == ue) {
		return;
	}
	if (ue != -1) {
		parent[ue] = v;
	}
	if (ve != -1) {
		parent[ve] = u;
	}
	enemy[u] = v;
	enemy[v] = u;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	int a, b;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		enemy[i] = -1;
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		merge(a, b);
	}
	for (int i = 1; i <= n; i++) {
		if (parent[i] == enemy[i]) {
			ret = false;
		}
	}

	cout << ret;
}
