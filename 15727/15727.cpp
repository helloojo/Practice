#include <stdio.h>
//BOJ #15727

int main() {
	int n;
	scanf("%d", &n);
	printf("%d", n / 5 + (n%5?1:0));
	return 0;
}