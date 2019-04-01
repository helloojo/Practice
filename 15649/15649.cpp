#include <stdio.h>
//BOJ #15649

int arr[9];
bool visited[9];
int n, m;
void print() {
	for (int i = 1; i <= m; i++) {
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void pick(int level) {
	if (level > m) {
		print();
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (visited[i]) {
			continue;
		}
		arr[level] = i;
		visited[i] = true;
		pick(level + 1);
		visited[i] = false;
	}
}

int main() {
	scanf("%d %d", &n, &m);
	pick(1);
	return 0;
}