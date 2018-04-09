#include <iostream>
#include <map>
#include <algorithm>
#include <climits>
using namespace std;
//BOJ #11652

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	map<ll, int> m;
	int n;
	cin >> n;
	ll a;
	int max = -1;
	ll maxnum = LLONG_MAX;
	while (n--) {
		cin >> a;
		m[a]++;
	}
	for (auto i = m.begin(); i != m.end(); i++) {
		if (i->second > max) {
			max = i->second;
			maxnum = i->first;
		}
	}
	cout << maxnum;
	return 0;
}