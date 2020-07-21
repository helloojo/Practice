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
//BOJ #2609

int gcd(int p, int q) {
	if (q == 0) {
		return p;
	}
	return gcd(q, p%q);
}
int lcm(int p, int q) {
	return p / gcd(p, q)*q;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a, b;
	cin >> a >> b;
	cout << gcd(a, b) << '\n';
	cout << lcm(a, b);
}
