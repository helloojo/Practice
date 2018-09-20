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
//BOJ #12836

typedef long long ll;
ll tree[40001];
int n, q;

void update(int p, int v) {
	while(p <= n) {
		tree[p] += v;
		p += p & (-p);
	}
}
ll sum(int p) {
	ll ret = 0;
	while(p > 0) {
		ret += tree[p];
		p -= p & (-p);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> q;
	ll a, b, c;
	for(int i = 0; i < q; i++) {
		cin >> a >> b >> c;
		switch(a) {
		case 1:
			update(b, c);
			break;
		case 2:
			cout << sum(c) - sum(b - 1) << '\n';
			break;
		}
	}
}
