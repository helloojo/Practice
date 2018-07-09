#include <iostream>
#include <algorithm>
using namespace std;

int n, c, m;

struct Box {
	int start;
	int dest;
	int boxs;
};

Box bx[10001];
int truck[2001];

bool cmp(const Box &p, const Box &q) {
	if (p.dest < q.dest) {
		return true;
	} else if (p.dest == q.dest) {
		return p.start > q.start;
	}
	return false;
}

int main() {
	cin >> n >> c >> m;
	for (int i = 0; i < m; ++i) {
		cin >> bx[i].start >> bx[i].dest >> bx[i].boxs;
	}
	sort(bx, bx + m, cmp);
	int ans = 0;
	for (int i = 0; i < m; i++) {
		int cur = 0;
		for (int j = bx[i].start; j < bx[i].dest; j++) {
			cur = max(cur, truck[j]);
		}
		int minbox = min(bx[i].boxs, c - cur);
		for (int j = bx[i].start; j < bx[i].dest; j++) {
			truck[j] += minbox;
		}
		ans += minbox;
	}
	cout << ans;
	return 0;
}