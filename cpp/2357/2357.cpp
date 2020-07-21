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
//BOJ #2357
#define INF 1000000001
int arr[100001];
pair<int, int> tree[400001];

pair<int,int> make(int left, int right, int here) {
	if (left == right) {
		return tree[here] = { arr[left], arr[left] };
	}
	int mid = (left + right) / 2;
	auto l = make(left, mid, here * 2);
	auto r = make(mid+1,right, here * 2 + 1);
	return tree[here] = { min(l.first,r.first),max(l.second,r.second) };
}
pair<int, int> find(int src, int dst, int left, int right, int here) {
	if (src > right || dst < left) {
		return { INF,0 };
	}
	if (left >= src && right <= dst) {
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
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	make(1, n, 1);
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		auto ret = find(a, b, 1, n, 1);
		cout << ret.first << ' ' << ret.second << '\n';
	}
}
