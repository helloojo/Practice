#include <iostream>
#include <algorithm>
using namespace std;
//BOJ #1965

int box[1001];
int memo[1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> box[i];
	}
	int ret = 0;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < i; j++) {
			if (box[i] > box[j]) {
				cnt = max(memo[j], cnt);
			}
		}
		memo[i] = cnt + 1;
		ret = max(memo[i], ret);
	}
	cout << ret;
	return 0;
}