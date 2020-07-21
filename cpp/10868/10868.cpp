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
//BOJ #10868
#define INF 1000000001
int arr[100001];
int tree[400001];

int make_tree(int left, int right, int here) {
	if (left == right) {
		return tree[here] = arr[left];
	}
	int mid = (left + right) / 2;
	int lmin = make_tree(left, mid, here * 2);
	int rmin = make_tree(mid + 1, right, here * 2 + 1);
	return tree[here] = min(lmin, rmin);
}
int find(int src, int dst, int here, int left, int right) {
	if (dst < left || right < src) {
		return INF;
	}
	if (src <= left && right <= dst) {
		return tree[here];
	}
	int mid = (left + right) / 2;
	return min(find(src, dst, here * 2, left, mid), find(src, dst, here * 2 + 1, mid + 1, right));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= 4 * n; i++) {
		tree[i] = INF;
	}
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	make_tree(1, n, 1);
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		cout << find(a, b, 1, 1, n) << '\n';
	}
}
