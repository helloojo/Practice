#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a[501];
int b[501];
char acnt[2500001];
char bcnt[2500001];
int t, s, n, m;
int sum = 0;
const int MAXX = 1 << 20;
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
	int tmp = getcha();
	x = 0;
	while (tmp < '0') {
		tmp = getcha();
	}
	while (tmp >= '0') {
		x = x * 10 + (tmp - '0');
		tmp = getcha();
	}
}

int main() {
	getint(t);
	while (t--) {
		getint(s);
		getint(n);
		getint(m);
		memset(acnt, 0, sizeof(acnt));
		memset(bcnt, 0, sizeof(bcnt));
		for (int i = 0; i < n; i++) {
			getint(a[i]);
		}
		for (int i = 0; i < m; i++) {
			getint(b[i]);
		}
		for (int i = 0; i < n; i++) {
			sum = 0;
			for (int j = 0; j < n - 1; j++) {
				sum += (a[(i + j) % n]);
				acnt[sum]++;
			}
		}
		sum = 0;
		for (int i = 0; i < n; i++) {
			sum += a[i];
		}
		acnt[sum]++;
		for (int i = 0; i < m; i++) {
			sum = 0;
			for (int j = 0; j < m - 1; j++) {
				sum += (b[(i + j) % m]);
				bcnt[sum]++;
			}
		}
		sum = 0;
		for (int i = 0; i < m; i++) {
			sum += b[i];
		}
		bcnt[sum]++;
		long long ret = 0;
		for (int i = 0; i < s; i++) {
			ret += acnt[i] * bcnt[s - i];
		}
		ret += (acnt[s] + bcnt[s]);
		cout << ret << '\n';
	}

	return 0;
}