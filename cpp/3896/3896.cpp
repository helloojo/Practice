#include <iostream>
using namespace std;
//BOJ #3896

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	bool isprime[1299710];
	for (int i = 0; i < 1299710; i++) {
		isprime[i] = true;
	}
	for (int i = 2; i*i < 1299710; i++) {
		for (int j = i * i; j < 1299710; j += i) {
			isprime[j] = false;
		}
	}
	while (t--) {
		int n;
		cin >> n;
		if (isprime[n]) {
			cout << 0 << '\n';
		} else {
			int start = n;
			while (!isprime[start--]);
			int cnt = 0;
			for (int i = start+1; !isprime[i]; i++) {
				cnt++;
			}
			cout << cnt << '\n';
		}
	}
	return 0;
}