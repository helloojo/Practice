#include <iostream>
#include <string>
using namespace std;
//BOJ #2248
typedef unsigned long long int;
int memo[32][32];
int comb(int n, int k) {
	if (n == k || k == 0 || n == 0 || n == 1) {
		return 1;
	}
	if (memo[n][k]) {
		return memo[n][k];
	}
	memo[n][k] = comb(n - 1, k - 1) + comb(n - 1, k);
	return memo[n][k];
}

int sum(int n, int k) {
	int ret = 0;
	for (int i = k; i >= 1; i--) {
		ret += comb(n, i);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(Nint);
	int n, l;
	int inddx;
	cin >> n >> l >> inddx;
	int order = 1;
	int size = n;
	int cnt = l;
	string s = "";
	while (size != 0) {
		size--;
		if (order + sum(size, cnt) + 1 <= inddx) {
			s += "1";
			cout << order << ' ' << sum(size, cnt) << ' ' << endl;
			order += sum(size, cnt--) + 1;
		} else if (order==inddx && cnt) {
			s += "1";
			cnt--;
		} else {
			s += "0";
		}
	}
	cout << s;
	return 0;
}