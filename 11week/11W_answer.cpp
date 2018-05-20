#include <iostream>
#include <algorithm>
using namespace std;

int map[501][501];
int check[501][501];
int n, k;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	int index = 0;
	int a;
	char b;
	while (t--) {
		cin >> n >> k;
		int maxcnt = 0;
		for (int i = 0; i < n; i++) {
			index = 0;
			int cnt = 1;
			while (index < k) {
				cin >> a >> b;
				for (int j = index; j < index + a; j++) {
					if (b == 'e') {
						map[i][j] = 0;
						cnt = 1;
					} else {
						map[i][j] = cnt++;
					}
					maxcnt = max(maxcnt, cnt);
				}
				index += a;
			}
		}
		int ret = 0;
		for (int kk = 1; kk < maxcnt; kk++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < k; j++) {
					if (map[i][j] >= kk) {
						check[i][j] = 1;
					} else {
						check[i][j] = 0;
					}
				}
			}			
			int maxl = 0;
			int lcnt = 0;
			for (int i = 0; i < k; i++) {
				lcnt = 0;
				for (int j = 0; j < n; j++) {
					if (check[j][i]) {
						lcnt++;
					} else {
						lcnt = 0;
					}
					maxl = max(maxl, lcnt);
				}
			}
			ret = max(ret, maxl*kk);
		}
		cout << ret << '\n';
	}
}