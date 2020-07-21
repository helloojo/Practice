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
//BOJ #2243
int tree[4000001];
int update(int ch, int val, int left, int right, int here) {
	if (ch > right || ch < left) {
		return tree[here];
	}
	if (left == right) {
		return tree[here] += val;
	}
	int mid = (left + right) / 2;
	int l = update(ch, val, left, mid, here * 2);
	int r = update(ch, val, mid + 1, right, here * 2 + 1);
	return tree[here] = l + r;
}
int find(int val, int left, int right, int here) {
	if (left == right) {
		return left;
	}
	int mid = (left + right) / 2;
	if (tree[here * 2] < val) {
		return find(val - tree[here * 2], mid + 1, right, here * 2 + 1);
	}
	return find(val, left, mid, here * 2);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int a, b, c;
	int ret;
	for (int i = 0; i < n; i++) {
		cin >> a;
		switch (a) {
		case 1:
			cin >> b;
			ret = find(b, 1, 1000000, 1);
			cout << ret << '\n';
			update(ret, -1, 1, 1000000, 1);
			break;
		case 2:
			cin >> b >> c;
			update(b, c, 1, 1000000, 1);
			break;
		}
	}
}
