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
//BOJ #12015



typedef long long ll;
int tree[4000001];
pair<int, int> arr[1000001];

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
int update(int ch, int val, int left, int right, int here) {
	if (ch > right || ch < left) {
		return tree[here];
	}
	if (left == right) {
		return tree[here] = val;
	}
	int mid = (left + right) / 2;
	int l = update(ch, val, left, mid, here * 2);
	int r = update(ch, val, mid + 1, right, here * 2 + 1);
	return tree[here] = max(l, r);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i].first;
		arr[i].second = i;
	}
	sort(arr + 1, arr + n + 1, [](pair<int, int>& a, pair<int, int>& b) {
		return (a.first<b.first ? true : (a.first==b.first ? a.second>b.second : false));
	});

	int ret = 0;
	for (int i = 1; i <= n; i++) {
		int v = find(1, arr[i].second, 1, n, 1) + 1;
		ret = max(ret, update(arr[i].second, v, 1, n, 1));
	}
	cout << ret;
}
