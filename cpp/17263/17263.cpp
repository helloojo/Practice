#include <cstdio>
//BOJ #17263
const int SIZE = (1 << 15);
char buf[SIZE];
int p = SIZE;
inline char getcha() {
	if (p == SIZE) {
		fread(buf, 1, SIZE, stdin);
		p = 0;
	}
	return buf[p++];
}
inline void readint(int* x) {
	(*x) = 0;
	int temp = getcha();
	while (temp<'0' || temp>'9') {
		temp = getcha();
	}
	while (temp >= '0' && temp <= '9') {
		(*x) = (*x) * 10 + (temp - '0');
		temp = getcha();
	}
}
int main() {
	int n;
	readint(&n);
	int m = 0;
	int num;
	for (register int i = 0; i < n; i++) {
		readint(&num);
		m = (m < num) ? num : m;
	}
	printf("%d", m);
}
