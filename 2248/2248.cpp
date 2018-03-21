#include <iostream>
#include <string>
using namespace std;
//BOJ #2248
typedef unsigned long long ull;
ull memo[32][32];
ull comb(int n, int k) {
	if (n == k || k == 0 || n == 0 || n == 1) {
		return 1;
	}
	if (memo[n][k]) {
		return memo[n][k];
	}
	memo[n][k] = comb(n - 1, k - 1) + comb(n - 1, k);
	return memo[n][k];
}

ull sum(int n, int k) {
	ull ret = 0;
	for (int i = k; i >= 1; i--) {
		ret += comb(n, i);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, l;
	ull index;
	cin >> n >> l >> index;
	ull order = 1;
	int size = n;
	int cnt = l;
	string s = "";
	while (size != 0) {
		size--;
		if (order + sum(size, cnt) + 1 <= index) {
			s += "1";
			cout << order << ' ' << sum(size, cnt) << ' ' << endl;
			order += sum(size, cnt--) + 1;
		} else if (order==index && cnt) {
			s += "1";
			cnt--;
		} else {
			s += "0";
		}
	}
	cout << s;
	return 0;
}