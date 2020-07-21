#include <iostream>
#include <cmath>
using namespace std;

const int MAXX = 1 << 15;
char buf[MAXX];
int p = MAXX;
inline char getcha() {
	if (p == MAXX) {
		fread(buf, 1, MAXX, stdin);
		p = 0;
	}
	return buf[p++];
}
inline void getint(int& x) {
	x = 0;
	int temp = getcha();
	while (temp < '0') {
		temp = getcha();
	}
	while (temp >= '0' && temp <= '9') {
		x = 10 * x + (temp - '0');
		temp = getcha();
	}
}

int main() {
	int t, k, c;
	int a, b;
	getint(t);
	while (t--) {
		getint(k);
		getint(c);
		while (c--) {
			getint(a);
			getint(b);
			if (a > b) {
				cout << (b + (k - a) >= a - 2) << '\n';
			} else if (a < b) {
				cout << (a + (k - b) > b - 2) << '\n';
			} else {
				cout << (a <= k) << '\n';
			}
		}
	}
}