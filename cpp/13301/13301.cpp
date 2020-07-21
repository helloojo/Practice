#include <iostream>
using namespace std;
//BOJ #13301

typedef unsigned long long ull;

ull memo[81];

ull fibo(int n) {
	if (n <= 2) {
		return 1;
	}
	if (memo[n]) {
		return memo[n];
	}
	return memo[n] = fibo(n - 1) + fibo(n - 2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	cout << 2 * fibo(n + 1) + 2 * fibo(n);
}