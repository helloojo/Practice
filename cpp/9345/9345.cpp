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
//BOJ #9345

pair<int, int> tree[400001];
int arr[100001];

pair<int, int> make(int left, int right, int here) {
	if (left == right) {
		return tree[here] = { arr[left],arr[left] };
	}
	int mid = (left + right) / 2;
	auto l = make(left, mid, here * 2);
	auto r = make(mid + 1, right, here * 2 + 1);
	return tree[here] = { min(l.first,r.first),max(l.second,r.second) };
}
pair<int, int> update(int ch, int val, int left, int right, int here) {
	if (ch<left || ch>right) {
		return tree[here];
	}
	if (left == right) {
		return tree[here] = { val,val };
	}
	int mid = (left + right) / 2;
	auto l = update(ch, val, left, mid, here * 2);
	auto r = update(ch, val, mid + 1, right, here * 2 + 1);
	return tree[here] = { min(l.first,r.first),max(l.second,r.second) };
}
pair<int, int> find(int src, int dst, int left, int right, int here) {
	if (src > right || dst < left) {
		return { 987654321,0 };
	}
	if (src <= left && right <= dst) {
		return tree[here];
	}
	int mid = (left + right) / 2;
	auto l = find(src, dst, left, mid, here * 2);
	auto r = find(src, dst, mid + 1, right, here * 2 + 1);
	return { min(l.first,r.first),max(l.second,r.second) };
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			arr[i] = i;
		}
		make(0, n - 1, 1);
		int q, a, b;
		for (int i = 0; i < k; i++) {
			cin >> q >> a >> b;
			switch (q) {
			case 0:
				update(a, arr[b], 0, n - 1, 1);
				update(b, arr[a], 0, n - 1, 1);
				swap(arr[a], arr[b]);
				break;
			case 1:
				auto f = find(a, b, 0, n - 1, 1);
				if (f == make_pair(a,b)) {
					cout << "YES\n";
				} else {
					cout << "NO\n";
				}
				break;
			}
		}
	}
}
