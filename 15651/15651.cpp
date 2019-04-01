#include <stdio.h>
//BOJ #15651

int arr[9];
int n, m;
void print() {
	for (int i = 1; i <= m; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void pick(int level) {
	if (level > m) {
		print();
		return;
	}
	for (int i = 1; i <= n; i++) {
		arr[level] = i;
		pick(level + 1);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	pick(1);
	return 0;
}