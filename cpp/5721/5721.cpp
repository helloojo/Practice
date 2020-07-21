#include <cstdio>
#include <cstring>
//BOJ #5721
typedef long long ll;
typedef unsigned long long ull;
int memo[100001][2];	//memo[i][0] -> 이걸 안주웠을때 최대값 = max(memo[i-1][1],memo[i-2][0]
int memo2[100001][2];	//memo[i][0] -> 이걸 안주웠을때 최대값 = max(memo[i-1][1],memo[i-2][0]
static int max(int a, int b) {
	return (a > b ? a : b);
}
const int size = (1 << 20);
int p = size;
char buf[size];
inline static char getChar() {
	if (p == size) {
		fread(buf, 1, size, stdin);
		p = 0;
	}
	return buf[p++];
}
inline static void getint(int& x) {
	x = 0;
	int temp = getChar();
	while (temp<'0' || temp>'9') {
		temp = getChar();
	}
	while (temp >= '0' && temp <= '9') {
		x = x * 10 + (temp - '0');
		temp = getChar();
	}
}

int main() {
	register int i, j;
	int m, n;
	getint(m);
	getint(n);
	while (!(m == 0 && n == 0)) {
		int ret = 0;
		for (i = 1; i <= m; i++) {
			int num;
			int cnt = 0;
			for (j = 1; j <= n; j++) {
				getint(num);
				if (j < 3) {
					memo[j][1] = num;
					memo[j][0] = memo[j - 1][1];
				} else {
					memo[j][0] = max(memo[j - 1][0], max(memo[j - 1][1], memo[j - 2][1]));
					memo[j][1] = max(memo[j - 2][1], max(memo[j - 1][0], memo[j - 2][0])) + num;
				}
				cnt = max(cnt, max(memo[j][0], memo[j][1]));
			}
			if (i > 2) {
				memo2[i][0] = max(memo2[i - 1][0], max(memo2[i - 1][1], memo2[i - 2][1]));
				memo2[i][1] = max(memo2[i - 1][0], max(memo2[i - 2][0], memo2[i - 2][1])) + cnt;
			} else {
				memo2[i][0] = memo2[i - 1][1];
				memo2[i][1] = cnt;
			}
			ret = max(memo2[i][0], memo2[i][1]);
		}
		printf("%d\n", ret);
		getint(m);
		getint(n);
	}
}
