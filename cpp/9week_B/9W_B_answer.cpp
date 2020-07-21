#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

pair<int, int> p[10001];
int memo[10001][3];	//0: left,1: right, 2:not

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t, n;
	cin >> t;
	while (t--) {
		memset(memo, 0, sizeof(memo));
		cin >> n;
		int ret = 0;
		for (int i = 1; i <= n; i++) {
			cin >> p[i].first >> p[i].second;
		}
		p[n + 1].first = 987654321;
		for (int i = 1; i <= n; i++) {
			//left
			if (p[i - 1].first + p[i - 1].second < p[i].first - p[i].second) {
				memo[i][0] = max({ memo[i][0],memo[i - 1][0],memo[i - 1][1],memo[i - 1][2] }) + p[i].second;
			} else if (p[i].first - p[i].second > p[i - 1].first) {
				memo[i][0] = max({ memo[i][0],memo[i - 1][0],memo[i - 1][2] }) + p[i].second;
			}
			//right
			if (p[i].first > p[i - 1].first + p[i - 1].second && p[i].first + p[i].second < p[i + 1].first) {
				memo[i][1] = max({ memo[i][1],memo[i - 1][0],memo[i - 1][1],memo[i - 1][2] }) + p[i].second;
			} else if (p[i].first + p[i].second < p[i + 1].first) {
				memo[i][1] = max({ memo[i][1],memo[i - 1][0],memo[i - 1][2] }) + p[i].second;
			}
			//not
			if (p[i - 1].first + p[i - 1].second < p[i].first) {
				memo[i][2] = max({ memo[i][2],memo[i - 1][0],memo[i - 1][1],memo[i - 1][2] });
			} else {
				memo[i][2] = max({ memo[i][2],memo[i - 1][0],memo[i - 1][2] });
			}
			ret = max({ ret,memo[i][0],memo[i][1],memo[i][2] });
		}
		cout << ret << '\n';
	}
}