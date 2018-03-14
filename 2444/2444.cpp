#include <iostream>
using namespace std;
//BOJ #2444
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < 2 * n - 1; i++) {
		if (i < n) {
			for (int j = 1; j < n - i; j++) {
				cout << " ";
			}
			for (int j = 0; j < 2 * i + 1; j++) {
				cout << "*";
			}
		} else {
			for (int j = (i + 1) % n; j>0; j--) {
				cout << " ";
			}
			for (int j = 0; j < 2 * (2 * n - i - 1) - 1; j++) {
				cout << "*";
			}
		}
		cout << '\n';
	}
	return 0;
}