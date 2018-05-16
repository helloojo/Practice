#include <iostream>
using namespace std;
//BOJ #11921
const int MAXX = 1<<20;
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
	x = getcha()-'0';
	int temp;
	while ((temp=getcha())!='\n') {
		x = x * 10 + (temp - '0');
	}
}
typedef unsigned long long ull;
int main() {
	int n;
	getint(n);
	ull sum = 0ull;
	int x;
	printf("%d\n", n);
	while (n--) {
		getint(x);
		sum += (ull)x;
	}
	printf("%llu",sum);
	return 0;
}