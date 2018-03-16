#include <iostream>
#include <algorithm>
using namespace std;

int price[101][101];
int memo[101][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	int n, m;
	while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> price[i][j];
				memo[i][j] = 987654321;
			}
		}
		//price[restaurant n][dayprice m]
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				for (int k = 1; k <= n; k++) {
					if (j == k) continue;
					memo[j][i] = min(memo[j][i], memo[k][i - 1] + price[j][i]);
				}
			}
		}
		int ret = 987654321;
		for (int i = 1; i <= n; i++) {
			ret = min(ret, memo[i][m]);
		}
		cout << ret << '\n';
	}
	return 0;
}