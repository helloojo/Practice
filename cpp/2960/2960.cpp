#include <iostream>
using namespace std;
//BOJ #2960

bool isprime[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(Nint);
	int n, k;
	cin >> n >> k;
	for (int i = 2; i <= n; i++) {
		isprime[i] = true;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = i; j <= n; j+=i) {
			if (isprime[j]) {
				isprime[j] = false;
				k--;
				if (k==0) {
					cout << j;
					return 0;
				}
			}
		}
	}
	return 0;
}