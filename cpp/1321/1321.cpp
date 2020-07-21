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
//BOJ #1321

const int MAX = 1 << 20;
char buf[MAX];
int p = MAX;
int arr[500001];
int tree[2000001];

char getc() {
	if (p == MAX) {
		fread(buf, 1, MAX, stdin);
		p = 0;
	}
	return buf[p++];
}
void getint(int& x) {
	x = 0;
	int t = getc();
	while ((t<'0' || t>'9') && t!='-') {
		t = getc();
	}
	int minus = 1;
	if (t == '-') {
		minus = -1;
		t = getc();
	}
	while (t >= '0' && t <= '9') {
		x = x * 10 + (t - '0');
		t = getc();
	}
	x *= minus;
}

int make(int l, int r, int h) {
	if (l == r) {
		return tree[h] = arr[l];
	}
	int mid = (l + r) / 2;
	int left = make(l, mid, h * 2);
	int right = make(mid + 1, r, h * 2 + 1);
	return tree[h] = left + right;
}

int update(int ch, int val, int left, int right, int here) {
	if (ch<left || right<ch) {
		return tree[here];
	}
	if (left == right) {
		return tree[here] += val;
	}
	int mid = (left + right) / 2;
	int l = update(ch, val, left, mid, here * 2);
	int r = update(ch, val, mid + 1, right, here * 2 + 1);
	return tree[here] = l + r;
}
int find(int val, int left, int right, int here) {
	if (left == right) {
		return left;
	}
	int mid = (left + right) / 2;
	if (tree[here * 2] < val) {
		return find(val - tree[here * 2], mid + 1, right, here * 2 + 1);
	}
	return find(val, left, mid, here * 2);
}

int main() {
	int n;
	getint(n);
	for (int i = 1; i <= n; i++) {
		getint(arr[i]);
	}
	make(1, n, 1);
	int m;
	getint(m);
	int a, b, c;
	for (int i = 0; i < m; i++) {
		getint(a);
		switch (a) {
		case 1:
			getint(b);
			getint(c);
			update(b, c, 1, n, 1);
			break;
		case 2:
			getint(b);
			cout << find(b, 1, n, 1) << '\n';
			break;
		}
	}
}
