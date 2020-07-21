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
//BOJ #2042

int arr[1000001];
long long tree[4000001];

long long make_tree(int left, int right, int here) {
	if (left == right) {
		return tree[here] = arr[left];
	}
	int mid = (left + right) / 2;
	long long l = make_tree(left, mid, here * 2);
	long long r = make_tree(mid + 1, right, here * 2 + 1);
	return tree[here] = l + r;
}

long long find(int src, int dst, int left, int right, int here) {
	if (left > dst || right < src) {
		return 0;
	}
	if (src <= left && right <= dst) {
		return tree[here];
	}
	int mid = (left + right) / 2;
	long long l = find(src, dst, left, mid, here * 2);
	long long r = find(src, dst, mid + 1, right, here * 2 + 1);
	return l + r;
}

long long update(int ch, int val, int here, int left, int right) {
	if (ch < left || right < ch) {
		return tree[here];
	}
	if (left == right) {
		return tree[here] = val;
	}
	int mid = (left + right) / 2;
	long long l = update(ch, val, here * 2, left, mid);
	long long r = update(ch, val, here * 2 + 1, mid + 1, right);
	return tree[here] = l + r;
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
	make_tree(1, n, 1);
	int a, b, c;
	for (int i = 0; i < m + k; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			update(b, c, 1, 1, n);
		} else {
			cout << find(b, c, 1, n, 1) << '\n';
		}
	}
}
