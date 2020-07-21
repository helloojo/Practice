#include <stdio.h>
//BOJ #5533

int existed[101][3];
int arr[201][4];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &arr[i][j]);
			existed[arr[i][j]][j]++;
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < n; j++) {
			if (existed[arr[j][i]][i] == 1) {
				arr[j][3] += arr[j][i];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d\n", arr[i][3]);
	}
	return 0;
}