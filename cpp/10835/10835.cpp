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
//BOJ #10835

int memo[2001][2001];
int A[2001];
int B[2001];
int n;

int solve(int i, int j) {
	if (i >= n || j >= n) {
		return 0;
	}
	if (memo[i][j] != -1) {
		return memo[i][j];
	}
	int ret = 0;
	ret = max({ ret, solve(i + 1, j),solve(i + 1,j + 1) });
	if (A[i] > B[j]) {
		ret = max(ret,solve(i,j + 1) + B[j]);
	}
	memo[i][j] = ret;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> B[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			memo[i][j] = -1;
		}
	}
	cout << solve(0, 0);
}
