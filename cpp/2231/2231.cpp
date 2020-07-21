#include <iostream>
using namespace std;
//BOJ #2231

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int temp = i;
		int sum = i;
		while (temp) {
			sum += temp % 10;
			temp /= 10;
		}
		if (sum == n) {
			cout << i;
			return 0;
		}
	}
	cout << 0;
}