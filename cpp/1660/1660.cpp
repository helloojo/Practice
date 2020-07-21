#include <iostream>
#include <algorithm>
using namespace std;
//BOJ #1660
int all[150];
int memo[300001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int next = 3;
	int up = 2;
	int cur = 1;
	int prev = 1;
	for (int i = 1; i <= n; i++) {
		memo[i] = 987654321;
	}
	all[1] = 1;
	for (int i = 2; i < 150; i++) {
		all[i] = all[i - 1] + next;
		next = ++up + next;
	}
	for (int i = 1; i < 150; i++) {
		for (int j = all[i]; j <= n; j++) {
			if (all[i] > n) {
				break;
			}
			memo[j] = min(memo[j], memo[j - all[i]] + 1);
		}
		if (all[i] > n) {
			break;
		}
	}
	cout << memo[n];
	return 0;
}