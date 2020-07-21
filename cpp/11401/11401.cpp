#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
//BOJ #11401
typedef long long ull;
const ull MOD = 1000000007;

ull square(ull val, int exp) {
	if (exp == 0) {
		return 1;
	}
	if (exp == 1) {
		return val % MOD;
	}
	if (exp == 2) {
		return ((val % MOD) * (val%MOD)) % MOD;
	}
	if (exp & 1) {
		return ((val%MOD)*(square(val, exp - 1) % MOD)) % MOD;
	} else {
		return ((square(val, exp / 2) % MOD) *(square(val, exp / 2) % MOD)) % MOD;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	ull nfact = 1;
	for (int i = 1; i <= n; i++) {
		nfact *= i;
		nfact %= MOD;
	}
	ull kfact = 1;
	for (int i = 1; i <= k; i++) {
		kfact *= i;
		kfact %= MOD;
	}
	for (int i = 1; i <= n - k; i++) {
		kfact *= i;
		kfact %= MOD;
	}
	cout << ((nfact%MOD)*(square(kfact, MOD - 2) % MOD)) % MOD;
}
