#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <iomanip>
using namespace std;
//BOJ #15954
typedef long long ll;
typedef unsigned long long ull;

double arr[501];
double tree[2001];
double make(int left, int right, int here) {
	if (left == right) {
		return tree[here] = arr[left];
	}
	int mid = (left + right) / 2;
	double l = make(left, mid, here * 2);
	double r = make(mid + 1, right, here * 2 + 1);
	return tree[here] = l + r;
}
double find(int src, int dst, int left, int right, int here) {
	if (src > right || dst < left) {
		return 0;
	}
	if (src <= left && right <= dst) {
		return tree[here];
	}
	int mid = (left + right) / 2;
	double l = find(src, dst, left, mid, here * 2);
	double r = find(src, dst, mid + 1, right, here * 2 + 1);
	return l + r;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	make(0, n - 1, 1);
	double ret = 987654321;
	for (int i = 0; i < n; i++) {
		for (int j = k; i + j <= n; j++) {
			double mean = find(i, i + j-1, 0, n - 1, 1) / j;
			double var = 0.0;
			for (int p = i; p < i + j; p++) {
				var += pow(arr[p] - mean, 2);
			}
			var /= j;
			ret = min(ret, sqrt(var));
		}
	}
	cout << setprecision(11);
	cout << ret;
}
