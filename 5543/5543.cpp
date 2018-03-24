#include <iostream>
using namespace std;
//BOJ #5543
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int mina = 987654321;
	int minb = 987654321;
	int n;
	for (int i = 0; i < 3; i++) {
		cin >> n;
		if (n < mina) {
			mina = n;
		}
	}
	for (int i = 0; i < 2; i++) {
		cin >> n;
		if (n < minb) {
			minb = n;
		}
	}
	cout << mina + minb - 50;
	return 0;
}