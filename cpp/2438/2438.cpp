#include <iostream>
using namespace std;
//BOJ #2438
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = n; j > i + 1; j--) {
			cout << ' ';
		}
		for (int j = 0; j <= i; j++) {
			cout << '*';
		}
		cout << '\n';
	}
	return 0;
}