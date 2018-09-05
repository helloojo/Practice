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
//BOJ #1395

int tree[400001];
int lazy[400001];
int n, m;
void update_lazy(int left, int right, int here) {
	int len = right - left + 1;
	if (lazy[here] != 0) {
		tree[here] = lazy[here] * len - tree[here];
		if (left != right) {
			lazy[here * 2] = !lazy[here * 2];
			lazy[here * 2 + 1] = !lazy[here * 2 + 1];
		}
		lazy[here] = 0;
	}
}

int update_range(int src, int dst, int left, int right, int here) {
	update_lazy(left, right, here);
	if (src > right || dst < left) {
		return tree[here];
	}
	int len = right - left + 1;
	if (src <= left && right <= dst) {
		if (left != right) {
			lazy[here * 2] = !lazy[here * 2];
			lazy[here * 2 + 1] = !lazy[here * 2 + 1];
		}
		return tree[here] = len - tree[here];
	}
	int mid = (left + right) / 2;
	int l = update_range(src, dst, left, mid, here * 2);
	int r = update_range(src, dst, mid + 1, right, here * 2 + 1);
	return tree[here] = l + r;
}

int find(int src, int dst, int left, int right, int here) {
	update_lazy(left, right, here);
	if (src > right || dst < left) {
		return 0;
	}
	if (src <= left && right <= dst) {
		return tree[here];
	}
	int mid = (left + right) / 2;
	int l = find(src, dst, left, mid, here * 2);
	int r = find(src, dst, mid + 1, right, here * 2 + 1);
	return (l + r);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (a) {
			cout << find(b, c, 1, n, 1) << '\n';
		} else {
			update_range(b, c, 1, n, 1);
		}
	}
}