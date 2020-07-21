#include <iostream>
using namespace std;
//BOJ #14490

int GCD(int p, int q) {
	if(q==0) {
		return p;
	} else {
		return GCD(q, p%q);
	}
}

int main() {
	int n, m;
	scanf("%d:%d", &n, &m);
	int gcd = GCD(n, m);
	printf("%d:%d", n/gcd, m/gcd);
	return 0;
}