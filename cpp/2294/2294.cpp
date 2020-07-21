#include <iostream>
#include <algorithm>
using namespace std;
//BOJ #2294

int coin[101];
int memo[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> coin[i];
	}
	for (int i = 1; i <= k; i++) {
		memo[i] = 987654321;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			memo[j] = min(memo[j], memo[j - coin[i]] + 1);
		}
	}
	if (memo[k] == 987654321) {
		cout << -1;
	} else {
		cout << memo[k];
	}
	return 0;
}