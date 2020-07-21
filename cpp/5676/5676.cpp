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
//BOJ #5676

int arr[100001];
char tree[400001];

int make(int l, int r, int h) {
	if (l == r) {
		if (arr[l] > 0) {
			tree[h] = 1;
		} else if (arr[l] < 0) {
			tree[h] = -1;
		} else {
			tree[h] = 0;
		}
		return tree[h];
	}
	int m = (l + r) / 2;
	return tree[h] = make(l, m, h * 2)*make(m + 1, r, h * 2 + 1);
}
int find(int s, int d, int l, int r, int h) {
	if (s > r || d < l) return 1;
	if (s <= l && r <= d) {
		return tree[h];
	}
	int m = (l + r) / 2;
	return find(s, d, l, m, h * 2)*find(s, d, m + 1, r, h * 2 + 1);
}
int update(int c, int v, int l, int r, int h) {
	if (c < l || r < c) return tree[h];
	if (l == r) {
		if (v > 0) {
			tree[h] = 1;
		} else if (v < 0) {
			tree[h] = -1;
		} else {
			tree[h] = 0;
		}
		return tree[h];
	}
	int m = (l + r) / 2;
	return tree[h] = update(c, v, l, m, h * 2)*update(c, v, m + 1, r, h * 2 + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	while (cin >> n >> k) {
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}
		make(1, n, 1);
		char c;
		int a, b;
		int result;
		for (int i = 0; i < k; i++) {
			cin >> c >> a >> b;
			switch (c) {
			case 'P':
				result = find(a, b, 1, n, 1);
				if (result > 0) {
					cout << "+";
				} else if (result < 0) {
					cout << "-";
				} else {
					cout << "0";
				}
				break;
			case 'C':
				update(a, b, 1, n, 1);
				break;
			}
		}
		cout << '\n';
	}
}
