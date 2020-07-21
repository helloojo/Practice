#include <iostream>
#include <algorithm>
using namespace std;
//BOJ #4190
int coin[101];
int memo[20001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	int p;
	int n;
	while (t--) {
		cin >> p >> n;
		for (int i = 1; i <= n; i++) {
			cin >> coin[i];
		}
		memo[0] = 0;
		for (int i = 1; i <= 20000; i++) {
			memo[i] = 987654321;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = coin[i]; j <= 20000; j++) {
				memo[j] = min(memo[j], memo[j - coin[i]] + 1);
			}
		}
		for (int i = p; i <= 20000; i++) {
			if (memo[i] != 987654321) {
				cout << i << ' ' << memo[i] << '\n';
				break;
			}
		}
	}
	return 0;
}