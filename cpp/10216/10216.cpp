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
//BOJ #10216
typedef long long ll;
typedef unsigned long long ull;

struct pos {
	int x;
	int y;
	int r;
	int p;
} arr[3001];

int find(int p) {
	if(arr[p].p == p) {
		return p;
	}
	return arr[p].p = find(arr[p].p);
}
void merge(int u, int v) {
	u = find(u);
	v = find(v);
	if(u == v) {
		return;
	}
	if(u > v) {
		swap(u, v);
	}
	arr[v].p = u;
}

int cal(pos& a, pos& b) {
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		for(int i = 1; i <= n; i++) {
			cin >> arr[i].x >> arr[i].y >> arr[i].r;
			arr[i].p = i;
			for(int j = 1; j < i; j++) {
				if((arr[i].r + arr[j].r)*(arr[i].r + arr[j].r) >= cal(arr[i], arr[j])) {
					merge(i, j);
				}
			}
		}
		int ret = 0;
		for(int i = 1; i <= n; i++) {
			if(i == find(i)) {
				ret++;
			}
		}
		cout << ret << '\n';
	}
}
