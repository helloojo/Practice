#include <cstdio>
#include <cstring>

typedef unsigned long long ull;
ull bit[468751];
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

inline void getint(int &x) {
	int tmp = getcha();
	x = 0;
	while (tmp < 47) {
		tmp = getcha();
	}
	while (tmp > 47) {
		x = x * 10 + (tmp - '0');
		tmp = getcha();
	}
}

int main() {
	int t, n, temp, cnt;
	getint(t);
	while (t--) {
		cnt = 0;
		getint(n);
		memset(bit, 0, sizeof(bit));
		for (int i = 0; i < n; i++) {
			getint(temp);
			bit[temp/64] |= (1ull << (temp%64));
		}
		for (int j = 0; j < n; j++) {
			getint(temp);
			if (!(bit[temp/64] & (1ull << (temp%64)))) {
				printf("%d ", temp);
				cnt++;
			}
		}
		if (!cnt) {
			printf("0");
		}
		printf("\n");
	}
	return 0;
}