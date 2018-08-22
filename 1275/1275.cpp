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
//BOJ #1275

typedef long long ll;
ll tree[400001];
ll arr[100001];
ll make(int l, int r, int h) {
	if (l == r) {
		return tree[h] = arr[l];
	}
	int mid = (l + r) / 2;
	ll left = make(l, mid, h * 2);
	ll right = make(mid + 1, r, h * 2 + 1);
	return tree[h]=left + right;
}
ll find(int src, int dst, int left, int right, int here) {
	if (src > right || left > dst) {
		return 0;
	}
	if (src <= left && dst >= right) {
		return tree[here];
	}
	int mid = (left + right) / 2;
	ll l = find(src, dst, left, mid, here * 2);
	ll r = find(src, dst, mid + 1, right, here * 2 + 1);
	return l + r;
}
ll update(int ch, int val, int left, int right, int here) {
	if (ch > right || ch < left) {
		return tree[here];
	}
	if (left == right) {
		return tree[here] = val;
	}
	int mid = (left + right) / 2;
	ll l = update(ch, val, left, mid, here * 2);
	ll r = update(ch, val, mid + 1, right, here * 2 + 1);
	return tree[here] = l + r;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	make(1, n, 1);
	int a, b, c, d;
	for (int i = 0; i < q; i++) {
		cin >> a >> b >> c >> d;
		if (a > b) {
			swap(a, b);
		}
		cout << find(a, b, 1, n, 1) << '\n';
		update(c, d, 1, n, 1);
	}
}
