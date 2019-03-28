#include <iostream>
#include <algorithm>
using namespace std;
//BOJ #1915
typedef long long ll;
typedef unsigned long long ull;

char map[1001][1001];
int memo[1001][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}
	int ret = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j]=='1') {
				memo[i][j] = min({ memo[i - 1][j - 1],memo[i - 1][j],memo[i][j - 1] }) + 1;
				ret = max(memo[i][j], ret);
			}
		}
	}
	cout << ret * ret;
}
