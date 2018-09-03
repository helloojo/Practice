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
//BOJ #10999
typedef long long ll;
ll arr[1000001];
ll tree[4000001];
ll lazy[4000001];

ll make(int left, int right, int here) {
	if (left == right) {
		return tree[here] = arr[left];
	}
	int mid = (left + right) / 2;
	ll l = make(left, mid, here * 2);
	ll r = make(mid + 1, right, here * 2 + 1);
	return tree[here] = l + r;
}

void update_lazy(int left, int right, int here) {
	if (lazy[here] != 0) {
		tree[here] += (right - left + 1)*lazy[here];
		if (left != right) {
			lazy[here * 2] += lazy[here];
			lazy[here * 2 + 1] += lazy[here];
		}
		lazy[here] = 0;
	}
}

ll update_range(int src, int dst, int left, int right, int here, ll val) {
	update_lazy(left, right, here);
	if (src > right || dst < left) {
		return tree[here];
	}
	if (src <= left && right <= dst) {
		tree[here] += (right - left + 1)*val;
		if (left != right) {
			lazy[here * 2] += val;
			lazy[here * 2 + 1] += val;
		}
		return tree[here];
	}
	int mid = (left + right) / 2;
	ll l = update_range(src, dst, left, mid, here * 2, val);
	ll r = update_range(src, dst, mid + 1, right, here * 2 + 1, val);
	return tree[here] = l + r;
}

ll find(int src, int dst, int left, int right, int here) {
	update_lazy(left, right, here);
	if (src > right || dst < left) {
		return 0;
	}
	if (src <= left && right <= dst) {
		return tree[here];
	}
	int mid = (left + right) / 2;
	ll l = find(src, dst, left, mid, here * 2);
	ll r = find(src, dst, mid + 1, right, here * 2 + 1);
	return l + r;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	make(1, n, 1);
	int a, b, c, d;
	for (int i = 0; i < m + k; i++) {
		cin >> a;
		switch (a) {
		case 1:
			cin >> b >> c >> d;
			update_range(b, c, 1, n, 1, d);
			break;
		case 2:
			cin >> b >> c;
			cout << find(b, c, 1, n, 1) << '\n';
			break;
		}
	}
}
