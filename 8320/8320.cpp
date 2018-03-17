#include <iostream>
using namespace std;
//BOJ #8320
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int ret = 0;
	ret += n;
	for (int i = 2; i <= n / 2; i++) {
		if (n / i >= i) {
			ret += n / i - i + 1;
		}
	}
	cout << ret;
	return 0;
}