#include <iostream>
using namespace std;
//BOJ #3896

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	int k;
	bool isprime[1299710];
	for (int i = 2; i < 1299710; i++) {
		isprime[i] = true;
	}
	for (int i = 2; i*i < 1299710; i++) {
		for (int j = i * i; j < 1299710; j += i) {
			isprime[j] = false;
		}
	}
	while (t--) {
		cin >> k;
		if (isprime[k]) {
			cout << 0 << '\n';
		} else {
			int ret = 1;
			for (int i = k-1, j = k+1; !isprime[i] || !isprime[j];) {
				if (!isprime[i]) {
					i--;
					ret++;
				}
				if (!isprime[j]) {
					j++;
					ret++;
				}
			}
			cout << ret+1 << '\n';
		}
		
	}
	return 0;
}