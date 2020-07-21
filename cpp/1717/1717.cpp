#include <iostream>
using namespace std;
//BOJ #1717

int parent[1000001];

int find(int a) {
	if (parent[a] == a) {
		return a;
	} else {
		return parent[a] = find(parent[a]);
	}
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	parent[b] = a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	int a, b, c;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (a) {
			if (find(b) == find(c)) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		} else {
			merge(b, c);
		}
	}
	return 0;
}