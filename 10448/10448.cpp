#include <iostream>
using namespace std;
//BOJ #10448

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	int arr[101];
	for (int i = 1; i <= 100; i++) {
		arr[i] = (i*(i + 1)) / 2;
	}
	while (t--) {
		int n;
		cin >> n;
		bool find = false;
		for (int i = 1; i <= 100; i++) {
			for (int j = 1; j <= 100; j++) {
				for (int k = 1; k <= 100; k++) {
					if (arr[i] + arr[j] + arr[k] == n) {
						cout << 1 << '\n';
						find = true;
						break;
					}
				}
				if (find) {
					break;
				}
			}
			if (find) {
				break;
			}
		}
		if (!find) {
			cout << 0 << '\n';
		}
	}
}