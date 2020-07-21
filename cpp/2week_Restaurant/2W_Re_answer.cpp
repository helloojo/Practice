#include <iostream>
#include <algorithm>
using namespace std;

int price[101][101];
int memo[101][101];

const int MAXX = 1 << 20;
char buf[MAXX];
int p = MAXX;
inline char getcha() {
	if (p == MAXX) {
		fread(buf, 1, MAXX, stdin);
		p = 0;
	}
	return buf[p++];
}

inline void getint(int &x) {
	int tmp = getcha();
	x = 0;
	while (tmp < 47) {
		tmp = getcha();
	}
	while (tmp > 47) {
		x = x * 10 + (tmp - '0');
		tmp = getcha();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	int t;
	getint(t);
	int n, m;
	while (t--) {
		getint(n);
		getint(m);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				getint(price[i][j]);
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