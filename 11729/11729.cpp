#include <iostream>
#include <cmath>
using namespace std;
//BOJ #11729

void hanoi(int n, int src, int dst) {
	if (n > 1) {
		hanoi(n - 1, src, 6 - src - dst);
	}
	cout << src << ' ' << dst << '\n';
	if (n > 1) {
		hanoi(n - 1, 6 - src - dst, dst);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	cout << (int)pow(2, n) - 1 << '\n';
	hanoi(n, 1, 3);
}