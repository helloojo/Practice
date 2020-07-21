#include <iostream>
#include <cstring>
using namespace std;
typedef unsigned int uint;
uint bit[1000000];

int main() {
	int t, n, temp;
	bool can = false;
	scanf("%d", &t);
	while (t--) {
		can = false;
		scanf("%d", &n);
		for (int i = 0; i < 1000000; i++) {
			bit[i] = 0;
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", &temp);
			bit[temp / 32] |= (1 << (temp % 32));
		}
		for (int j = 0; j < n; j++) {
			scanf("%d", &temp);
			if (!(bit[temp / 32] & (1 << (temp % 32)))) {
				printf("%d ", temp);
				can = true;
			}
		}
		if (!can) {
			printf("0");
		}
		printf("\n");
	}
	return 0;
}