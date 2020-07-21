#include <stdio.h>
#define MAXX (1<<20)
//BOJ #
typedef unsigned long long ull;
ull bit[468751];
char buf[MAXX];
int p=MAXX;
inline char getcha() {
	if (p == MAXX) {
		fread(buf, 1, MAXX, stdin);
		p = 0;
	}
	return buf[p++];
}

inline void getint(int* x) {
	int tmp = getcha();
	*x = 0;
	while (tmp < 47) {
		tmp = getcha();
	}
	while (tmp > 47) {
		*x = (*x) * 10 + (tmp - '0');
		tmp = getcha();
	}
}

int main() {
	int t = 0;
	int n = 0;
	int temp = 0;
	int cnt = 0;
	int a = 0;
	int b = 0;
	int i = 0;
	getint(&t);
	while (t--) {
		cnt = 0;
		getint(&n);
		for (i = 0; i < 468751; i++) {
			bit[i] = 0;
		}
		for (i = 0; i < n; i++) {
			getint(&temp);
			a = temp / 64;
			b = temp - 64 * a;
			bit[a] |= (1ull << b);
		}
		for (i = 0; i < n; i++) {
			getint(&temp);
			a = temp / 64;
			b = temp - 64 * a;
			if (!(bit[a] & (1ull << b))) {
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