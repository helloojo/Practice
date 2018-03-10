#include <iostream>
#include <map>
#include <cmath>
using namespace std;
//BOJ #1351

typedef long long ll;

map<ll, ll> m;
ll n, p, q;

ll dp(ll i) {
	if (m[i]) {
		return m[i];
	}
	m[i] = dp((ll)floor((double)i / p)) + dp((ll)floor((double)i / q));
	return m[i];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> p >> q;
	m[0] = 1; 
	cout << dp(n);
	return 0;
}