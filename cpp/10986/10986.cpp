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
//BOJ #10986
int n, m;
int arr[1000000];
int tree[4000000];
int make(int l, int r, int h) {
	if (l == r) {
		return tree[h] = arr[l] % m;
	}
	int mid = (l + r) / 2;
	
	return tree[h] = (make(l, mid, h * 2) % m + make(mid + 1, r, h * 2 + 1) % m) % m;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(tree, -1, sizeof(tree));
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	make(0, n - 1, 1);
	int ret = 0;
	for (int i = 1; i < n * 4; i++) {
		if (tree[i] != -1) {
			if (tree[i] == 0) {
				ret++;
			}
		}
	}
	cout << ret;
}
