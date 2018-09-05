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
//BOJ #12844

int arr[500001];
int tree[2000001];
int lazy[2000001];

int make(int left, int right, int here) {
	if (left == right) {
		return tree[here] ^= arr[left];
	}
	int mid = (left + right) / 2;
	int l = make(left, mid, here * 2);
	int r = make(mid + 1, right, here * 2 + 1);
	return tree[here] = (l ^ r);
}

void update_lazy(int left, int right, int here) {
	if (lazy[here] != 0) {
		if ((right - left + 1) & 1) {
			tree[here] ^= lazy[here];
		}
		if (left != right) {
			lazy[here * 2] ^= lazy[here];
			lazy[here * 2 + 1] ^= lazy[here];
		}
		lazy[here] = 0;
	}
}

int update_range(int src, int dst, int left, int right, int here, int val) {
	update_lazy(left, right, here);
	if (src > right || dst < left) {
		return tree[here];
	}
	if (src <= left && right <= dst) {
		if (left != right) {
			lazy[here * 2] ^= val;
			lazy[here * 2 + 1] ^= val;
		}
		if ((right-left+1) & 1) {
			return tree[here] ^= val;
		} else {
			return tree[here];
		}
	}
	int mid = (left + right) / 2;
	int l = update_range(src, dst, left, mid, here * 2, val);
	int r = update_range(src, dst, mid + 1, right, here * 2 + 1, val);
	return tree[here] = (l ^ r);
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
	return (l ^ r);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	make(0, n - 1, 1);
	int m;
	cin >> m;
	int t, a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> t;
		switch (t) {
		case 1:
			cin >> a >> b >> c;
			if (a > b) {
				swap(a, b);
			}
			update_range(a, b, 0, n - 1, 1, c);
			break;
		case 2:
			cin >> a >> b;
			if (a > b) {
				swap(a, b);
			}
			cout << find(a, b, 0, n - 1, 1) << '\n';
			break;
		}
	}
}
