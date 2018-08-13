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
//BOJ #9938

int parent[300001];
bool check[300001];
int n, l;

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

	cin >> n >> l;
	int a, b;
	for (int i = 1; i <= l; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		if (!check[a]) {
			check[a] = true;
			merge(a, b);
			cout << "LADICA\n";
			continue;
		}
		if (!check[b]) {
			check[b] = true;
			merge(b, a);
			cout << "LADICA\n";
			continue;
		}
		int fa = find(a);
		if (!check[fa]) {
			check[fa] = true;
			merge(a, b);
			cout << "LADICA\n";
			continue;
		}
		int fb = find(b);
		if (!check[fb]) {
			check[fb] = true;
			merge(b, a);
			cout << "LADICA\n";
			continue;
		}
		cout << "SMECE\n";
	}
}
