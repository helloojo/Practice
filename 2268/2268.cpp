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
//BOJ #2268
typedef long long ll;
ll tree[4000001];

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

ll find(int src, int dst, int left, int right, int here) {
	if (src > right || dst < left) {
		return 0;
	}
	if (left >= src && dst >= right) {
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
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		switch (a) {
		case 0:
			if (b > c) {
				swap(b, c);
			}
			cout << find(b, c, 1, n, 1) << '\n';
			break;
		case 1:
			update(b, c, 1, n, 1);
			break;
		}
	}
}
