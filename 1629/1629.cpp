#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;
//BOJ #1629
typedef long long ll;
typedef unsigned long long ull;
ll multi(ll a, ll b, ll c) {
	if (b == 0) {
		return 1;
	}
	if (b == 1) {
		return a;
	}
	if (b & 1) {
		return ((a%c)*(multi(a, b - 1, c) % c)) % c;
	}
	return (multi(a, b / 2, c) % c*multi(a, b / 2, c) % c) % c;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll a, b, c;
	cin >> a >> b >> c;
	cout << multi(a, b, c)%c;
}
