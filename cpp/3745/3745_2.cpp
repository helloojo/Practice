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
//BOJ #3745

pair<int, int> arr[100001];
int tree[400001];

int update(int ch, int val, int left, int right, int here) {
	if (ch<left || right<ch) {
		return tree[here];
	}
	if (left == right) {
		return tree[here] = val;
	}
	int mid = (left + right) / 2;
	int l = update(ch, val, left, mid, here * 2);
	int r = update(ch, val, mid + 1, right, here * 2 + 1);
	return tree[here]=max(l, r);
}
int find(int src, int dst, int left, int right, int here) {
	if (src > right || dst < left) {
		return 0;
	}
	if (left >= src && dst >= right) {
		return tree[here];
	}
	int mid = (left + right) / 2;
	int l = find(src, dst, left, mid, here * 2);
	int r = find(src, dst, mid + 1, right, here * 2 + 1);
	return max(l, r);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	while (cin >> n) {
		memset(tree, 0, sizeof(tree));
		for (int i = 1; i <= n; i++) {
			cin >> arr[i].first;
			arr[i].second = i;
		}
		sort(arr + 1, arr + 1 + n, [](auto& a, auto& b) {
			return (a.first < b.first ? true : (a.first == b.first ? a.second > b.second: false));
		});
		int ret = 0;
		for (int i = 1; i <= n; i++) {
			int v = find(1, arr[i].second, 1, n, 1) + 1;
			ret = max(ret, update(arr[i].second, v, 1, n, 1));
		}
		cout << ret << '\n';
	}
}
