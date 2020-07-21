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
//BOJ #11505
#define DIV 1000000007
typedef long long ll;
ll tree[4000001];
int arr[1000001];

ll make_tree(int left, int right, int here) {
	if (left == right) {
		return tree[here] = arr[left];
	}
	int mid = (left + right) / 2;
	return tree[here] = ((make_tree(left, mid, here * 2) % DIV)*(make_tree(mid + 1, right, here * 2 + 1) % DIV)) % DIV;
}
ll find(int src, int dst, int left, int right, int here) {
	if (left > dst || right < src) return 1;
	if (left >= src && right <= dst) {
		return tree[here];
	}
	int mid = (left + right) / 2;
	return ((find(src, dst, left, mid, here * 2) % DIV)*(find(src, dst, mid + 1, right, here * 2 + 1)))%DIV;
}
ll update(int change, int value, int left, int right, int here) {
	if (change<left || change>right) return tree[here];
	if (left == right) {
		return tree[here] = value;
	}
	int mid = (left + right) / 2;
	return tree[here]=((update(change, value, left, mid, here * 2) % DIV)*(update(change, value, mid + 1, right, here * 2 + 1))) % DIV;
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
			update(b, c, 1, n, 1);
		} else {
			cout << find(b, c, 1, n, 1) << '\n';
		}
	}
}
