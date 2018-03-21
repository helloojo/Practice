#include <iostream>
#include <algorithm>
using namespace std;
//BOJ #5618
int num[3];

int gcd(int p, int q) {
	if (q == 0) {
		return p;
	}
	return gcd(q, p%q);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int gcdn = 0;
	if (n == 2) {
		cin >> num[0] >> num[1];
		gcdn = gcd(num[0], num[1]);
		for (int i = 1; i <= gcdn; i++) {
			if (gcdn%i == 0) {
				cout << i << '\n';
			}
		}
	} else {
		cin >> num[0] >> num[1] >> num[2];
		gcdn = gcd(num[0], gcd(num[1], num[2]));
		for (int i = 1; i <= gcdn; i++) {
			if (gcdn%i == 0) {
				cout << i << '\n';
			}
		}
	}

	return 0;
}