#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
//BOJ #11066

int file[501];
int p[501];
int memo[501][501];
int solve(int i, int j) {
	if (i == j) {
		return 0;
	}
	if (memo[i][j]) {
		return memo[i][j];
	}
	int ret = 987654321;
	for (int k = i; k < j; k++) {
		ret = min(ret, solve(i, k) + solve(k + 1, j) + p[j] - p[i - 1]);
	}
	return memo[i][j] = ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	int k;
	while (t--) {
		cin >> k;
		memset(memo, 0, sizeof(memo));
		for (int i = 1; i <= k; i++) {
			cin >> file[i];
			p[i] = p[i - 1] + file[i];
		}
		cout << solve(1, k) << '\n';
	}
	return 0;
}