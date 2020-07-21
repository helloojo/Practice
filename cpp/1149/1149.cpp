#include <iostream>
#include <algorithm>
using namespace std;
//BOJ #1149
int price[1001][3];
int memo[1001][3];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> price[i][j];
			memo[i][j] = 987654321;
		}
	}
	memo[0][0] = price[0][0];
	memo[0][1] = price[0][1];
	memo[0][2] = price[0][2];
	for (int i = 1; i <= n; i++) {
		memo[i][0] = min(memo[i-1][1],memo[i-1][2])+price[i][0];
		memo[i][1] = min(memo[i - 1][0], memo[i - 1][2]) + price[i][1];
		memo[i][2] = min(memo[i - 1][0], memo[i - 1][1]) + price[i][2];
	}
	cout << min({ memo[n][0],memo[n][1],memo[n][2] });
	return 0;
}