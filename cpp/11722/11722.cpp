#include <iostream>
#include <algorithm>
using namespace std;
//BOJ #11722
int num[1001];
int memo[1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int ret = 0;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		int maxn = 0;
		for (int j = 0; j < i; j++) {
			if (num[i] < num[j]) {
				maxn = max(maxn, memo[j]);
			}
		}
		memo[i] = maxn + 1;
		ret = max(ret, memo[i]);
	}
	cout << ret;
	return 0;
}