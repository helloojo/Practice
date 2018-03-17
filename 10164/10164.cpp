#include <iostream>
using namespace std;
//BOJ #10164
int memo[16][16];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	int cur = 1;
	pair<int, int> must;
	must.first = k / m + 1;
	must.second = k % m;
	if (must.second == 0) {
		must.first--;
		must.second = m;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == 1 && j == 1) {
				memo[i][j] = 1;
			} else {
				memo[i][j] = memo[i - 1][j] + memo[i][j - 1];
			}
		}
	}
	if (k == 0) {
		cout << memo[n][m];
	} else {
		cout << memo[must.first][must.second] * memo[n - must.first + 1][m - must.second + 1];
	}

	return 0;
}