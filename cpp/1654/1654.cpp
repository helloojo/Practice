#include <iostream>
#include <algorithm>
using namespace std;
//BOJ #1654
typedef long long ull;
ull lan[10001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int k, n;
	cin >> k >> n;
	ull high = 0;
	ull low = 0;
	for (int i = 0; i < k; i++) {
		cin >> lan[i];
		high = max(high, lan[i]);
	}
	high++;
	ull mid = (low + high) / 2;
	ull ret = 0;
	while (low + 1 < high) {
		ull sum = 0;
		for (int i = 0; i < k; i++) {
			sum += (lan[i] / mid);
		}
		if (sum < n) {
			high = mid;
		} else {
			low = mid;
		}
		if (sum >= n) {
			ret = max(ret, mid);
		}
		mid = (low + high) / 2;
	}
	cout << ret;
}