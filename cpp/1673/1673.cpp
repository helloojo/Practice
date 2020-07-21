#include <iostream>
using namespace std;
//BOJ #1673
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	int ret = 0;
	while (cin >> n >> k) {
		ret = 0;
		ret += n;
		while (n >= k) {
			ret += n / k;
			n = n / k + n % k;
		}
		cout << ret << '\n';
	}
	return 0;
}