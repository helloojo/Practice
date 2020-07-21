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
//BOJ #12899
typedef long long ll;
typedef unsigned long long ull;
int tree[8000001];
int update(int ch, int val, int left, int right, int here) {
	if(left > ch || right < ch) {
		return tree[here];
	}
	if(left == right) {
		return tree[here] += val;
	}
	int mid = (left + right) / 2;
	int l = update(ch, val, left, mid, here * 2);
	int r = update(ch, val, mid + 1, right, here * 2 + 1);
	return tree[here] = l + r;
}
int find(int val, int left, int right, int here) {
	if(left == right) {
		return left;
	}
	int mid = (left + right) / 2;
	if(tree[here * 2] < val) {
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
	int t, x;
	while(n--) {
		cin >> t >> x;
		int ret = 0;
		switch(t) {
		case 1:
			update(x, 1, 1, 2000000, 1);
			break;
		case 2:
			ret = find(x, 1, 2000000, 1);
			update(ret, -1, 1, 2000000, 1);
			cout << ret << '\n';
			break;
		}
	}
}
