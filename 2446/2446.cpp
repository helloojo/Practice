#include <iostream>
using namespace std;
//BOJ #2446
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<i; j++) {
			cout << " ";
		}
		for (int j = n * 2 - 1; j>i * 2; j--) {
			cout << "*";
		}
		cout << '\n';
	}
	for (int i = n - 2; i >= 0; i--) {
		for (int j = 0; j<i; j++) {
			cout << " ";
		}
		for (int j = n * 2 - 1; j>2 * i; j--) {
			cout << "*";
		}
		cout << '\n';
	}
	return 0;
}