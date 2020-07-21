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
//BOJ #11051

int memo[1001][1001];
int cal(int n, int k) {
	if (k == n || k == 0) {
		return 1;
	}
	if (memo[n][k]) {
		return memo[n][k];
	}
	return memo[n][k] = cal(n - 1, k - 1) % 10007 + cal(n - 1, k) % 10007;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	cout << cal(n, k) % 10007;
}
